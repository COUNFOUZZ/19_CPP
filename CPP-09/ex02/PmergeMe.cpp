#include "PmergeMe.hpp"

//	private:
PmergeMe::PmergeMe(const PmergeMe& src) : _cList(), _cVec() { *this = src; }
PmergeMe&	PmergeMe::operator=(const PmergeMe& dest) {
	if (this == &dest)
		return *this;
	this->_cList = dest._cList;
	this->_cVec = dest._cVec;
	return *this;
}

void	PmergeMe::swap(std::list<int>::iterator& a, std::list<int>::iterator& b) {
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

//	public:
PmergeMe::PmergeMe(void) : _cList(), _cVec() {}
PmergeMe::~PmergeMe(void) {}

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
			this->_cVec.push_back(value);
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

void	PmergeMe::mergeSort(void) {
	if (this->_cList.size() < 2)
		return;
	
}

//	Getters
const std::list<int>	PmergeMe::getList(void) const {
	return this->_cList;
}

const std::vector<int>	PmergeMe::getVector(void) const {
	return this->_cVec;
}