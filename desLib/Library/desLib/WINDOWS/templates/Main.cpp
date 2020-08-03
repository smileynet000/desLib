#ifndef Main_cpp
#define Main_cpp


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
5/6/16 Original a - The first version.
*/


// Includes go here...
#include "../classes/Array.cpp"


// Classes go here...


// Global variables go here...
char * _memblock_;


#ifdef TEMPLATE_Main
// Function prototypes go here...
int Main(Array<String> args);


// Functions go here...
int main(int argc, char ** argv)
{
 try
 {
  // Boiler plate code...
  _memblock_ = new char[5000];


  // main program...
  Array<String> args;
  
  for (unsigned long i = 0; i < argc; ++i)
  {
   args.insert();
   args[i] = argv[i];
  }
   
  int ret = Main(args);


  return ret;
 }
 catch (Exception e)
 {
  e.display();
  exit(1);
 }
 catch (bad_alloc e)
 {
  delete _memblock_;
  error(ERRORMSG, (char *)"Out of Memory.");
  exit(1);
 }
 catch (...)
 {
  error(ERRORMSG, (char *)"Uncaught Exception.");
  exit(1);
 }
}
#endif // TEMPLATE_Main


#endif // Main_cpp
