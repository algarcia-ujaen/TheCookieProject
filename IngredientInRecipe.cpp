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

IngredientInRecipe::IngredientInRecipe ( Ingredient& i, float am ): _amount ( am ),
                                                                    _ingredient ( &i )
{ }

IngredientInRecipe::IngredientInRecipe ( const IngredientInRecipe& orig ): _amount ( orig._amount ),
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
{   _amount = a;
}

IngredientInRecipe& IngredientInRecipe::setIngredient ( Ingredient& i )
{  _ingredient = &i;
}





