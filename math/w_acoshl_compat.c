/* Copyright (C) 2011-2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@gmail.com>, 2011.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <math.h>
#include <math_private.h>
#include <math-svid-compat.h>


/* wrapper acosl */
long double
__acoshl (long double x)
{
  if (__builtin_expect (isless (x, 1.0L), 0) && _LIB_VERSION != _IEEE_)
    /* acosh(x<1) */
    return __kernel_standard_l (x, x, 229);

  return __ieee754_acoshl (x);
}
weak_alias (__acoshl, acoshl)