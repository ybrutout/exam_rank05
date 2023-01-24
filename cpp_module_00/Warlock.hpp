#pragma once 

# include <iostream>
# include <string>

class Warlock{
	private:
		std::string		_name;
		std::string		_title;
		
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

		~Warlock()
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

};
