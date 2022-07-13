#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "change_encoding.h"

static const char* coding_type[]   = {"cp1251", "koi8", "iso8859-5"};
static const int   coding_marker[] = {CP1251_SYM_CODE, KOI8_SYM_CODE,
                                    ISO8859_5_SYM_CODE};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Wrong arguments quantity.\n");
        return EXIT_FAILURE;
    }

    int success      = EXIT_FAILURE;
    int coding_index = 0;
    for (size_t i = 0; i < (sizeof(coding_type) / sizeof(char*)); i++) {
        if (!strcmp(argv[2], coding_type[i])) {
            coding_index = i;
            success      = EXIT_SUCCESS;
            break;
        }
    }
    if (success == EXIT_FAILURE) {
        printf("Wrong coding type in third argument.\n");
        return success;
    }
    // INPUT
    struct stat file_attributes;
    if (stat(argv[1], &file_attributes) == -1) {
        perror("Input file opening error");
        return EXIT_FAILURE;
    }

    if (!S_ISREG(file_attributes.st_mode)) {
        printf("Not a regular input file.\n");
        return EXIT_FAILURE;
    }
    // OUTPUT
    if (stat(argv[3], &file_attributes) == -1) {
        perror("Output file opening error");
        return EXIT_FAILURE;
    }

    if (!S_ISREG(file_attributes.st_mode)) {
        printf("Not a regular output file.\n");
        return EXIT_FAILURE;
    }

    FILE* file_ptr     = fopen(argv[1], "rb");
    FILE* out_file_ptr = fopen(argv[3], "wb");

    int      curr_letter = 0;
    uint16_t out_letter  = 0;
    size_t   wr_size     = 0;
    do {
        curr_letter = fgetc(file_ptr);
        if (curr_letter == EOF) {
            break;
        }
        out_letter =
            convert_to_unicode(&curr_letter, coding_marker[coding_index]);
        if (out_letter == NON_UNICODE_SYMBOL) {
            success = EXIT_FAILURE;
            break;
        }
        wr_size = fwrite(&out_letter, sizeof(uint16_t), 1, out_file_ptr);
    } while (wr_size != 0);


    fclose(file_ptr);
    fclose(out_file_ptr);
    return success;
}
