#pragma once 

# include <iostream>
# include <string>
# include <vector>

# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"

class Warlock{
	private:
		std::string				_name;
		std::string				_title;
		SpellBook				_book;
		
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
			_book.learnSpell(spell);
		}

		void			forgetSpell(std::string spell)
		{
			_book.forgetSpell(spell);
		}

		void			launchSpell(std::string spell, ATarget const &target)const
		{
			ASpell		*tmp = _book.createSpell(spell);
			if (tmp)
			{
				tmp->launch(target);
			}
		}

};
