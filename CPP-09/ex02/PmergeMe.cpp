#include "PmergeMe.hpp"

//	private:
PmergeMe::PmergeMe(const PmergeMe& src) : _cList(), _cVec(), timeList(0), timeVector(0) { *this = src; }
PmergeMe&	PmergeMe::operator=(const PmergeMe& dest) {
	if (this == &dest)
		return *this;
	this->_cList = dest._cList;
	this->_cVec = dest._cVec;
	this->timeList = dest.timeList;
	this->timeVector = dest.timeVector;
	return *this;
}

//	public:
PmergeMe::PmergeMe(void) : _cList(), _cVec(), timeList(0), timeVector(0) {}
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
	std::set<int>	checkDouble(this->_cList.begin(), this->_cList.end());
	if (checkDouble.size() != this->_cList.size())
		throw DoubleException();
}

void	PmergeMe::sort(void) {
	timeval	start, end, diff;

	std::cout << "Before: ";
	printContainer(this->_cList);

	gettimeofday(&start, 0);
	mergeSortHanling(this->_cList);
	gettimeofday(&end, 0);
	timersub(&end, &start, &diff);
	this->timeList = (diff.tv_sec * 1000000.0 + diff.tv_usec) / 1000000.0;

	gettimeofday(&start, 0);
	mergeSortHanling(this->_cVec);
	gettimeofday(&end, 0);
	timersub(&end, &start, &diff);
	this->timeVector = (diff.tv_sec * 1000000.0 + diff.tv_usec) / 1000000.0;

	std::cout << "After: ";
	printContainer(this->_cList);

	std::cout << "Time to process a range of " << std::fixed << this->_cList.size() << " elements with list : " << this->timeList << " s" << std::endl;
	std::cout << "Time to process a range of " << std::fixed << this->_cList.size() << " elements with vector : " << this->timeVector << " s" << std::endl;
}

//	Getters
std::list<int>&	PmergeMe::getList(void) {
	return this->_cList;
}

std::vector<int>&	PmergeMe::getVector(void) {
	return this->_cVec;
}