#ifndef	AForm_HPP
#define	AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
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
		AForm(void);
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& src);
		~AForm(void);

		AForm&	operator=(const AForm& dest);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		beSigned(const Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& out, const AForm& b);

#endif