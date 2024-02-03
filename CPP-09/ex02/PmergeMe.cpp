#include "PmergeMe.hpp"

//	private:
PmergeMe::PmergeMe(const PmergeMe& src) : _cList() { *this = src; }
PmergeMe&	PmergeMe::operator=(const PmergeMe& dest) {
	if (this == &dest)
		return *this;
	return *this;
}

void	PmergeMe::swap(std::list<int>::iterator& a, std::list<int>::iterator& b) {
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

//	public:
PmergeMe::PmergeMe(void) : _cList() {}
PmergeMe::~PmergeMe(void) {}

void	PmergeMe::printContainer(void) const {
	std::list<int>::const_iterator	it;

	for (it = this->_cList.begin(); it != this->_cList.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::parseInput(std::string str) {
	std::stringstream	ss(str);
	int					value;
	char				buffer;

	while (!ss.eof()) {
		buffer = ss.peek();
		if (isdigit(buffer)) {
			ss >> value;
			if (ss.fail())
				throw InvalidStringStreamException();
			this->_cList.push_back(value);
		} else if (buffer == '-') {
			ss.ignore();
			if (isdigit(ss.peek())) {
					ss >> value;
					value *= -1;
				if (ss.fail())
					throw InvalidStringStreamException();
				this->_cList.push_back(value);
			}
		} else {
			throw BadInputException();
		}
	}
}

void	PmergeMe::insertionSort(void) {
	if (this->_cList.size() < 2)
		return;
	
	std::list<int>::iterator	it;
	std::list<int>::iterator	second;

	for (it = this->_cList.begin(); it != this->_cList.end(); ++it) {
		second = it;
		while (second != this->_cList.begin() && *it < *(--second)) {
			swap(it, second);
			--it;
		}
	}
}
