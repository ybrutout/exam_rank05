#pragma once 

# include <iostream>
# include <string>

# include "ATarget.hpp"

class Dummy: public ATarget{
	public:
		Dummy(): ATarget("Target Practice Dummy")
		{}

		ATarget			*clone(void)const
		{
			return (new Dummy());
		}

};
