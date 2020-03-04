
#ifndef RECIPE_H
#define RECIPE_H

#include <string>

class Recipe
{  private:
      int _ingredientsSize = 0;   ///< Capacity for ingredient names
      int _nIngredients = 0;      ///< Number of ingredient names actually stored
      std::string* _ingredients = nullptr;   ///< Address of memory block with ingredient names
   public:
      Recipe ( ) = default;
      Recipe ( int nI );
      Recipe ( const Recipe& orig );
      virtual ~Recipe ( );
      Recipe& addIngredient ( const std::string& ing );
      Recipe& operator+= ( const std::string& ing );
      bool operator== ( const Recipe& other );
      Recipe& operator= ( const Recipe& other );
};

#endif /* RECIPE_H */

