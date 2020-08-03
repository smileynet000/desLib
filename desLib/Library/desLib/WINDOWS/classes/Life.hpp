#ifndef Life_hpp
#define Life_hpp


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


class Life
{
 private:
         bool eternal;
         unsigned long age;
         unsigned long weight;
         unsigned long height;
         
         bool alive;
         
         
 public:
        Life(bool e, unsigned long a, unsigned long w, unsigned long h, bool al);
        ~Life();
        
        
        bool getEternal();
        unsigned long getAge();
        unsigned long getWeight();
        unsigned long getHeight();
        bool getAlive();
        
        void setEternal(bool e);
        void setAge(unsigned long a);
        void setWeight(unsigned long w);
        void setHeight(unsigned long h);
        void setAlive(bool a);
        
        
        void addYears(unsigned long a);
        void subYears(unsigned long a);
        
        void addHeight(unsigned long h);
        void subHeight(unsigned long h);
        
        void grow();
        void shrink();
        void birthday();
};


#endif // Life_hpp
