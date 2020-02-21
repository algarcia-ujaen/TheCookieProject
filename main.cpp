#include <cstdlib>
#include <iostream>

#include "Cookie.h"

using namespace std;

int main ( int argc, char** argv )
{
   Cookie c1;
   Cookie c2 ( "Chocolate cookie", 3 );

   Cookie* pC1 = nullptr;

   try
   {
      pC1 = new Cookie ( "testCookie", true, -3, 4 );
   }
   catch ( std::string& e )
   {
      cout << e << endl;
   }

   Cookie c3 ( "Vanilla cookie", true, 100, 4 );
   Cookie c4 ( c1 );
   Cookie c5 = c2;
   c5.setCalories (0)
     .setGlutenFree ( true )
     .setName ( "myCookie" );

   try
   {
      ( c2 + "vanilla" ) + "chocolate";
   }
   catch ( std::string& e )
   {

   }
   return 0;
}

