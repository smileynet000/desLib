#ifndef Animal_hpp
#define Animal_hpp


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


#include <string>
#include "Life.cpp"


using namespace std;


class Animal : public Life
{
 private:
         bool awake;
         bool blooded;
         string words;
         
         
 public:
        Animal(bool eternal, unsigned long age, unsigned long weight, unsigned long height, bool alive, bool awake, bool blooded, string words);
        
        ~Animal();
        
        
        bool getAwake();
        bool getBlooded();
        
        void setAwake(bool awake);
        void setBlooded(bool blooded);
        
        
        void sleep();
        void wakeup();
        virtual void think(string words);
        virtual void speak();
        
        
        void operator>>(string words);
        void operator<<(string words);
};


#endif // Animal_hpp
