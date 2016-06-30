/*
 * This file is part of nmealib.
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

#include "mockContext.h"
#include <stdio.h>

int nmeaTraceCalls = 0;
int nmeaErrorCalls = 0;

void mockContextReset(void) {
  nmeaTraceCalls = 0;
  nmeaErrorCalls = 0;
}

void traceFunction(const char *s __attribute__((unused)), size_t sz __attribute__((unused))) {
  nmeaTraceCalls++;
}

void errorFunction(const char *s __attribute__((unused)), size_t sz __attribute__((unused))) {
//  printf("\n***ERROR*** %s\n", s);
  nmeaErrorCalls++;
}
