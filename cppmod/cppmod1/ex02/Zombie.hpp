#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name, std::string type);
		void	advert();
	private:
		std::string	nom;
		std::string type;
		std::string	sound;
};


#endif