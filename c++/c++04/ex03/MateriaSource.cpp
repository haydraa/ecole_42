#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void): _NumberLearned(0)
{
	for (int i = 0; i < MateriaSource::_MateriasSize; i++)
		this->_Materias[i] = NULL;
	std::cout << "Default constructor for MateriaSource called" << std::endl;
	return;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << "Copy constructor for MateriaSource called" << std::endl;
	*this = src;
	return;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < MateriaSource::_MateriasSize; i++)
	{
		if (this->_Materias[i])
			delete this->_Materias[i];
	}
	std::cout << "Destructor for MateriaSource called" << std::endl;
	return;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs)
{
	for (int i = 0; i < MateriaSource::_MateriasSize; i++)
	{
		if (this->_Materias[i])
			delete this->_Materias[i];
		if (rhs._Materias[i])
			this->_Materias[i] = rhs._Materias[i]->Clone();
		else
			this->_Materias[i] = NULL;
	}
	std::cout << "Assignement operator for MateriaSource called" << std::endl;
	return *this;
}

void		MateriaSource::LearnMateria(AMateria *MateriaToLearn)
{
	if (this->_NumberLearned >= MateriaSource::_MateriasSize)
		std::cout << "Can't learn any more materias" << std::endl;
	else
	{
		this->_Materias[this->_NumberLearned] = MateriaToLearn;
		this->_NumberLearned++;
		std::cout << "Learned " << MateriaToLearn->GetType() << " Materia"
			<< std::endl;
	}
}

AMateria	*MateriaSource::CreateMateria(std::string const & type)
{
	for (int i = 0; i < MateriaSource::_Materias_Size && this->_Materias[i]; i++)
	{
		if (type == this->_Materias[i]->GetType())
			return this->_Materias[i]->Clone();
	}
	return NULL;
}

void		MateriaSource::PrintMaterias( void ) const
{
	for (int i = 0; i < MateriaSource::_MateriasSize; i++)
	{
		if (this->_Materias[i])
			std::cout << i << ": " << this->_Materias[i]->GetType() << std::endl;
		else
			std::cout << i << ": Empty" << std::endl;
	}
}
