#include "ActionInRecipe.h"
#include <sstream>

ActionInRecipe::ActionInRecipe ( const ActionInRecipe& orig ): RecipeComponent (orig),
                                                               _description ( orig._description )
{ }

ActionInRecipe::ActionInRecipe ( std::string description,
                                 std::string modifier ): RecipeComponent (),
                                                         _description ( description )
{
   setModifier ( modifier );
}


ActionInRecipe::~ActionInRecipe ( ) { }

ActionInRecipe& ActionInRecipe::setDescription ( std::string description )
{
   this->_description = description;
   return *this;
}

std::string ActionInRecipe::getDescription ( ) const
{
   return _description;
}

std::string ActionInRecipe::toText ( )
{
   std::stringstream aux;
   aux << _description << " " << getModifier ();
   return aux.str ();
}

ActionInRecipe& ActionInRecipe::operator = ( const ActionInRecipe& other )
{
   if ( this != &other )
   {
      _description = other._description;
      
      RecipeComponent::operator = ( other );
   }

   return *this;
}
