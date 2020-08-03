#ifndef IO_cpp
#define IO_cpp


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


#include "IO.hpp"

#include "Exception.cpp"


IO::IO(IO_DEVICE where, IO_WHICH which)
{
 itswhere = where;
 itswhich = which;	
}

IO::~IO()
{
 itsfin.close();
 itsfout.close();
 delete itsdata;
}


IO_DEVICE IO::where()
{
 return itswhere;
}

IO_WHICH IO::which()
{
 return itswhich;
}
  
void IO::where(IO_DEVICE w)
{
 itswhere = w;
}

void IO::which(IO_WHICH w)
{
 itswhich = w;
}
  
void IO::open(String filename, IO_MODE mode)
{
 if (itswhere == DEVFILE && itswhich == WHNEW)
 {
  if (mode == MIN)
  {
   itsfin.open(filename.getString().c_str());
   itsio = false;
  }
  else
  {
   itsio = true;
   switch (mode)
   {
   	case MOUT:
   	 itsfout.open(filename.getString().c_str(), ios::out);
     break;
     
   	case MBINARY:
   	 itsfout.open(filename.getString().c_str(), ios::binary);
     break;
     
   	case MATE:
   	 itsfout.open(filename.getString().c_str(), ios::ate);
     break;
     
   	case MAPP:
   	 itsfout.open(filename.getString().c_str(), ios::app);
     break;
     
   	case MTRUNC:
   	 itsfout.open(filename.getString().c_str(), ios::trunc);
     break;
     
   	default:
     itsfout.open(filename.getString().c_str(), ios::out);
     break;
   };
  }
 }
}

void IO::close()
{
 itsfin.close();
 itsfout.close();
}

bool * IO::is_open()
{
 bool b;
 if (itsio == true)
  b = itsfout.is_open();
 else
  b = itsfin.is_open();
  
 itsdata = new bool(b);
 return itsdata;
}

IO & IO::put(char c)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout.put(c);
   	break;
   	
   case DEVERROR:
   	cerr.put(c);
   	break;
   	
   case DEVLOG:
   	clog.put(c);
   	break;
   	
   case DEVFILE:
   	itsfout.put(c);
   	break;
   	
   default:
   	cout.put(c);
   	break;
  }
 }
 
 return *this;
}

IO & IO::write(const char * s, long n)
{
if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout.write(s, n);
   	break;
   	
   case DEVERROR:
   	cerr.write(s, n);
   	break;
   	
   case DEVLOG:
   	clog.write(s, n);
   	break;
   	
   case DEVFILE:
   	itsfout.write(s, n);
   	break;
   	
   default:
   	cout.write(s, n);
   	break;
  }
 }
 
 return *this;
}

long IO::tellp()
{
 long ret;
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	ret = cout.tellp();
   	break;
   	
   case DEVERROR:
   	ret = cerr.tellp();
   	break;
   	
   case DEVLOG:
   	ret = clog.tellp();
   	break;
   	
   case DEVFILE:
   	ret = itsfout.tellp();
   	break;
   	
   default:
   	ret = cout.tellp();
   	break;
  }
 }
 else
  ret = -1;
 
 return ret;
}

IO & IO::flush()
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout.flush();
   	break;
   	
   case DEVERROR:
   	cerr.flush();
   	break;
   	
   case DEVLOG:
   	clog.flush();
   	break;
   	
   case DEVFILE:
   	itsfout.flush();
   	break;
   	
   default:
   	cout.flush();
   	break;
  }
 }
 
 return *this;	
}

IO & IO::operator >>(char * data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cin >> data;
   	break;
   	
   case DEVERROR:
   	// Fall through...
   case DEVLOG:
   	throw Exception((char *)"Cannot input from device.", (char *)__FILE__, __LINE__);
   	break;
   	
   case DEVFILE:
   	itsfin >> data;
   	break;
   	
   default:
   	cin >> data;
   	break;
  }
 }
 
 return *this;
}

IO & IO::operator <<(char * data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout << data;
   	break;
   	
   case DEVERROR:
   	cerr << data;
   	break;
   	
   case DEVLOG:
   	clog << data;
   	break;
   	
   case DEVFILE:
   	itsfout << data;
   	break;
   	
   default:
   	cout << data;
   	break;
  }
 }
 
 return *this;
}

IO & IO::operator >>(string data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cin >> data;
   	break;
   	
   case DEVERROR:
   	// Fall through...
   case DEVLOG:
   	throw Exception((char *)"Cannot input from device.", (char *)__FILE__, __LINE__);
   	break;
   	
   case DEVFILE:
   	itsfin >> data;
   	break;
   	
   default:
   	cin >> data;
   	break;
  }
 }
 
 return *this;	
}

IO & IO::operator <<(string data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout << data;
   	break;
   	
   case DEVERROR:
   	cerr << data;
   	break;
   	
   case DEVLOG:
   	clog << data;
   	break;
   	
   case DEVFILE:
   	itsfout << data;
   	break;
   	
   default:
   	cout << data;
   	break;
  }
 }
 
 return *this;	
}

IO & IO::operator >>(int & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cin >> data;
   	break;
   	
   case DEVERROR:
   	// Fall through...
   case DEVLOG:
   	throw Exception((char *)"Cannot input from device.", (char *)__FILE__, __LINE__);
   	break;
   	
   case DEVFILE:
   	itsfin >> data;
   	break;
   	
   default:
   	cin >> data;
   	break;
  }
 }
 
 return *this;	
}

IO & IO::operator <<(int & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout << data;
   	break;
   	
   case DEVERROR:
   	cerr << data;
   	break;
   	
   case DEVLOG:
   	clog << data;
   	break;
   	
   case DEVFILE:
   	itsfout << data;
   	break;
   	
   default:
   	cout << data;
   	break;
  }
 }
 
 return *this;	
}
  
IO & IO::operator >>(short & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cin >> data;
   	break;
   	
   case DEVERROR:
   	// Fall through...
   case DEVLOG:
   	throw Exception((char *)"Cannot input from device.", (char *)__FILE__, __LINE__);
   	break;
   	
   case DEVFILE:
   	itsfin >> data;
   	break;
   	
   default:
   	cin >> data;
   	break;
  }
 }
 
 return *this;	
}

IO & IO::operator <<(short & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout << data;
   	break;
   	
   case DEVERROR:
   	cerr << data;
   	break;
   	
   case DEVLOG:
   	clog << data;
   	break;
   	
   case DEVFILE:
   	itsfout << data;
   	break;
   	
   default:
   	cout << data;
   	break;
  }
 }
 
 return *this;	
}
  
IO & IO::operator >>(long & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cin >> data;
   	break;
   	
   case DEVERROR:
   	// Fall through...
   case DEVLOG:
   	throw Exception((char *)"Cannot input from device.", (char *)__FILE__, __LINE__);
   	break;
   	
   case DEVFILE:
   	itsfin >> data;
   	break;
   	
   default:
   	cin >> data;
   	break;
  }
 }
 
 return *this;	
}

IO & IO::operator <<(long & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout << data;
   	break;
   	
   case DEVERROR:
   	cerr << data;
   	break;
   	
   case DEVLOG:
   	clog << data;
   	break;
   	
   case DEVFILE:
   	itsfout << data;
   	break;
   	
   default:
   	cout << data;
   	break;
  }
 }
 
 return *this;	
}
  
IO & IO::operator >>(float & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cin >> data;
   	break;
   	
   case DEVERROR:
   	// Fall through...
   case DEVLOG:
   	throw Exception((char *)"Cannot input from device.", (char *)__FILE__, __LINE__);
   	break;
   	
   case DEVFILE:
   	itsfin >> data;
   	break;
   	
   default:
   	cin >> data;
   	break;
  }
 }
 
 return *this;	
}

IO & IO::operator <<(float & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout << data;
   	break;
   	
   case DEVERROR:
   	cerr << data;
   	break;
   	
   case DEVLOG:
   	clog << data;
   	break;
   	
   case DEVFILE:
   	itsfout << data;
   	break;
   	
   default:
   	cout << data;
   	break;
  }
 }
 
 return *this;	
}
  
IO & IO::operator >>(double & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cin >> data;
   	break;
   	
   case DEVERROR:
   	// Fall through...
   case DEVLOG:
   	throw Exception((char *)"Cannot input from device.", (char *)__FILE__, __LINE__);
   	break;
   	
   case DEVFILE:
   	itsfin >> data;
   	break;
   	
   default:
   	cin >> data;
   	break;
  }
 }
 
 return *this;	
}

IO & IO::operator <<(double & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout << data;
   	break;
   	
   case DEVERROR:
   	cerr << data;
   	break;
   	
   case DEVLOG:
   	clog << data;
   	break;
   	
   case DEVFILE:
   	itsfout << data;
   	break;
   	
   default:
   	cout << data;
   	break;
  }
 }
 
 return *this;	
}
  
IO & IO::operator >>(bool & data)
{
 String d = (char *)"";
 
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cin >> d;
   	break;
   	
   case DEVERROR:
   	// Fall through...
   case DEVLOG:
   	throw Exception((char *)"Cannot input from device.", (char *)__FILE__, __LINE__);
   	break;
   	
   case DEVFILE:
   	itsfin >> d;
   	break;
   	
   default:
   	cin >> d;
   	break;
  }
  
  data = d == (char *)"true" ? true : false;
 }
 
 return *this;	
}

IO & IO::operator <<(bool & data)
{
 String d = data == true ? (char *)"true" : (char *)"false";
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout << d;
   	break;
   	
   case DEVERROR:
   	cerr << d;
   	break;
   	
   case DEVLOG:
   	clog << d;
   	break;
   	
   case DEVFILE:
   	itsfout << d;
   	break;
   	
   default:
   	cout << d;
   	break;
  }
 }
 
 return *this;	
}
  
IO & IO::operator >>(char & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cin >> data;
   	break;
   	
   case DEVERROR:
   	// Fall through...
   case DEVLOG:
   	throw Exception((char *)"Cannot input from device.", (char *)__FILE__, __LINE__);
   	break;
   	
   case DEVFILE:
   	itsfin >> data;
   	break;
   	
   default:
   	cin >> data;
   	break;
  }
 }
 
 return *this;	
}

IO & IO::operator <<(char & data)
{
 if (itswhich == WHNEW)
 {
  switch (itswhere)
  {
   case DEVCONSOLE:
   	cout << data;
   	break;
   	
   case DEVERROR:
   	cerr << data;
   	break;
   	
   case DEVLOG:
   	clog << data;
   	break;
   	
   case DEVFILE:
   	itsfout << data;
   	break;
   	
   default:
   	cout << data;
   	break;
  }
 }
 
 return *this;	
}

IO & IO::operator >>(bool * data)
{
 *this >> *data;
 return *this;
}

IO & IO::operator <<(bool * data)
{
 *this << *data;
 return *this;
}


#endif // IO_cpp
