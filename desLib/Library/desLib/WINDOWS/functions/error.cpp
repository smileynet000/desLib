#ifndef error_cpp
#define error_cpp


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


#include "../classes/String.cpp"


// Code Here
enum error_type 
{ 
 ERRORMSG = 0, 
 WARNINGMSG 
};

void error(error_type e, String str)
{
 switch (e)
 {
  case ERRORMSG:
       cout << "* ERROR: " << str << "\n\n";
       break;
       
  case WARNINGMSG:
       cout << "* WARNING: " << str << "\n\n";
       break;
       
       
  default:
        cout << "* ERROR: " << str << "\n\n";
        break;
 }
}


#endif // error_cpp
