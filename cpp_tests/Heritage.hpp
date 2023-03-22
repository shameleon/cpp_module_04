#ifndef DIAMOND_HPP
# define DIAMOND_HPP

# define COL_RED "\033[0;31m"
# define COL_GRN "\033[0;32m"
# define COL_YEL "\033[0;33m"
# define COL_PUR "\033[0;35m"
# define COL_INV_YEL "\033[7;93m"
# define COL_CYA "\033[0;36m"
# define COL_RES "\033[0m"

# include <iostream>
# include <iomanip>

class	Base
{
	protected:
		std::string		_name;
	public:
		Base(void);
		Base(std::string name);
		~Base(void);
};

class	Derived1: public Base
{
	private:
		std::string		_name;
	public:
		Derived1(void);
		Derived1(std::string name);
		~Derived1(void);
};

class	Derived2: public Base
{
	private:
		std::string		_name;
	public:
		Derived2(void);
		Derived2(std::string name);
		~Derived2(void);
};

#endif