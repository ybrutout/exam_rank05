#pragma once

# include <iostream>
# include <string>
# include <vector>

# include "ASpell.hpp"

class SpellBook{
	private:
		SpellBook(SpellBook const &other)
		{}

		SpellBook				*operator=(SpellBook const &other)
		{
			return this;
		}

		std::vector<ASpell*>	_book;

	public:
		SpellBook()
		{}

		virtual~SpellBook()
		{
			std::vector<ASpell*>::iterator	ite = _book.end();
			for(std::vector<ASpell*>::iterator it = _book.begin(); it != ite; it++)
			{
				delete *it;
			}
			_book.clear();
		}

		void			learnSpell(ASpell *const spell)
		{
			if (spell)
			{
				std::vector<ASpell*>::iterator	ite = _book.end();
				for(std::vector<ASpell*>::iterator it = _book.begin(); it != ite; it++)
				{
					if ((*it)->getName() == spell->getName())
						return;
				}
				_book.push_back(spell->clone());
			}
		}

		void			forgetSpell(std::string const spell)
		{
			std::vector<ASpell*>::iterator	ite = _book.end();
			for(std::vector<ASpell*>::iterator it = _book.begin(); it != ite; it++)
			{
				if ((*it)->getName() == spell)
				{
					delete *it;
					_book.erase(it);
					return;
				}
			}
		}

		ASpell			*createSpell(std::string const &spell)const
		{
			std::vector<ASpell*>::const_iterator	ite = _book.end();
			for(std::vector<ASpell*>::const_iterator it = _book.begin(); it != ite; it++)
			{
				if ((*it)->getName() == spell)
					return (*it)->clone();
			}
			return NULL;
		}
};
