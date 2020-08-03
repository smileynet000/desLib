#ifndef Array_hpp
#define Array_hpp


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
7/26/15 Original a - The first version.
*/


#include <vector>


template <class T>
class Array
{
 private:
         vector<T> data;
         
         
 public:
        Array(unsigned long s);
        ~Array();
        
        
        T & get(unsigned long s);
        void put(T d, unsigned long s);
        unsigned long length() const;
        
        Array<T> operator=(const Array<T> & rhs);
        T & operator[](unsigned long offSet);
        
        void insert();
        void remove();
        
        void insert(T d, unsigned long offset);
        void remove(unsigned long offset);
        void copy(unsigned long d1, unsigned long d2);
        void move(unsigned long d1, unsigned long d2);
};

String operator +(char * arg1, String arg2);


#endif // Array_hpp
