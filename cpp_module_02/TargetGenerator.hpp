#pragma once

# include <iostream>
# include <string>
# include <vector>

# include "ATarget.hpp"

class TargetGenerator{
	private:
		TargetGenerator(TargetGenerator const &other)
		{}

		TargetGenerator				*operator=(TargetGenerator const &other)
		{
			return this;
		}

		std::vector<ATarget*>	_bookTarget;

	public:
		TargetGenerator()
		{}

		virtual~TargetGenerator()
		{
			std::vector<ATarget*>::iterator	ite = _bookTarget.end();
			for(std::vector<ATarget*>::iterator it = _bookTarget.begin(); it != ite; it++)
			{
				delete *it;
			}
			_bookTarget.clear();
		}

		void			learnTargetType(ATarget *const target)
		{
			if (target)
			{
				std::vector<ATarget*>::iterator	ite = _bookTarget.end();
				for(std::vector<ATarget*>::iterator it = _bookTarget.begin(); it != ite; it++)
				{
					if ((*it)->getType() == target->getType())
						return;
				}
				_bookTarget.push_back(target->clone());
			}
		}

		void			forgetTargetType(std::string const target)
		{
			std::vector<ATarget*>::iterator	ite = _bookTarget.end();
			for(std::vector<ATarget*>::iterator it = _bookTarget.begin(); it != ite; it++)
			{
				if ((*it)->getType() == target)
				{
					delete *it;
					_bookTarget.erase(it);
					return;
				}
			}
		}

		ATarget			*createTarget(std::string const &target)const
		{
			std::vector<ATarget*>::const_iterator	ite = _bookTarget.end();
			for(std::vector<ATarget*>::const_iterator it = _bookTarget.begin(); it != ite; it++)
			{
				if ((*it)->getType() == target)
					return (*it)->clone();
			}
			return NULL;
		}
};
