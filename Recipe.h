
#ifndef RECIPE_H
#define RECIPE_H

#include "Ingredient.h"

#define MAX_INGREDIENTS 10

class Recipe
{  private:
      int _nIngredients = 0;      ///< Number of ingredient names actually stored
      Ingredient* _ingredients[MAX_INGREDIENTS];   ///< Pointers to ingredients
   public:
      Recipe ( );
      Recipe ( const Recipe& orig );
      virtual ~Recipe ( );
      Recipe& addIngredient ( Ingredient& ing );
      Recipe& operator+= ( Ingredient& ing );
      bool operator== ( const Recipe& other );
      Recipe& operator= ( const Recipe& other );
};

#endif /* RECIPE_H */

