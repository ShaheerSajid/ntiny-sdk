

/*
 *
 * Droid_Sans_24
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : Droid_Sans_24.h
 * Date                : 06.03.2013
 * Font size in bytes  : 23777
 * Font width          : 10
 * Font height         : 25
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#ifdef __AVR__
#include <avr/pgmspace.h>
#elif defined (ESP8266)
#include <pgmspace.h>
#else
#define PROGMEM
#endif

#ifndef DROID_SANS_24_H
#define DROID_SANS_24_H

#define DROID_SANS_24_WIDTH 10
#define DROID_SANS_24_HEIGHT 25

static const uint8_t Droid_Sans_24[]  = {
    0x5C, 0xE1, // size
    0x0A, // width
    0x19, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x03, 0x07, 0x0E, 0x0A, 0x12, 0x10, 0x02, 0x06, 0x06, 
    0x0A, 0x0B, 0x04, 0x06, 0x03, 0x09, 0x0B, 0x06, 0x0B, 0x0B, 
    0x0D, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x03, 0x04, 0x0B, 0x0B, 
    0x0B, 0x09, 0x12, 0x0E, 0x0B, 0x0C, 0x0C, 0x09, 0x09, 0x0E, 
    0x0C, 0x06, 0x04, 0x0C, 0x09, 0x10, 0x0D, 0x0F, 0x0A, 0x0F, 
    0x0B, 0x0A, 0x0C, 0x0C, 0x0D, 0x14, 0x0C, 0x0C, 0x0A, 0x05, 
    0x09, 0x05, 0x0D, 0x0A, 0x05, 0x0A, 0x0B, 0x09, 0x0B, 0x0B, 
    0x07, 0x0C, 0x0A, 0x02, 0x04, 0x0A, 0x02, 0x12, 0x0A, 0x0C, 
    0x0B, 0x0B, 0x08, 0x09, 0x08, 0x0A, 0x0C, 0x12, 0x0C, 0x0C, 
    0x09, 0x07, 0x02, 0x07, 0x0B, 0x0A, 
    
    // font data
    0xFC, 0xFC, 0xFC, 0x07, 0x3F, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, // 33
    0xFC, 0xFC, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
    0x00, 0x80, 0x80, 0x80, 0xE0, 0xFC, 0x84, 0x80, 0x80, 0x80, 0xFC, 0x9C, 0x80, 0x80, 0x30, 0x31, 0x31, 0xFD, 0x3F, 0x31, 0x31, 0x31, 0xF1, 0xFF, 0x37, 0x31, 0x31, 0x01, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 35
    0xE0, 0xF0, 0x38, 0x18, 0xFE, 0xFE, 0x18, 0x18, 0x18, 0x00, 0x81, 0x03, 0x07, 0x06, 0xFF, 0xFF, 0x0C, 0x9C, 0xF8, 0xF0, 0x01, 0x03, 0x03, 0x03, 0x1F, 0x1F, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 36
    0xF0, 0xF8, 0x0C, 0x0C, 0x0C, 0xF8, 0xF0, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x38, 0x1C, 0x04, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0C, 0x0C, 0x0C, 0x87, 0xE3, 0x78, 0x1C, 0x07, 0x03, 0xF8, 0xFC, 0x06, 0x06, 0x06, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x04, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x06, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 37
    0x00, 0x00, 0xF0, 0xF8, 0x9C, 0x0C, 0x0C, 0x0C, 0x9C, 0xF8, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF8, 0x18, 0x0D, 0x07, 0x07, 0x0F, 0x1F, 0x39, 0x70, 0xE0, 0xC0, 0xF0, 0x78, 0x18, 0x00, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x03, 0x07, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 38
    0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 39
    0x00, 0xE0, 0xF0, 0x3C, 0x0C, 0x04, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x01, 0x0F, 0x1F, 0x78, 0x60, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 40
    0x04, 0x0C, 0x3C, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0x40, 0x60, 0x78, 0x1F, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 41
    0x60, 0x60, 0x60, 0x60, 0xFE, 0xFE, 0x60, 0x60, 0x60, 0x60, 0x00, 0x04, 0x0E, 0x0F, 0x01, 0x01, 0x07, 0x0E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
    0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0xFF, 0xFF, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 43
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, // 44
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 45
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, // 46
    0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0x3C, 0x04, 0x00, 0x80, 0xF0, 0x7C, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x06, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 47
    0xC0, 0xF0, 0x78, 0x1C, 0x0C, 0x0C, 0x0C, 0x1C, 0x78, 0xF0, 0xC0, 0x7F, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x7F, 0x00, 0x01, 0x03, 0x07, 0x06, 0x06, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 48
    0x20, 0x70, 0x38, 0x18, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 49
    0x10, 0x18, 0x1C, 0x0C, 0x0C, 0x0C, 0x0C, 0x18, 0xF8, 0xF0, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x70, 0x38, 0x1C, 0x0F, 0x07, 0x01, 0x00, 0x06, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 50
    0x08, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x9C, 0xF8, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x07, 0x05, 0x8D, 0xF8, 0xF0, 0x03, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 51
    0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0x70, 0x1C, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x60, 0x78, 0x7C, 0x67, 0x63, 0x60, 0x60, 0x60, 0xFF, 0xFF, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 52
    0xF8, 0xFC, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x8E, 0xFC, 0xF8, 0x03, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 53
    0x80, 0xE0, 0xF0, 0x18, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x7F, 0xFF, 0x8C, 0x02, 0x03, 0x03, 0x03, 0x03, 0x86, 0xFE, 0xF8, 0x00, 0x01, 0x03, 0x07, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 54
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x8C, 0xFC, 0x7C, 0x1C, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x3E, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 55
    0x00, 0xF0, 0xF8, 0x1C, 0x0C, 0x0C, 0x0C, 0x9C, 0xF8, 0xF0, 0x00, 0xE0, 0xF8, 0x19, 0x0F, 0x07, 0x06, 0x07, 0x0F, 0x19, 0xF8, 0xE0, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 56
    0xE0, 0xF8, 0x38, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0x38, 0xF0, 0xC0, 0x03, 0x0F, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x08, 0xE4, 0xFF, 0x3F, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 57
    0xC0, 0xC0, 0xC0, 0x01, 0x01, 0x01, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, // 58
    0x00, 0xC0, 0xC0, 0xC0, 0x00, 0x01, 0x01, 0x01, 0x30, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, // 59
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0x60, 0x0C, 0x0C, 0x1E, 0x12, 0x33, 0x21, 0x61, 0x61, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 60
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 61
    0x60, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x61, 0x61, 0x21, 0x33, 0x12, 0x1E, 0x0C, 0x0C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 62
    0x08, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0xF8, 0xF0, 0x00, 0x00, 0x00, 0x38, 0x3C, 0x0E, 0x07, 0x03, 0x01, 0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 63
    0x00, 0xC0, 0xE0, 0x30, 0x18, 0x18, 0x08, 0x0C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x18, 0x18, 0x70, 0xE0, 0x80, 0xFE, 0xFF, 0x00, 0x00, 0x00, 0x3E, 0x7F, 0xC3, 0xC1, 0xC1, 0x41, 0x3F, 0x7F, 0xC0, 0xC0, 0xC0, 0x7F, 0x1F, 0x00, 0x03, 0x07, 0x0E, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 64
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0x3C, 0x3C, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0x7E, 0x3F, 0x31, 0x30, 0x30, 0x31, 0x3F, 0x7E, 0xF0, 0xC0, 0x00, 0x06, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 65
    0xFC, 0xFC, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0xF8, 0xF8, 0x60, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x9D, 0xF9, 0xF0, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 66
    0x80, 0xE0, 0xF0, 0x38, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x08, 0x3F, 0xFF, 0xE1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 67
    0xFC, 0xFC, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x18, 0x38, 0xF0, 0xE0, 0x80, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF0, 0xFF, 0x3F, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 68
    0xFC, 0xFC, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 69
    0xFC, 0xFC, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 70
    0x80, 0xE0, 0xF0, 0x38, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x18, 0x00, 0x3F, 0xFF, 0xE1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x0C, 0x0C, 0xFC, 0xFC, 0x00, 0x00, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 71
    0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0xFF, 0xFF, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 72
    0x04, 0x0C, 0xFC, 0xFC, 0x0C, 0x04, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x04, 0x06, 0x07, 0x07, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 73
    0x00, 0x00, 0xFC, 0xFC, 0x00, 0x00, 0xFF, 0xFF, 0xC0, 0xE0, 0x7F, 0x3F, 0x00, 0x00, 0x00, 0x00, // 74
    0xFC, 0xFC, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x60, 0x38, 0x1C, 0x0C, 0x04, 0xFF, 0xFF, 0x0C, 0x06, 0x0F, 0x1F, 0x38, 0xF0, 0xC0, 0x80, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 75
    0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 76
    0xFC, 0xFC, 0x1C, 0xFC, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0x1C, 0xFC, 0xFC, 0xFF, 0xFF, 0x00, 0x01, 0x0F, 0x7F, 0xF8, 0xC0, 0xC0, 0xF8, 0x3E, 0x07, 0x00, 0x00, 0xFF, 0xFF, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 77
    0xFC, 0xFC, 0x1C, 0x78, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x07, 0x0E, 0x3C, 0xF0, 0xC0, 0x00, 0xFF, 0xFF, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 78
    0x80, 0xE0, 0xF0, 0x38, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x18, 0x38, 0xF0, 0xE0, 0x80, 0x3F, 0xFF, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xFF, 0x3F, 0x00, 0x00, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 79
    0xFC, 0xFC, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x38, 0xF8, 0xF0, 0xFF, 0xFF, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x07, 0x07, 0x01, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0x80, 0xE0, 0xF0, 0x38, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x18, 0x38, 0xF0, 0xE0, 0x80, 0x3F, 0xFF, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xFF, 0x3F, 0x00, 0x00, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x3F, 0x73, 0x61, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 81
    0xFC, 0xFC, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x38, 0xF8, 0xF0, 0x00, 0xFF, 0xFF, 0x0C, 0x0C, 0x0C, 0x1C, 0x7C, 0xE7, 0xC3, 0x01, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 82
    0xF0, 0xF8, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0x00, 0x01, 0x03, 0x03, 0x06, 0x06, 0x0C, 0x0C, 0x1C, 0xF8, 0xF0, 0x03, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 83
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0xFC, 0xFC, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 84
    0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x00, 0x01, 0x03, 0x07, 0x06, 0x06, 0x06, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 85
    0x0C, 0x7C, 0xF8, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF8, 0x7C, 0x0C, 0x00, 0x00, 0x03, 0x1F, 0xFC, 0xE0, 0x00, 0xE0, 0xFC, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x06, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 86
    0x1C, 0xFC, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7C, 0x7C, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF0, 0xFC, 0x1C, 0x00, 0x00, 0x0F, 0xFF, 0xF0, 0x00, 0xF8, 0x7F, 0x07, 0x00, 0x00, 0x07, 0x7F, 0xF0, 0x00, 0xF8, 0x7F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x06, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 87
    0x04, 0x1C, 0x38, 0xF0, 0xC0, 0x00, 0x00, 0xC0, 0xF0, 0x38, 0x1C, 0x04, 0x00, 0x00, 0xC0, 0xF0, 0x3B, 0x1F, 0x1F, 0x7F, 0xF0, 0xC0, 0x00, 0x00, 0x04, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 88
    0x0C, 0x3C, 0xF8, 0xE0, 0x80, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x3C, 0x0C, 0x00, 0x00, 0x00, 0x03, 0x0F, 0xFE, 0xFC, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 89
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x8C, 0xCC, 0xFC, 0x3C, 0x0C, 0x00, 0x80, 0xE0, 0x78, 0x3E, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x06, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 90
    0xFC, 0xFC, 0x0C, 0x0C, 0x0C, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, // 91
    0x0C, 0x3C, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1F, 0xF8, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 92
    0x0C, 0x0C, 0x0C, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x60, 0x60, 0x60, 0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, // 93
    0x00, 0x00, 0x00, 0xC0, 0xE0, 0x38, 0x0C, 0x3C, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x10, 0x1C, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x1C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 95
    0x01, 0x03, 0x07, 0x0E, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 96
    0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0xE0, 0xF0, 0x30, 0x18, 0x18, 0x18, 0x18, 0x19, 0xFF, 0xFF, 0x01, 0x03, 0x07, 0x06, 0x06, 0x06, 0x02, 0x03, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 97
    0xFE, 0xFE, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0xFF, 0xFF, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xFF, 0xFE, 0x07, 0x07, 0x03, 0x02, 0x06, 0x06, 0x06, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 98
    0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0xFE, 0xFF, 0x83, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 99
    0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0xFE, 0xFE, 0xFE, 0xFF, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xFF, 0xFF, 0x00, 0x01, 0x03, 0x06, 0x06, 0x06, 0x06, 0x02, 0x03, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 100
    0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x7C, 0xFF, 0x9B, 0x18, 0x18, 0x18, 0x18, 0x18, 0x19, 0x1F, 0x1E, 0x00, 0x01, 0x03, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 101
    0x80, 0xC0, 0xFC, 0xFE, 0xC6, 0xC6, 0xC6, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 102
    0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x1F, 0xBF, 0xF1, 0x60, 0x60, 0x60, 0x60, 0x71, 0x3F, 0x1F, 0x00, 0x70, 0xF8, 0x8F, 0x87, 0x86, 0x86, 0x86, 0x86, 0x86, 0xC6, 0xFC, 0x78, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, // 103
    0xFE, 0xFE, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 104
    0xCE, 0xCE, 0xFF, 0xFF, 0x07, 0x07, 0x00, 0x00, // 105
    0x00, 0x00, 0xCE, 0xCE, 0x00, 0x00, 0xFF, 0xFF, 0x80, 0x80, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x00, // 106
    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x40, 0xFF, 0xFF, 0x30, 0x18, 0x3E, 0xF7, 0xC3, 0x81, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 107
    0xFE, 0xFE, 0xFF, 0xFF, 0x07, 0x07, 0x00, 0x00, // 108
    0xC0, 0xC0, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 109
    0xC0, 0xC0, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 110
    0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x7E, 0xFF, 0x83, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x83, 0xFF, 0x7C, 0x00, 0x01, 0x03, 0x07, 0x06, 0x06, 0x06, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 111
    0xC0, 0xC0, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0xFF, 0xFF, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xFF, 0xFE, 0xFF, 0xFF, 0x03, 0x02, 0x06, 0x06, 0x06, 0x06, 0x03, 0x01, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 112
    0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0xC0, 0xC0, 0xFE, 0xFF, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xFF, 0xFF, 0x00, 0x01, 0x03, 0x06, 0x06, 0x06, 0x06, 0x02, 0x03, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, // 113
    0xC0, 0xC0, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 114
    0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x07, 0x0F, 0x1C, 0x18, 0x18, 0x30, 0x70, 0xE0, 0xC0, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 115
    0xC0, 0xC0, 0xF0, 0xF8, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 116
    0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x01, 0x03, 0x07, 0x06, 0x06, 0x06, 0x02, 0x03, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 117
    0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x00, 0x07, 0x1F, 0xFC, 0xE0, 0x00, 0x00, 0xE0, 0xFC, 0x1F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 118
    0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x01, 0x1F, 0xFF, 0xF0, 0x00, 0xC0, 0xFC, 0x1F, 0x03, 0x03, 0x1F, 0xFC, 0xC0, 0x00, 0xF0, 0xFF, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x07, 0x06, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x06, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 119
    0x40, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x40, 0x00, 0x00, 0x81, 0xC7, 0xEE, 0x7C, 0x7C, 0xEE, 0xC7, 0x01, 0x00, 0x00, 0x04, 0x06, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 120
    0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x00, 0x03, 0x1F, 0x7C, 0xE0, 0x80, 0x80, 0xE0, 0xFC, 0x1F, 0x07, 0x00, 0x80, 0x80, 0x80, 0xC0, 0xE3, 0x7F, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 121
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x80, 0xC0, 0xF0, 0x38, 0x1E, 0x07, 0x03, 0x00, 0x06, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 122
    0x00, 0x00, 0x00, 0xF8, 0xF8, 0x0C, 0x0C, 0x18, 0x18, 0x3C, 0xFF, 0xE7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x3F, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 123
    0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, // 124
    0x0C, 0x0C, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE7, 0xFF, 0x3C, 0x18, 0x18, 0x60, 0x60, 0x3F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 125
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x06, 0x06, 0x06, 0x06, 0x04, 0x0C, 0x0C, 0x0C, 0x0C, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
    0xFC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // 127
    
};

#endif
