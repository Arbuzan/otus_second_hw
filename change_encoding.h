#ifndef CHANGE_ENCODING_H_
#define CHANGE_ENCODING_H_

#include <stdint.h>

#define NON_UNICODE_CHAR 0xFFFF

#define CP1251_SPEC_TABLE_START 0x80
#define CP1251_CYR_LETTER_START 0xC0
#define CP1251_CYR_LETTER_END   0xFF
#define CP1251_CODE_POINT_A     0x410

uint16_t cp1251_to_unicode(int* symbol);

#endif /* CHANGE_ENCODING_H_ */
