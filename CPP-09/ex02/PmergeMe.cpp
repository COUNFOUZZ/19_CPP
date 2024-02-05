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

// void	PmergeMe::sortList(void) {
// 	std::list<int>::iterator it, second;

// 	for (it = this->_cList.begin(); it != this->_cList.end(); ++it) {
// 		int key = *it;
// 		second = it;
// 		while (second != this->_cList.begin() && key < *(--second)) {
// 			std::iter_swap(it, second);
// 			--it;
// 		}
// 	}
// }

// void	PmergeMe::sortVector(void) {
// 	std::vector<int>::iterator it, second;

// 	for (it = this->_cVec.begin(); it != this->_cVec.end(); ++it) {
// 		int key = *it;
// 		second = it;
// 		while (second != this->_cVec.begin() && key < *(--second)) {
// 			std::iter_swap(it, second);
// 			--it;
// 		}
// 	}
// }

// void	PmergeMe::insertionSort(int listOrVector) {
// 	if (this->_cList.size() < 2)
// 		return;
// 	if (!listOrVector)
// 		sortList();
// 	else if (listOrVector == 1)
// 		sortVector();
// 	else
// 		return;
// }



void	PmergeMe::mergeSortHanling(std::list<int>& list) {
	if (list.size() < 2)
		return;
	std::list<int>				left, right;
	std::list<int>::iterator	middle;
	
	std::advance(middle, list.size() / 2);
	left.assign(list.begin(), middle);
	right.assign(middle, list.end());


	list.clear();
}

void	PmergeMe::mergeSort(void) {
	mergeSortHanling(this->_cList);
}

//	Getters
std::list<int>&	PmergeMe::getList(void) {
	return this->_cList;
}

std::vector<int>&	PmergeMe::getVector(void) {
	return this->_cVec;
}