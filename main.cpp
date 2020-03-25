#include <cstdlib>
#include <iostream>

#include "Cookie.h"
#include "IngredientInRecipe.h"

using namespace std;

int main ( int argc, char** argv )
{
   // Declare ingredients and set names
   Ingredient i1, i2, i3;

   i1.setName ( "Flour" );
   i2.setName ( "Chocolate chips" );
   i3.setName ( "Milk" );

   // Declare recipe and add ingredients and actions to the recipe
   Recipe recipe1;

   recipe1.addAction ( "Take a bowl", "big enough" )
          .addAction ( "Add", "" )
          .addIngredient ( i1, 50, "sifted" )
          .addAction ( "Pour", "slowly")
          .addIngredient ( i3, 12.5, "hot" )
          .addAction ( "Remove", "with a spoon" )
          .addIngredient (i2, 30, "white and dark" )
          .addAction ( "Bake", "20 minutes" );

   // Show the recipe on screen
   // FOR THE MOMENT THIS DOES NOT WORK AS EXPECTED. WE WILL SEE IN LESSON 4
   // WHY THIS IS HAPPENING, AND HOW TO SOLVE IT
   cout << recipe1.getAsText ();

   // Create cookie using the recipe
   Cookie chocolateCookie ( "Chocolate cookie", &recipe1 );

   // TRY DOING THE SAME WITH OBJECTS IN DYNAMIC MEMORY




   // This can not be done if we do not provide a default constructor for
   // Cookie
   // Cookie c[10];

//   Cookie c1;
//   Cookie c2 ( "Chocolate cookie", 3 );
//
//   Cookie* pC1 = nullptr;
//
//   try
//   {
//      pC1 = new Cookie ( "testCookie", true, -3, 4 );
//   }
//   catch ( std::string& e )
//   {
//      cout << e << endl;
//   }
//
//   Cookie c3 ( "Vanilla cookie", true, 100, 4 );
//   Cookie c4 ( c1 );
//   Cookie c5 = c2;
//   c5.setCalories (0)
//     .setGlutenFree ( true )
//     .setName ( "myCookie" );
//
//   try
//   {
//      ( c2 + "vanilla" ) + "chocolate";
//   }
//   catch ( std::string& e )
//   {
//
//   }
   return 0;
}

