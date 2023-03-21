
#include "Heritage.hpp"


Derived1::Derived1(){
	this->_name = "default_D1";
	std::cout << "Derived1 - Default constructor : " << this->_name << std::endl;
}

Derived1::Derived1(std::string name){
	this->_name = name;
	std::cout << "Derived1 - parametric constructor : " << this->_name << std::endl;
}

Derived1::~Derived1(void){
	std::cout << "Derived1 - Destructor : " << this->_name << std::endl;
}
