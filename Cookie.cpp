/**
 * @file Cookie.cpp
 * Implementation of the Cookie class methods
 *
 * @author algarcia
 * @date February 12, 2020, 9:59
 */

#include <new>

#include "Cookie.h"

/**
 * @brief Completely parameterized constructor
 *
 * Initializes every attribute with the parameters or the default values
 * @param newName Name of the cookie
 * @param isGF Is it gluten free?
 * @param cals Number of calories per 100g
 * @param nI Number of ingredients
 * @post Memory is allocated for the number of ingredients given. Every
 *       ingredient is initialized to an empty string
 * @throw std::bad_alloc If it has not been possible to allocate a memory block
 *        for the ingredients
 * @throw std::string If the value of cals or nI is less than or equal to 0
 */
Cookie::Cookie ( const std::string newName, bool isGF,
                 float cals, int nI ) try : _name ( newName ), _glutenFree ( isGF ),
                                            _calories ( cals ), _ingredientsSize ( nI )
{
   if ( cals <= 0 )
   {
      throw std::string ( "The calories can not be less than 0" );
   }

   if ( nI <= 0 )
   {
      throw std::string ( "Number of ingredients can not be less than 0" );
   }

   _ingredients = new std::string[nI];
}
catch ( std::string& e )
{
   throw std::string ( "Cookie::Cookie: Error creating the cookie ->" + e );
}

Cookie::Cookie ( const std::string newName, int nI ): _name ( newName ),
                                                      _ingredientsSize ( nI )
{
   if ( nI <= 0 )
   {
      throw std::string ( "Number of ingredients can not be less than 0" );
   }

   _ingredients = new std::string[nI];
}

Cookie::Cookie ( const Cookie& orig ): _name ( orig._name ),
                                       _glutenFree ( orig._glutenFree ),
                                       _calories ( orig._calories ),
                                       _nIngredients ( orig._nIngredients ),
                                       _ingredientsSize ( orig._ingredientsSize )
{
   _ingredients = new std::string[_ingredientsSize];

   for ( int i = 0; i < _nIngredients; i++ )
   {
      _ingredients[i] = orig._ingredients[i];
   }
}

Cookie::~Cookie ( )
{
   if ( _ingredients != nullptr )
   {
      delete [] _ingredients;
      _ingredients = nullptr;
   }
}

Cookie& Cookie::setCalories ( float calories )
{
   this->_calories = calories;
   return *this;
}

float Cookie::getCalories ( ) const
{
   return _calories;
}

Cookie& Cookie::setGlutenFree ( bool glutenFree )
{
   this->_glutenFree = glutenFree;
   return *this;
}

bool Cookie::isGlutenFree ( ) const
{
   return _glutenFree;
}

Cookie& Cookie::setName ( const std::string& name )
{
   this->_name = name;
   return *this;
}

std::string Cookie::getName ( ) const
{
   return _name;
}

Cookie& Cookie::operator+ ( const std::string& ing )
{
   if ( _nIngredients < _ingredientsSize )
   {
      _ingredients[_nIngredients] = ing;
      _nIngredients++;
      return *this;
   }

   // Declares a pointer for the new block
   std::string* newPtr = nullptr;
   try
   {
      // Allocates the memory block
      newPtr = new std::string [ _nIngredients + 1 ];
   }
   catch ( std::bad_alloc& e )
   {
      throw std::string ( "Cookie::operator+ failed at allocating a memory block" );
   }

   // Copies the values from the old block to the new one
   for ( int i = 0; i < _nIngredients; i++ )
   {
      newPtr[i] = _ingredients[i];
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

bool Cookie::operator== ( const Cookie& other )
{
   // Sets a default return value
   bool retVal = true;

   // Checks whether the object is the same as the "other"
   if ( &other != this )
   {
      // Checks the criteria one by one. If one of them fails, the return value
      // is changed, but no "else" section is added to the conditionals
      if ( this->_name != other._name )
      {
         retVal = false;
      }

      if ( this->_calories != other._calories )
      {
         retVal = false;
      }

   }

   // Returns the return value
   return retVal;
}
