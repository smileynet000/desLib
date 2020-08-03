#ifndef fib_cpp
#define fib_cpp


/*
Copyright (C) 2017 Dennis Earl Smiley


This file is part of desLib.

desLib is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

desLib is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with desLib.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
CHANGELOG
=========
7/26/15 Original a - The first version.
*/


unsigned long fib(unsigned long n)
{
 long minus2, minus1, awnser;
 
 
 if (n < 3)
  return 1;
  
  
 for (n -= 3; n; --n)
 {
  minus2 = minus1;
  minus1 = awnser;
  
  awnser = minus1 + minus2;
 }
 
 
 return awnser;
}


#endif // fib_cpp
