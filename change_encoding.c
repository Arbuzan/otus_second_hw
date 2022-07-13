#include "change_encoding.h"

uint16_t convert_to_unicode(int* symbol, uint16_t code_point) {
    if (*symbol < SPEC_TABLE_START) {
        return *symbol;
    }

    switch (code_point) {
        case CP1251_SYM_CODE:
            if (*symbol >= CP1251_KOI8_CYR_LS &&
                *symbol <= CP1251_KOI8_CYR_LE) {
                return code_point + (*symbol - CP1251_KOI8_CYR_LS);
            }
            break;
        case KOI8_SYM_CODE:
            return *symbol & 0x7F;
        case ISO8859_5_SYM_CODE:
            if (*symbol == 0xAD || *symbol == 0xA0) {
                return *symbol;
            } else if (*symbol == 0xF0) {
                return 0x2116;
            } else if (*symbol >= ISO859_5_CYR_LS &&
                       *symbol <= ISO859_5_CYR_LE) {
                return code_point + (*symbol - ISO859_5_CYR_LS);
            }
            break;
    }


    return NON_UNICODE_SYMBOL;
}
