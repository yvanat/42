#include "Zombie.hpp"

Zombie::Zombie(std::string nom, std::string type)
{
	this->nom = nom;
	this->type = type;
	sound = "Braiiiiiiinnnssss ...";
}

void	Zombie::advert()
{
	std::cout << "<" << this->nom << " (" << this->type << ")> " << sound << std::endl;
}

void	Zombie::announce()
{
	std::cout << "Hi I'm " << this->nom << std::endl;
}