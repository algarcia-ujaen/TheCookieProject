#ifndef INGREDIENTINRECIPE_H
#define INGREDIENTINRECIPE_H

#include "Ingredient.h"
#include "RecipeComponent.h"

class IngredientInRecipe: public RecipeComponent
{
 public:
   IngredientInRecipe ( ) = default;
   IngredientInRecipe ( Ingredient& i, float am, std::string modifier );
   IngredientInRecipe ( const IngredientInRecipe& orig );
   virtual ~IngredientInRecipe ( );
   IngredientInRecipe& setAmount ( float a );
   IngredientInRecipe& setIngredient ( Ingredient& i );
   float getAmount () const;
   Ingredient* getIngredient ();
   std::string toText ();
   
   IngredientInRecipe& operator= ( const IngredientInRecipe& other );
 private:
   Ingredient* _ingredient = nullptr;
   float _amount = 0;
} ;

#endif /* INGREDIENTINRECIPE_H */

