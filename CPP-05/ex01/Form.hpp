#ifndef	FORM_HPP
#define	FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		class GradeTooHighException : public std::exception {
			public:
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char*	what() const throw();
		};

	public:
		Form(void);
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form& src);
		~Form(void);

		Form&	operator=(const Form& dest);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		beSigned(const Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& out, const Form& b);

#endif