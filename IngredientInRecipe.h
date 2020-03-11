#ifndef INGREDIENTINRECIPE_H
#define INGREDIENTINRECIPE_H

#include "Ingredient.h"

class IngredientInRecipe
{
 public:
   IngredientInRecipe ( ) = default;
   IngredientInRecipe ( Ingredient& i, float am );
   IngredientInRecipe ( const IngredientInRecipe& orig );
   virtual ~IngredientInRecipe ( );
   IngredientInRecipe& setAmount ( float a );
   IngredientInRecipe& setIngredient ( Ingredient& i );
   float getAmount () const;
   Ingredient* getIngredient ();
 private:
   Ingredient* _ingredient = nullptr;
   float _amount = 0;
} ;

#endif /* INGREDIENTINRECIPE_H */

