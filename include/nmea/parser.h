/*
 * This file is part of nmealib.
 *
 * Copyright (c) 2008 Timur Sinitsyn
 * Copyright (c) 2011 Ferry Huberts
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __NMEA_PARSER_H__
#define __NMEA_PARSER_H__

#include <nmea/info.h>
#include <nmea/sentence.h>

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum _sentence_parser_state {
  SKIP_UNTIL_START,
  READ_SENTENCE,
  READ_CHECKSUM,
  READ_EOL
} sentence_parser_state;

/**
 * NMEA frame parser structure
 */
typedef struct _sentencePARSER {
    char * sentence_start;
    unsigned int sentence_length;
    int sentence_checksum;
    int calculated_checksum;

    char sentence_checksum_chars[2];
    char sentence_checksum_chars_count;

    char sentence_eol_chars_count;

    sentence_parser_state state;
} sentencePARSER;

/**
 * parsed NMEA data and frame parser state
 */
typedef struct _nmeaPARSER {
    union {
        nmeaGPGGA gpgga;
        nmeaGPGSA gpgsa;
        nmeaGPGSV gpgsv;
        nmeaGPRMC gprmc;
        nmeaGPVTG gpvtg;
    } sentence;

    sentencePARSER sentence_parser;
} nmeaPARSER;

int nmea_parser_init(nmeaPARSER *parser);
int nmea_parse(nmeaPARSER * parser, const char * s, int len, nmeaINFO * info);

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* __NMEA_PARSER_H__ */
