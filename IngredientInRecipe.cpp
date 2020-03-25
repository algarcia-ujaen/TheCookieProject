/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   IngredientInRecipe.cpp
 * Author: algarcia
 *
 * Created on 11 de marzo de 2020, 10:08
 */

#include "IngredientInRecipe.h"
#include <sstream>

IngredientInRecipe::IngredientInRecipe ( Ingredient& i, float am,
                                         std::string modifier ): RecipeComponent (),
                                                                 _amount ( am ),
                                                                 _ingredient ( &i )
{
   setModifier ( modifier );
}

IngredientInRecipe::IngredientInRecipe ( const IngredientInRecipe& orig ): RecipeComponent ( orig ),
                                                                           _amount ( orig._amount ),
                                                                           _ingredient ( orig._ingredient )
{ }

IngredientInRecipe::~IngredientInRecipe ( )
{
   _ingredient = nullptr;
}

float IngredientInRecipe::getAmount ( ) const
{  return _amount;
}

Ingredient* IngredientInRecipe::getIngredient ( )
{  return _ingredient;
}

IngredientInRecipe& IngredientInRecipe::setAmount ( float a )
{  _amount = a;
   return *this;
}

IngredientInRecipe& IngredientInRecipe::setIngredient ( Ingredient& i )
{  _ingredient = &i;
   return *this;
}

std::string IngredientInRecipe::toText ( )
{
   std::stringstream aux;
   aux << "Use " << _amount << " of " << getModifier ()
       << " " << _ingredient->getName ();
   return aux.str ();
}

IngredientInRecipe& IngredientInRecipe::operator= ( const IngredientInRecipe& other )
{
   if ( this != &other )
   {
      _ingredient = other._ingredient;
      _amount = other._amount;

      RecipeComponent::operator = ( other );
   }

   return *this;
}



