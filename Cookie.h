/**
 * @file Cookie.h
 * Declaration of the Cookie class
 *
 * @author algarcia
 * @date February 12, 2020, 9:59
 */

#ifndef COOKIE_H
#define COOKIE_H

#include <string>

/**
 * @brief Cookie example class for the 2019-2020 academic year
 * 
 * Objects of this class represent cookies like the ones that we can buy in a
 * supermarket
 */
class Cookie
{
   private:
      std::string _name = "";     ///< Name of the cookie
      bool _glutenFree = false;   ///< If true, the cookie is gluten free
      float _calories = 0;        ///< Amount of calories per 100g
      int _ingredientsSize = 0;   ///< Capacity for ingredient names
      int _nIngredients = 0;      ///< Number of ingredient names actually stored
      std::string* _ingredients = nullptr;   ///< Address of memory block with ingredient names
   public:
      Cookie() = default;
      Cookie ( const std::string newName, bool isGF, float cals, int nI );
      Cookie ( const std::string newName, int nI );
      Cookie ( const Cookie& orig );
      virtual ~Cookie ();
      Cookie& setCalories ( float calories );
      float getCalories () const;
      Cookie& setGlutenFree ( bool glutenFree );
      bool isGlutenFree () const;
      Cookie& setName ( const std::string& name );
      std::string getName () const;
      Cookie& addIngredient ( const std::string& ing );
      Cookie& operator+ ( const std::string& ing );
      bool operator== ( const Cookie& other );
};

#endif /* COOKIE_H */

