#ifndef	AForm_HPP
#define	AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
	protected:
		std::string	_target;
		void		checkForm(const Bureaucrat& executor) const;

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
		class NotSignedException : public std::exception {
			public:
				const char*	what() const throw();
		};

	public:
		AForm(void);
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute, const std::string target);
		AForm(const AForm& src);
		virtual ~AForm(void);

		AForm&	operator=(const AForm& dest);

		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		void			beSigned(const Bureaucrat& b);
		virtual void	execute(const Bureaucrat& executor) const = 0;
};

std::ostream&	operator<<(std::ostream& out, const AForm& b);

#endif