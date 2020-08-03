#ifndef Array_cpp
#define Array_cpp


/*
* This code was based off of code in Sam's Teach Yourself C++ in Just 21 Days *
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
7/26/15 Original a - 1. The first version.
					 2. Fixed bugs...
					 3. Uses Exception class.
*/


#include "Array.hpp"

#include "Exception.cpp"


template <class T>        
Array<T>::Array(unsigned long s = 1)
{
 data.assign(s, 0);
}

template <>
Array<String>::Array(unsigned long s)
{
 data.assign(s, (char *)""); 
}

template <class T>       
Array<T>::~Array()
{
 
}       

template <class T>
T & Array<T>::get(unsigned long s)
{
 if (s < length())
  return data[s];
 else
 {
  String s2;
  s2.from_long(s);
  throw Exception((String)"get: Index Out of Bounds. index = " + (String)s2 + (char *)"\n", (char *)__FILE__, __LINE__);
 }
}

template <>
String & Array<String>::get(unsigned long s)
{
 if (s < length())
  return data[s];
 else
 {
  String s2;
  s2.from_long(s);
  throw Exception((char *)"get: Index Out of Bounds. index = " + (String)s2 + (char *)"\n", (char *)__FILE__, __LINE__);
 }
}

template <class T>
void Array<T>::put(T d, unsigned long s)
{
 if (s < length())
 {
  data[s] = d;
 }
 else
 {
  String s2;
  s2.from_long(s);
  throw Exception((String)"put: Index Out of Bounds. index = " + s2 + "\n", __FILE__, __LINE__);
 }
}

template <class T>
unsigned long Array<T>::length() const
{
 return data.size();
}

template <class T>
Array<T> Array<T>::operator=(const Array<T> & rhs)
{
 if (this == &rhs)
  return *this;
 
 data.assign(rhs.length(), 0);
 
 for (unsigned long i = 0; i < length(); ++i)
  data[i] = rhs.data[i];
  
  
 return (*this);
}

template <>
Array<String> Array<String>::operator=(const Array<String> & rhs)
{
 if (this == &rhs)
  return *this;
 
 data.assign(rhs.length(), (char *)"");
 
 for (unsigned long i = 0; i < length(); ++i)
  data[i] = rhs.data[i];
  
  
 return (*this);
}

template <class T>
T & Array<T>::operator[](unsigned long offSet)
{
 return get(offSet);
}

template <class T>
void Array<T>::insert()
{
 try
 {
  data.push_back(0);
 }
 catch (exception e)
 {
  throw Exception("Cannot allocate element.\n", __FILE__, __LINE__);
 }
}

template <>
void Array<String>::insert()
{
 try
 {
  data.push_back((char *)"");
 }
 catch (exception e)
 {
  throw Exception((char *)"Cannot allocate element.\n", (char *)__FILE__, __LINE__); 
 }
}

template <class T>
void Array<T>::remove()
{
 data.pop_back();
}

template <class T>
void Array<T>::insert(T d, unsigned long offset)
{
 Array<T> d1;
 unsigned long len;
 
 if (offset == length())
  len = offset + 1;
 else if (offset > length())
  len = offset;
 else
  len = length();
  
 
 for (unsigned long i = 0; i < len; ++i)
 { 
  if (i == offset)
  {
   if (i != 0)
    d1.insert();
   d1[i] = d;
  }
  else
  {   
   if (i != 0)
    d1.insert();
    
   if (i >= length())
   {
   	d1[i] = 0;
   	continue;
   }
   
   d1[i] = data[i];
  }
 }
 
 for (unsigned long i = 0; i < d1.length(); ++i)
 {
  if (i >= length())
   insert();
  data[i] = d1[i];
 }
}

template <>
void Array<String>::insert(String d, unsigned long offset)
{
 Array<String> d1;
 unsigned long len;
 
 if (offset == length())
  len = offset + 1;
 else if (offset > length())
  len = offset;
 else
  len = length();
  
  
 for (unsigned long i = 0; i < len; ++i)
 { 
  if (i == offset)
  {
   if (i != 0)
    d1.insert();
   d1[i] = d;
  }
  else
  {  
   if (i != 0)
    d1.insert();
    
   if (i >= length())
   {
   	d1[i] = (char *)"";
   	continue;
   }
   d1[i] = data[i];
  }
 }
 
 for (unsigned long i = 0; i < d1.length(); ++i)
 {
  if (i >= length())
   insert();
  data[i] = d1[i];
 }
}

template <class T>
void Array<T>::remove(unsigned long offset)
{
 data.erase(data.begin() + offset); 
}

template <class T>
void Array<T>::copy(unsigned long d1, unsigned long d2)
{
 insert(data[d1], d2);
}

template <class T>
void Array<T>::move(unsigned long d1, unsigned long d2)
{
 copy(d1, d2);
 data[d1] = 0;
}

template <>
void Array<String>::move(unsigned long d1, unsigned long d2)
{
 copy(d1, d2);
 data[d1] = (char *)"";
}


String operator +(char * arg1, String arg2)
{
 String str((char *)arg1);
 str += arg2;
 
 return str;
}


#endif // Array_cpp
