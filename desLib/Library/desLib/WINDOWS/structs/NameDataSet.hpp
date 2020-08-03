#ifndef NameDataSet_hpp
#define NameDataSet_hpp


/*
* This code is based off of code in C++ for Dummies 4th Edition *
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


#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

#include "..\functions\_stricmp_.hpp"


using namespace std;


struct NameDataSet
{
 char * firstName;
 char * lastName;
 int creditCard;
};

// getData - populate a NameDataSet object
bool getData(NameDataSet& nds)
{
 cout << "\nEnter first name: ";
 cin >> nds.firstName;
 // compare the name input irrespective of case
 if (_stricmp_(nds.firstName, "exit") == 0)
 {
  return false;
 }
 cout << "Enter last name: ";
 cin >> nds.lastName;
 cout << "Enter credit card number: ";
 cin >> nds.creditCard;
 return true;
}

// displayData - display a data set
void displayData(NameDataSet& nds)
{
 cout << nds.firstName
 << " "
 << nds.lastName
 << "/"
 << nds.creditCard
 << endl;
}


#endif // NameDataSet_hpp
