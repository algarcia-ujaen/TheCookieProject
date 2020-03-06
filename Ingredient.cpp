/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Ingredient.cpp
 * Author: algarcia
 *
 * Created on 5 de marzo de 2020, 11:51
 */

#include "Ingredient.h"

Ingredient::Ingredient ( const Ingredient& orig ): _name ( orig._name )
{ }

Ingredient::~Ingredient ( )
{ }

Ingredient& Ingredient::setName ( const std::string& newName )
{  _name = newName;
}

std::string Ingredient::getName ( ) const
{  return _name;
}



