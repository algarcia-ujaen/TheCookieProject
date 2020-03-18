
#ifndef RECIPE_H
#define RECIPE_H

#include "RecipeComponent.h"
#include "Ingredient.h"

#define MAX_COMPONENTS 10

class Recipe
{  private:
      int _nComponents = 0;      ///< Number of ingredient names actually stored
      RecipeComponent* _components[MAX_COMPONENTS];   ///< Pointers to ingredients
   public:
      Recipe ( );
      Recipe ( const Recipe& orig );
      virtual ~Recipe ( );
      Recipe& addIngredient ( Ingredient& ing, float amount, std::string modifier );
      Recipe& addAction ( std::string description, std::string modifier );
      bool operator== ( const Recipe& other );
      Recipe& operator= ( const Recipe& other );
      std::string getAsText ();
};

#endif /* RECIPE_H */

