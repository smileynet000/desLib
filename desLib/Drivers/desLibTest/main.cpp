/*
 Program:
 
 File:
 
 Description:
 
 Author: Dennis Earl Smiley
 
 Enviroment: Dev-C++ 5.5.3
 
 Notes:
 
 Revisons:
*/
// Includes go here...
#include <desLib/desLib.hpp>


// Classes go here...


// Global variables go here...
char * _memblock_;


// Function prototypes go here...


// Functions go here...
int main(int argc, char ** argv)
{
 try
 {
  // Boiler plate code...
  _memblock_ = new char[5000];
  
  
  // main program...
  Array<int> a;
  
  a[0] = 1;
  a.insert();
  a[1] = 500;
  a[2] = 3;
 
   
  return 0;
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
