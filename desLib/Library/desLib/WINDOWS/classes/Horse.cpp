#ifndef Horse_cpp
#define Horse_cpp


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


#include "Horse.hpp"

Horse::Horse(bool eternal = false, unsigned long age = 0, unsigned long weight = 0, unsigned long height = 0, bool alive = true, bool awake = true)
{
 Mammal(eternal, age, weight, height, alive, awake, "Winnie!\n");
}

void Horse::think()
{
 Animal::think("Winnie!\n");
}

void Horse::think(string words)
{
 Animal::think("Winnie!\n");
}
        
void Horse::winnie()
{
 this->think();
 this->speak();
}


#endif // Horse_cpp
