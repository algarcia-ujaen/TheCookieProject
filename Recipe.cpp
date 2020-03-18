
#include <new>
#include <sstream>

#include "Recipe.h"
#include "ActionInRecipe.h"
#include "IngredientInRecipe.h"

Recipe::Recipe ()
{  for ( int i = 0; i < MAX_COMPONENTS; i++ )
   {  _components[i] = nullptr;
   }
}


Recipe::Recipe ( const Recipe& orig ): _nComponents ( orig._nComponents )
{  // We are going to solve it in a WRONG way. We will talk about this in
   // lesson 4
   for ( int i = 0; i < _nComponents; i++ )
   {  _components[i] = new RecipeComponent ( *orig._components[i] );
   }

   for ( int i = _nComponents; i < MAX_COMPONENTS; i++ )
   {  _components[i] = nullptr;
   }
}


Recipe::~Recipe ( )
{  for ( int i = 0; i < _nComponents; i++ )
   {  delete _components[i];
      _components[i] = nullptr;
   }
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


Recipe& Recipe::addIngredient ( Ingredient& ing, float amount, std::string modifier )
{  // Check that we have a pointer available for the new ingredient
   if ( _nComponents >= MAX_COMPONENTS )
   {  throw std::string ( "Recipe::addIngredient : no room for the new ingredient!" );
   }

   _components [ _nComponents ] = new IngredientInRecipe ( ing, amount, modifier );
   _nComponents++;

   // Returns the reference (just in case)
   return *this;
}

Recipe& Recipe::addAction ( std::string description, std::string modifier )
{  // Check that we have a pointer available for the new ingredient
   if ( _nComponents >= MAX_COMPONENTS )
   {  throw std::string ( "Recipe::addAction : no room for the new action!" );
   }

   _components [ _nComponents ] = new ActionInRecipe ( description, modifier );
   _nComponents++;

   // Returns the reference (just in case)
   return *this;
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
   {  // Delete the ingredients that were previously stored in this recipe
      // Copy the ingredients from the other Recipe
      // Copy the rest of the attributes
   }

   return *this;
}

std::string Recipe::getAsText ( )
{
   std::stringstream aux;

   for ( int i = 0; i < _nComponents; i++ )
   {
      aux << _components[i]->toText () << std::endl;
   }

   return aux.str ();
}
