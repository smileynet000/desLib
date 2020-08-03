#ifndef displayArray_cpp
#define displayArray_cpp


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


// displayArray - display the members of an
// array of length sizeOfloatArray
void displayArray(int integerArray[], int sizeOfArray)
{
 cout << "The value of the array is: " << endl;
 for (int i = 0; i < sizeOfArray; i++)
 {
  cout.width(3);
  cout << i << ": " << integerArray[i] << endl;
 }
 cout << endl;
}

void displayArray(char stringArray[], int sizeOfloatArray)
{
 for(int i = 0; i< sizeOfloatArray; i++)
 {
  cout << stringArray[i];
 }
}


#endif // displayArray_cpp
