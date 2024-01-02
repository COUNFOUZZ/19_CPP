#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat {
	private:
		class GradeTooHighException : public std::exception {
			public:
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char*	what() const throw();
		};
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);

		Bureaucrat&	operator=(const Bureaucrat& dest);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		promote(void);
		void		demote(void);
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b);


#endif