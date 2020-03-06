
#include <new>

#include "Recipe.h"

Recipe::Recipe ()
{  for ( int i = 0; i < MAX_INGREDIENTS; i++ )
   {  _ingredients[i] = nullptr;
   }
}


Recipe::Recipe ( const Recipe& orig ): _nIngredients ( orig._nIngredients )
{  for ( int i = 0; i < MAX_INGREDIENTS; i++ )
   {  _ingredients[i] = orig._ingredients[i];
   }
}


Recipe::~Recipe ( )
{  for ( int i = 0; i < _nIngredients; i++ )
   {  _ingredients[i] = nullptr;
   }
}


Recipe& Recipe::operator+= ( Ingredient& ing )
{  // Check that we have a pointer available for the new ingredient
   if ( _nIngredients >= MAX_INGREDIENTS )
   {  throw std::string ( "Recipe::operator+= : no room for the new ingredient!" );
   }

   _ingredients [ _nIngredients ] = &ing;
   _nIngredients++;

   // Returns the reference (just in case)
   return *this;
}


// Alternative version: passing a pointer as parameter
//Recipe& Recipe::operator+= ( Ingredient* ing )
//{  // Check that we have a pointer available for the new ingredient
//   if ( _nIngredients < MAX_INGREDIENTS )
//   {  _ingredients [ _nIngredients ] = ing;
//      _nIngredients++;
//   }
//
//   // Returns the reference (just in case)
//   return *this;
//}


Recipe& Recipe::addIngredient ( Ingredient& ing )
{  return this->operator+= ( ing );
}


bool Recipe::operator== ( const Recipe& other )
{  // Sets a default return value
   bool retVal = true;

   // Checks whether the object is the same as the "other"
   if ( &other != this )
   {  // Checks the criteria one by one. If one of them fails, the return value
      // is changed, but no "else" section is added to the conditionals

      // How should be done???

      retVal = false;
   }

   // Returns the return value
   return retVal;
}


Recipe& Recipe::operator= ( const Recipe& other )
{  if ( this != &other )
   {  // Copy the ingredients from the other Recipe
      // Copy the rest of the attributes
   }

   return *this;
}