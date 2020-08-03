#ifndef Exception_cpp
#define Exception_cpp


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
9/22/15 Original a - The first version.
*/
#include "Exception.hpp"

#include "../functions/error.hpp"


Exception::Exception(String w, String f, long l) : itswhat(w), itsfile(f), itsline(l)
{
 
}
  
Exception::~Exception()
{
	
}  
  
String Exception::what()
{
 return itswhat;
}

void Exception::what(String w)
{
 itswhat = w;
}
  
String Exception::file()
{
 return itsfile;
}

void Exception::file(String f)
{
 itsfile = f;
}
  
long Exception::line()
{
 return itsline;
}

void Exception::line(long l)
{
 itsline = l;
}
  
void Exception::display()
{
 String str;
 str.from_long(line());
 String msg = what() + (char *)" @ " + file() + (char *)": " + str + (char *)".";
 error(ERRORMSG, msg);
}


#endif	// Exception_cpp
