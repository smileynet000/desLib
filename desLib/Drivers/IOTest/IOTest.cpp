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

#include "../../Source/classes/IO.cpp"


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
  IO io;
  io << (char *)"Hello World!\n";
  string str = "Hello 2!\n";
  io << str;
  
  bool b;
  io << (char *)": ";
  io >> b;
  io << (char *)"Your bool was: " << b << (char *)"\n";
  
  io.where(DEVFILE);
  io.open((char *)"a.txt", MAPP);
  io << (char *)"Hello World!\n";
  io << io.is_open() << (char *)"\n";
  io.close();
  
  io.where(DEVCONSOLE);
  io.put('D');
  io.put('\n');
  
  const char * s = (const char *)"Hello World to You!\n";
  io.write(s, 20);
  
  
  io.where(DEVFILE);
  io.open ((char *)"test.txt", MOUT);

  io.write ("This is an apple", 16);
  long pos = io.tellp();
  io << pos;

  io.close();
  
  
  io.open((char *)"test2.txt", MOUT);

  for (int n=0; n<100; ++n)
  {
    io << n;
    io.flush();
  }
  io.close();



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

