
#include "Heritage.hpp"


Base::Base(){
	this->_name = "default_B1";
	std::cout << "Base - Default constructor : " << this->_name << std::endl;
}

Base::Base(std::string name)
{
	this->_name = name;
	std::cout << "Base - parametric constructor : " << this->_name << std::endl;
}

Base::~Base(){
	std::cout << "Base - Destructor : " << this->_name << std::endl;
}
