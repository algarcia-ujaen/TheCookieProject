
#include <new>

#include "Recipe.h"

Recipe::Recipe ( int nI ) try : _ingredientsSize ( nI )
{  if ( nI <= 0 )
   {  throw std::string ( "A recipe has to have some ingredients!" );
   }

   _ingredients = new std::string [ nI ];

   for ( int i = 0; i < nI; i++ )
   {  _ingredients[i] = "";
   }
}
catch ( std::bad_alloc& e )
{  throw std::string ( "Recipe::Recipe: can not allocate memory" );
}
catch ( std::string& e )
{  throw std::string ( "Recipe::Recipe: can not create recipe -> " + e );
}


Recipe::Recipe ( const Recipe& orig ) try : _ingredientsSize ( orig._ingredientsSize ),
                                            _nIngredients ( orig._nIngredients )
{  _ingredients = new std::string [_ingredientsSize];

   for ( int i = 0; i < _ingredientsSize; i++ )
   {  _ingredients[i] = orig._ingredients[i];
   }
}
catch ( std::bad_alloc& e )
{  throw std::string ( "Recipe::Recipe: Can not allocate space for the "
                       "ingredients of the copy" );
}


Recipe::~Recipe ( )
{  if ( _ingredients != nullptr )
   {  delete [] _ingredients;
      _ingredients = nullptr;
   }
}


Recipe& Recipe::operator+= ( const std::string& ing )
{  // Ideally: there is room for the new ingredient
   if ( _nIngredients < _ingredientsSize )
   {  _ingredients [ _nIngredients ] = ing;
      _nIngredients++;
      return *this;
   }

   // In case there is no room for the new ingredient, it is a bit more
   // complicated:

   // Declares a pointer for the new block
   std::string* newPtr = nullptr;
   try
   {  // Allocates the memory block
      newPtr = new std::string [ _nIngredients + 1 ];
   }
   catch ( std::bad_alloc& e )
   {  throw std::string ( "Recipe::operator+ failed at allocating a memory block" );
   }

   // Copies the values from the old block to the new one
   for ( int i = 0; i < _nIngredients; i++ )
   {  newPtr[i] = _ingredients[i];
   }

   // Adds the new value to the new block
   newPtr[_nIngredients] = ing;

   // Frees the old block
   delete [] _ingredients;

   // Assigns the address of the new block to the pointer attribute
   _ingredients = newPtr;
   newPtr = nullptr;

   // Increments the size of the block
   _nIngredients++;

   // Returns the reference (just in case)
   return *this;
}


Recipe& Recipe::addIngredient ( const std::string& ing )
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
   {  // Delete the old ingredients
      // Allocate a new block for the ingredients
      // Copy the ingredients from the other Recipe
      // Copy the rest of the attributes
   }

   return *this;
}