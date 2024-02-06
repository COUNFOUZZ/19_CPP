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

void	PmergeMe::merge(std::list<int>& list, std::list<int>& left, std::list<int>& right) {
	std::list<int>::iterator	itLeft = left.begin();
	std::list<int>::iterator	itRight = right.begin();
	
	printContainer(left);
	printContainer(right);
	while (itLeft != left.end() && itRight != right.end())
		*itLeft > *itRight ? list.push_back(*itRight++) : list.push_back(*itLeft++);
	while (itLeft != left.end())
		list.push_back(*itLeft++);
	while (itRight != right.end())
		list.push_back(*itRight++);
}

void	PmergeMe::mergeSortHanling(std::list<int>& list) {
	if (list.size() <= SIZE_ARRAY) {
		insertionSort(list);
		return;
	}
	std::list<int>				left, right;
	std::list<int>::iterator	middle = list.begin();
	
	std::advance(middle, list.size() / 2);
	left.assign(list.begin(), middle);
	right.assign(middle, list.end());
	mergeSortHanling(left);
	mergeSortHanling(right);
	list.clear();
	merge(list, left, right);
}

void	PmergeMe::sort(void) {
	mergeSortHanling(this->_cList);
	printContainer(this->_cList);
}

//	Getters
std::list<int>&	PmergeMe::getList(void) {
	return this->_cList;
}

std::vector<int>&	PmergeMe::getVector(void) {
	return this->_cVec;
}