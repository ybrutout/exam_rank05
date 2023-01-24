#pragma once 

#include <iostream>
#include <string>

class ATarget;

class ASpell{
	private:
		std::string		_name;
		std::string		_effects;
	public:
		ASpell(std::string name, std::string effects): _name(name), _effects(effects)
		{}

		ASpell()
		{}

		ASpell(ASpell const &other)
		{
			this->_name = other._name;
			this->_effects = other._effects;
		}

		virtual ~ASpell()
		{}

		ASpell			*operator=(ASpell const &other)
		{
			this->_name = other._name;
			this->_effects = other._effects;
			return this;
		}

		std::string		getName(void)const
		{
			return this->_name;
		}

		std::string		getEffects(void)const
		{
			return this->_effects;
		}

		virtual ASpell			*clone(void)const = 0;

		void			launch(ATarget const &target)const;
};

# include "ATarget.hpp"
