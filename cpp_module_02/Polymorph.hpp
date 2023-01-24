#pragma once 

# include <iostream>
# include <string>

# include "ASpell.hpp"

class Polymorph: public ASpell{
	public:
		Polymorph(): ASpell("Polymorph", "turned into a critter")
		{}

		ASpell			*clone(void)const
		{
			return (new Polymorph());
		}

};
