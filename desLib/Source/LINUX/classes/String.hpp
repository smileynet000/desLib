#ifndef String_hpp
#define String_hpp


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
					 2. Removed useless comments.
*/


#include <string>


class String
{
 private:
         string str;
         
 public:
        String();
        String(string s);
        String(char * s);
        String(char c);
        String(unsigned long l);
        
        ~String();
        
        
        char & operator[](unsigned long offset);
        char operator[](unsigned long offset) const;
        String operator+(String s);
        String operator+(char c);
        void operator+=(String s);
        void operator+=(char * s);
        void operator+=(char c);
        
        bool operator==(String s);
        bool operator!=(String s);
        bool operator<(String s);
        bool operator>(String s);
        bool operator<=(String s);
        bool operator>=(String s);
        
        String operator=(const String & s);
        
        
        string getString();
        
        void setString();
        void setString(string s);
        void setString(char * s);


        unsigned long length();
        unsigned long size();

        unsigned long begin();
        unsigned long end();
        unsigned long rbegin();
        unsigned long rend();

        void clear();
        bool empty();
        
        void insert();
        void remove();
        
        void insert(unsigned long offset, char d);
        void remove(unsigned long offset);


        void from_long(unsigned long l);


        String reverse();
};


#endif // String_hpp
