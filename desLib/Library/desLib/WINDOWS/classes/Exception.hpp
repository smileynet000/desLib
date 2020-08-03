#ifndef Exception_hpp
#define Exception_hpp


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


class Exception
{
 protected:
  String itswhat;
  
  String itsfile;
  long itsline;
  
  
 public:
  Exception(String w = (char *)"General Exception", String f = (char *)__FILE__, long l = __LINE__);
  
  ~Exception();
  
  
  String what();
  void what(String w);
  
  String file();
  void file(String f);
  
  long line();
  void line(long l);
  
  void display();
};


#endif	// Exception_hpp
