#include "change_encoding.h"

uint16_t cp1251_to_unicode(int* symbol) {
    if (*symbol >= CP1251_CYR_LETTER_START &&
        *symbol <= CP1251_CYR_LETTER_END) {
        return CP1251_CODE_POINT_A + (*symbol - CP1251_CYR_LETTER_START);
    } else if (*symbol < CP1251_SPEC_TABLE_START) {
        return *symbol;
    } else {
        return NON_UNICODE_CHAR;
    }
}
