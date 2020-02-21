/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cookie.h
 * Author: algarcia
 *
 * Created on 12 de febrero de 2020, 9:59
 */

#ifndef COOKIE_H
#define COOKIE_H

#include <string>

class Cookie
{
   private:
      std::string _name = "";
      bool _glutenFree = false;
      float _calories = 0;
      int _ingredientsSize = 0;
      int _nIngredients = 0;
      std::string* _ingredients = nullptr;
   public:
      Cookie() = default;
      Cookie ( const std::string newName, bool isGF, float cals, int nI );
      Cookie ( const std::string newName, int nI );
      Cookie(const Cookie& orig);
      virtual ~Cookie();
      Cookie& setCalories(float calories);
      float getCalories() const;
      Cookie& setGlutenFree(bool glutenFree);
      bool isGlutenFree() const;
      Cookie& setName(std::string name);
      std::string getName() const;
      Cookie& addIngredient ( const std::string& ing );
      Cookie& operator+ ( const std::string& ing );
      bool operator== ( const Cookie& other );
};

#endif /* COOKIE_H */

