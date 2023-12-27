#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class	Cure : public	AMateria {
    public:
		Cure(void);
		Cure(Cure const& other);
		~Cure(void);

		Cure&	operator=(Cure const& dest);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif