#ifndef	MATERIASOURCE_HPP
#define	MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class	MateriaSource : public	IMateriaSource {
	private:
		AMateria*	_materias[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const& other);
		~MateriaSource(void);

		MateriaSource&	operator=(MateriaSource const& dest);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

#endif