#ifndef sumSequence_cpp
#define sumSequence_cpp


/*
* This code is based off of code in C++ for Dummies 4th Edition *
*/


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


#include "square.hpp"


int sumSequence(void)
{
 // loop forever
 int accumulator = 0;
 for(;;)
 {
  // fetch another number
  int value = 0;
  cout << "Enter next number: ";
  cin >> value;
  // if it’s negative...
  if (value < 0)
  {
   // ...then exit from the loop
   break;
  }
 // ...otherwise add the number to the
 // accumulator
 accumulator= accumulator + value;
 }
 // return the accumulated value
 return accumulator;
}


// sumSequence - accumulate the square of the number
// entered at the keyboard into a sequence
// until the user enters a negative number
double sumSequence2(void)
{
 // loop forever
 double accumulator= 0.0;
 for(;;)
 {
  // fetch another number
  double dValue = 0;
  cout << "Enter next number: ";
  cin >> dValue;
  // if it’s negative...
  if (dValue < 0)
  {
   // ...then exit from the loop
   break;
  }
  // ...otherwise calculate the square
  double value = square(dValue);
  // now add the square to the
  // accumulator
  accumulator = accumulator + value;
 }
 // return the accumulated value
 return accumulator;
}


#endif // sumSequence
