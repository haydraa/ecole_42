#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource &src );
		~MateriaSource( void );

		MateriaSource	&operator=( const MateriaSource &other );

		virtual void		LearnMateria(AMateria *MateriaToLearn);
		virtual AMateria	*CreateMateria(std::string const & type);

		void			PrintMaterias( void ) const ;

	private:
		const static int	MateriasSize = 4;

		AMateria		*_Materias[MateriaSource::MateriasSize];
		int			_NumberLearned;
};

#endif

