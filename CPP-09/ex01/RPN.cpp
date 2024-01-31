#include "RPN.hpp"

RPN::RPN(void) : _cStack() {}
RPN::RPN(const RPN& src) : _cStack() { *this = src; }
RPN::~RPN(void) {}
RPN&	RPN::operator=(const RPN& dest) {
	if (this == &dest)
		return *this;
	this->_cStack = dest._cStack;
	return *this;
}

bool	RPN::isSign(const char current) const {
	return ((current == '-')
		|| (current == '+')
		|| (current == '*')
		|| (current == '/'));
}

void	RPN::execute(const char sign) {
	int	nbrTmp;

	if (this->_cStack.size() < 2)
		return;

	nbrTmp = this->_cStack.top();
	this->_cStack.pop();
	if (sign == '+')
		nbrTmp = this->_cStack.top() + nbrTmp;
	else if (sign == '-')
		nbrTmp = this->_cStack.top() - nbrTmp;
	else if (sign == '*')
		nbrTmp = this->_cStack.top() * nbrTmp;
	else {
		if (!nbrTmp)
			throw DivideByZeroException();
		nbrTmp = this->_cStack.top() / nbrTmp;
	}
	this->_cStack.pop();
	this->_cStack.push(nbrTmp);
}

RPN::RPN(const std::string str) {
	std::stringstream	ss(str);
	char				peekBuf, sign;
	int					nbr;

	while (!ss.eof()) {
		peekBuf = ss.peek();
		if (isspace(peekBuf)) {
			ss.ignore();
			peekBuf = ss.peek();
		} else if (isdigit(peekBuf)) {
			ss >> nbr;
			if (ss.fail())
				throw ErrorStringStreamException();
			this->_cStack.push(nbr);
		} else if (isSign(peekBuf)) {
			ss.ignore();
			if ((peekBuf == '-' && isdigit(ss.peek())) || (peekBuf == '+' && isdigit(ss.peek()))) {
				ss >> nbr;
				if (ss.fail())
					throw ErrorStringStreamException();
				nbr *= -1;
				if (!isspace(ss.peek()))
					throw BadInputException();
				this->_cStack.push(nbr);
			} else {
				sign = peekBuf;
				execute(sign);
			}
		} else {
			throw BadInputException();
		}
		if (ss.fail())
			throw ErrorStringStreamException();
		ss.peek();
	}
	while (!this->_cStack.empty()) {
		std::cout << this->_cStack.top() << std::endl;
		this->_cStack.pop();
	}
}