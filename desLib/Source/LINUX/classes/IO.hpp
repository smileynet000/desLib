#ifndef IO_hpp
#define IO_hpp


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
5/5/16 Original a - The first version.
*/


#include <iostream>
#include <fstream>

#include "String.cpp"


using namespace std;


enum IO_DEVICE
{
 DEVCONSOLE = 0,
 DEVERROR,
 DEVLOG,
 DEVFILE
};

enum IO_WHICH
{
 WHOLD = 0,
 WHNEW
};

enum IO_MODE
{
 MIN = 0,
 MOUT,
 MBINARY,
 MATE,
 MAPP,
 MTRUNC	
};

class IO
{
 protected:
  IO_DEVICE itswhere;
  IO_WHICH itswhich;
  
  ifstream itsfin;
  ofstream itsfout;
  
  bool itsio;
  
  bool * itsdata;
  
 public:
  IO(IO_DEVICE where = DEVCONSOLE, IO_WHICH which = WHNEW);
  ~IO();
 
  IO_DEVICE where();
  IO_WHICH which();
  
  void where(IO_DEVICE w);
  void which(IO_WHICH w);
  
  
  void open(String filename, IO_MODE mode); 
  void close();
  
  bool * is_open();
  
  
  IO & put(char c);
  IO & write(const char * s, long n);
  
  
  long tellp();
  
  
  IO & flush();
  
  
  IO & operator >>(char * data);
  IO & operator <<(char * data);
  
  IO & operator >>(string data);
  IO & operator <<(string data);
  
  IO & operator >>(int & data);
  IO & operator <<(int & data);
  
  IO & operator >>(short & data);
  IO & operator <<(short & data);
  
  IO & operator >>(long & data);
  IO & operator <<(long & data);
  
  IO & operator >>(float & data);
  IO & operator <<(float & data);
  
  IO & operator >>(double & data);
  IO & operator <<(double & data);
  
  IO & operator >>(bool & data);
  IO & operator <<(bool & data);
  
  IO & operator >>(char & data);
  IO & operator <<(char & data);
  
  IO & operator >>(bool * data);
  IO & operator <<(bool * data);
};


#endif // IO_hpp
