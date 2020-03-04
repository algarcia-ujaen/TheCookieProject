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

#include "Recipe.h"

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
      Recipe* _myRecipe = nullptr;   ///< This attribute links the cookie with its recipe
   public:
//      Cookie() = default;
      Cookie ( const std::string newName, bool isGF, float cals, Recipe* recipe );
      Cookie ( const std::string newName, Recipe* recipe );
      Cookie ( const Cookie& orig );
      virtual ~Cookie ();
      Cookie& setCalories ( float calories );
      float getCalories () const;
      Cookie& setGlutenFree ( bool glutenFree );
      bool isGlutenFree () const;
      Cookie& setName ( const std::string& name );
      std::string getName () const;
      Recipe* getRecipe ();
      bool operator== ( const Cookie& other );
      Cookie& operator= ( const Cookie& other );
};

#endif /* COOKIE_H */

