/* 
Copyright (C) 1990 Free Software Foundation
    written by Doug Lea (dl@rocky.oswego.edu)

This file is part of the GNU C++ Library.  This library is free
software; you can redistribute it and/or modify it under the terms of
the GNU Library General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your
option) any later version.  This library is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU Library General Public License for more details.
You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the Free Software
Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#ifdef __GNUG__
#pragma implementation
#endif
#include <builtin.h>

/*
 some useful hash functions
*/

unsigned int hashpjw(const char* x) // From Dragon book, p436
{
  _G_uint32_t h = 0;
  _G_uint32_t g;

  while (*x != 0)
  {
    h = (h << 4) + *x++;
    if ((g = h & 0xf0000000) != 0)
      h = (h ^ (g >> 24)) ^ g;
  }
  return h;
}

_G_uint32_t multiplicativehash(_G_int32_t x)
{
  // uses a const close to golden ratio * pow(2,32)
  return ((_G_uint32_t)x) * 2654435767U;
}


unsigned int foldhash(double x)
{
  union { unsigned int i[2]; double d; } u;
  u.d = x;
  unsigned int u0 = u.i[0];
  unsigned int u1 = u.i[1]; 
  return u0 ^ u1;
}

