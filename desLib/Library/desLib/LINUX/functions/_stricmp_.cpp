#ifndef _stricmp__cpp
#define _stricmp__cpp


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


#include <cctype>
#include <cstring>


// Code Here
int _stricmp_(const char * s1, const char * s2)
{
 char ch;
 char * s3;
 char * s4;
 for (unsigned long i = 0; i < strlen(s1); ++i)
 {
  ch = tolower(s1[i]);
  s3[i] = ch;
 }
 
 for (unsigned long i = 0; i < strlen(s2); ++i)
 {
  ch = tolower(s2[i]);
  s4[i] = ch;
 }
 
 int ret = strcmp(s3, s4);
 
 
 return ret;
}


#endif // _stricmp__cpp
