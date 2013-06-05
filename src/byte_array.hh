/**
 * Copyright (c) 2007-2012, Timothy Stack
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * * Neither the name of Timothy Stack nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __byte_array_hh
#define __byte_array_hh

#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include <string>

template<size_t BYTE_COUNT>
struct byte_array {
    byte_array() { };

    byte_array(const byte_array &other)
    {
        memcpy(this->ba_data, other.ba_data, BYTE_COUNT);
    };

    bool operator<(const byte_array &other) const
    {
        return memcmp(this->ba_data, other.ba_data, BYTE_COUNT) < 0;
    };

    bool operator!=(const byte_array &other) const
    {
        return memcmp(this->ba_data, other.ba_data, BYTE_COUNT) != 0;
    };

    void to_string(char *buffer) const {
        for (size_t lpc = 0; lpc < BYTE_COUNT; lpc++) {
            snprintf(&buffer[lpc * 2], 3, "%02x", this->ba_data[lpc]);
        }
    };

    std::string to_string() const {
        char buffer[BYTE_COUNT * 2 + 1];

        this->to_string(buffer);
        return std::string(buffer);
    }

    unsigned char *out() { return this->ba_data; };

    unsigned char ba_data[BYTE_COUNT];
};
#endif