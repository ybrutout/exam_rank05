#pragma once 

# include <iostream>
# include <string>

# include "ATarget.hpp"

class BrickWall: public ATarget{
	public:
		BrickWall(): ATarget("Inconspicuous Red-brick Wall")
		{}

		ATarget			*clone(void)const
		{
			return (new BrickWall());
		}

};
