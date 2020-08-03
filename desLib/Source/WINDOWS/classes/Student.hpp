#ifndef Student_hpp
#define Student_hpp


/*
* This code was based off of code in C++ for Dummies 4th Edition *
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


class Student
{
 public:
        // add a completed course to the record
        float addCourse(int hours, float grade)
        {
         // calculate the sum of all courses times
         // the average grade
         float weightedGPA;
         weightedGPA = semesterHours * gpa;
         // now add in the new course
         semesterHours += hours;
         weightedGPA += grade * hours;
         gpa = weightedGPA / semesterHours;
         // return the new gpa
         return gpa;
        }
        int semesterHours;
        float gpa;
};


#endif // Student_hpp
