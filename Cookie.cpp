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
 * @param cals Amount of calories per 100g
 * @param recipe Memory address of a Recipe object that contains the recipe for
 *               the cookie
 * @throw std::string If the value of cals or nI is less than or equal to 0, or
 *                    no recipe is given (i.e. recipe is nullptr)
 */
Cookie::Cookie ( const std::string newName, bool isGF,
                 float cals, Recipe* recipe ) try : _name ( newName ), _glutenFree ( isGF ),
                                            _calories ( cals ), _myRecipe ( recipe )
{  if ( cals <= 0 )
   {  throw std::string ( "The calories can not be less than 0" );
   }

   if ( recipe == nullptr )
   {  throw std::string ( "A cookie can not be created without a recipe" );
   }
}
catch ( std::string& e )
{  throw std::string ( "Cookie::Cookie: Error creating the cookie ->" + e );
}


Cookie::Cookie ( const std::string newName, Recipe* recipe ): _name ( newName ),
                                                              _myRecipe ( recipe )
{  if ( recipe == nullptr )
   {  throw std::string ( "A cookie can not be created without a recipe" );
   }
}


Cookie::Cookie ( const Cookie& orig ): _name ( orig._name ),
                                       _glutenFree ( orig._glutenFree ),
                                       _calories ( orig._calories ),
                                       _myRecipe ( orig._myRecipe )
{ }


Cookie::~Cookie ( )
{  _myRecipe = nullptr;
}


Cookie& Cookie::setCalories ( float calories )
{  this->_calories = calories;
   return *this;
}


float Cookie::getCalories ( ) const
{  return _calories;
}


Cookie& Cookie::setGlutenFree ( bool glutenFree )
{  this->_glutenFree = glutenFree;
   return *this;
}


bool Cookie::isGlutenFree ( ) const
{  return _glutenFree;
}


Cookie& Cookie::setName ( const std::string& name )
{  this->_name = name;
   return *this;
}

std::string Cookie::getName ( ) const
{  return _name;
}


Recipe* Cookie::getRecipe ()
{  return _myRecipe;
}


bool Cookie::operator == ( const Cookie& other )
{
   bool retVal = true;

   if ( this != &other )
   {  if ( _name != other._name )
      {  retVal = false;
      }

      if ( _glutenFree != other._glutenFree )
      {  retVal = false;
      }

      if ( _calories != other._calories )
      {  retVal = false;
      }

      // What happens with _myRecipe????
   }

   return retVal;
}


Cookie& Cookie::operator = ( const Cookie& other )
{  if ( this != &other )
   {  _name = other._name;
      _glutenFree = other._glutenFree;
      _calories = other._calories;
      _myRecipe = other._myRecipe;
   }
}