/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ingredient.h
 * Author: algarcia
 *
 * Created on 5 de marzo de 2020, 11:51
 */

#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient
{
   private:
      std::string _name = "";
   public:
      Ingredient ( ) = default;
      Ingredient ( const Ingredient& orig );
      virtual ~Ingredient ( );
      Ingredient& setName ( const std::string& newName );
      std::string getName ( ) const;
} ;

#endif /* INGREDIENT_H */

