#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character( const Character & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	this->name = rhs.name;
	for (int i = 0; i < 4; i++)
		inventory[i] = rhs.inventory[i];
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m)
{
	int i;

	for (i = 0; i < 4; i++)
		if (inventory[i] == NULL)
			break;
	if (i == 4)
		std::cout << "Inventory is full" << std::endl;
	else
		inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (inventory[idx] == NULL)
		std::cout << idx << " slot is already empty" << std::endl;
	else
	{
		delete inventory[idx];
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		std::cout << "Invaild number" << std::endl;
	else if (inventory[idx] == NULL)
		std::cout << idx << " slot is empty" << std::endl;
	else
		inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const
{
	return (name);
}

/* ************************************************************************** */