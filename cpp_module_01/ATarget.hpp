#pragma once 

#include <iostream>
#include <string>

class ASpell;

class ATarget{
	private:
		std::string		_type;
	public:
		ATarget(std::string type): _type(type)
		{}

		ATarget()
		{}

		ATarget(ATarget const &other)
		{
			this->_type = other._type;
		}

		virtual ~ATarget()
		{}

		ATarget			*operator=(ATarget const &other)
		{
			this->_type = other._type;
			return this;
		}

		std::string		getType(void)const
		{
			return this->_type;
		}

		virtual ATarget			*clone(void)const = 0;

		void			getHitBySpell(ASpell const &spell)const;
};

# include "ASpell.hpp"
