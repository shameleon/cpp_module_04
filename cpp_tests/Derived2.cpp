
#include "Heritage.hpp"


Derived2::Derived2(){
	this->_name = "default_D2";
	std::cout << "Derived2 - Default constructor : " << this->_name << std::endl;
}

Derived2::Derived2(std::string name){
	this->_name = name;
	std::cout << "Derived2 - parametric constructor : " << this->_name << std::endl;
}

Derived2::~Derived2(){
	std::cout << "Derived2 - Destructor : " << this->_name << std::endl;
}
