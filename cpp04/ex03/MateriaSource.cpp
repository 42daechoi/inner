#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
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

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = rhs.inventory[i];
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria *materia)
{
	int i;

	for (i = 0; i < 4; i++)
		if (inventory[i] == NULL)
			break ;
	if (i == 4) 
		std::cout << "Inventory is full" << std::endl;
	else
		inventory[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria *temp = NULL;

	for (int i = 0; i < 4; i++) {
		if (type == inventory[i]->getType()) {	
			temp = inventory[i]->clone();
			break ;
		}
	}
	return (temp);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */