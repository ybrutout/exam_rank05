#pragma once 

# include <iostream>
# include <string>

# include "ASpell.hpp"

class Fireball: public ASpell{
	public:
		Fireball(): ASpell("Fireball", "burnt to a crisp")
		{}

		ASpell			*clone(void)const
		{
			return (new Fireball());
		}

};