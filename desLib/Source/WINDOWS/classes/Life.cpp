#ifndef Life_cpp
#define Life_cpp


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


#include "Life.hpp"


Life::Life(bool e = false, unsigned long a = 0, unsigned long w = 0, unsigned long h = 0, bool al = true)
{
 eternal = e;
 age = a;
 weight = w;
 height = h;
 alive = al;
}

Life::~Life()
{
 
}        
        
bool Life::getEternal()
{
 return eternal;
}

unsigned long Life::getAge()
{
 return age;
}

unsigned long Life::getWeight()
{
 return weight;
}

unsigned long Life::getHeight()
{
 return height;
}

bool Life::getAlive()
{
 return alive;
}
        
void Life::setEternal(bool e)
{
 eternal = e;
}

void Life::setAge(unsigned long a)
{
 age = a;
}

void Life::setWeight(unsigned long w)
{
 weight = w;
}

void Life::setHeight(unsigned long h)
{
 height = h;
}

void Life::setAlive(bool a)
{
 alive = a;
}        
        
void Life::addYears(unsigned long a = 1)
{
 age += a;
}

void Life::subYears(unsigned long a = 1)
{
 age -= a;
}
        
void Life::addHeight(unsigned long h = 1)
{
 height += h;
}

void Life::subHeight(unsigned long h = 1)
{
 height -= h;
}
        
void Life::grow()
{
 addHeight();
}

void Life::shrink()
{
 subHeight();
}

void Life::birthday()
{
 addYears();
}


#endif // Life_cpp
