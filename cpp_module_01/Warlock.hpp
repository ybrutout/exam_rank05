#pragma once 

# include <iostream>
# include <string>
# include <vector>

# include "ASpell.hpp"
# include "ATarget.hpp"

class Warlock{
	private:
		std::string				_name;
		std::string				_title;
		std::vector<ASpell*>	_book;
		
		Warlock()
		{}

		Warlock(Warlock const &other): _name(other._name), _title(other._title)
		{}

		Warlock			*operator=(Warlock const & other)
		{
			return this;
		}

	public:
		Warlock(std::string name, std::string title): _name(name), _title(title)
		{
			std::cout << this->_name << ": This looks like another boring day." << std::endl;
		}

		virtual ~Warlock()
		{
			std::cout << this->_name << ": My job here is done!" << std::endl;
			std::vector<ASpell*>::iterator	ite = _book.end();
			for(std::vector<ASpell*>::iterator it = _book.begin(); it != ite; it++)
			{
				delete *it;
			}
			_book.clear();

		}

		std::string		getName(void)const
		{
			return this->_name;
		}

		std::string		getTitle(void)const
		{
			return this->_title;
		}

		void			setTitle(std::string const title)
		{
			this->_title = title;
		}

		void			introduce()const
		{	
			std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
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

		void			forgetSpell(std::string spell)
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

		void			launchSpell(std::string spell, ATarget const &target)const
		{
			std::vector<ASpell*>::const_iterator	ite = _book.end();
			for(std::vector<ASpell*>::const_iterator it = _book.begin(); it != ite; it++)
			{
				if ((*it)->getName() == spell)
				{
					(*it)->launch(target);
					return ;
				}
			}
		}

};
