#ifndef CHANGE_ENCODING_H_
#define CHANGE_ENCODING_H_

#include <stdint.h>

#define NON_UNICODE_SYMBOL 0xFFFF

#define SPEC_TABLE_START   0x80
#define CP1251_KOI8_CYR_LS 0xC0
#define CP1251_KOI8_CYR_LE 0xFF

#define ISO859_5_CYR_LS 0xA1
#define ISO859_5_CYR_LE 0xFF

#define CP1251_SYM_CODE    0x410U
#define KOI8_SYM_CODE      0x44EU
#define ISO8859_5_SYM_CODE 0x401U

uint16_t convert_to_unicode(int* symbol, uint16_t code_point);

#endif /* CHANGE_ENCODING_H_ */
