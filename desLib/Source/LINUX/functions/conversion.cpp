#ifndef conversion_cpp
#define conversion_cpp


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


#include <iostream>


using namespace std;


void conversion()
{
 int celsius;
 cout << "Enter the temperature in Celsius: ";
 cin >> celsius;
 // calculate conversion factor for Celsius
 // to Fahrenheit
 int factor;
 factor = 212 - 32;
 // use conversion factor to convert Celsius
 // into Fahrenheit values
 int fahrenheit;
 fahrenheit = factor * celsius/100 + 32;
 // output the results (followed by a NewLine)
 cout << "Fahrenheit value is: ";
 cout << fahrenheit << endl;
}


float Cel2Fer(float TempCel)
{
 float factor = 212 - 32;
 float fahrenheight = factor * TempCel/100 + 32;
 
 
 return fahrenheight;
}

float Fer2Cel(float TempFer)
{
 float TempCel;
 TempCel = ((TempFer - 32) * 5) / 9;
 return TempCel;
}


#endif // conversion_cpp
