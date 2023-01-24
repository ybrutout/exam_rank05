#pragma once 

# include <iostream>
# include <string>

# include "ASpell.hpp"

class Fwoosh: public ASpell{
	public:
		Fwoosh(): ASpell("Fwoosh", "fwooshed")
		{}

		ASpell			*clone(void)const
		{
			return (new Fwoosh());
		}

};
