#include "iter.hpp"

//	Template
template<typename Tprint>
void	print(Tprint toPrint) {
	std::cout << toPrint << std::endl;
}

//	Function
void	fctIncrement(int& toAdd) {
	++toAdd;
}

void	fctDecremente(int& toDecrement) {
	--toDecrement;
}

//	Class
class RandomClass {
	private:
		int	_length;
		int _tab[10];

	public:
		 RandomClass(void) : _length(10) {
			for(int i = 0; i < this->_length; ++i)
				this->_tab[i] = i + 100;
		 }
		 RandomClass(const RandomClass& toCopy) : _length(toCopy._length) { *this = toCopy; }

		 RandomClass&	operator=(const RandomClass& dest) {
			if (this == &dest || this->_length < dest._length)
				return *this;
			for (int i = 0; i < dest._length; ++i)
				this->_tab[i] = dest._tab[i];
			return *this;
		 }

		void	printTab(void) const	{ iter(this->_tab, this->_length, &print); }
		void	add(void) 				{ iter(this->_tab, this->_length, &fctIncrement); }
		void	decrease(void)			{ iter(this->_tab, this->_length, &fctDecremente); }
};

int main(void) {
	RandomClass	obj;
	int tab[] = { 19, 10, 20 };

	iter(tab, 3, &print);
	std::cout << std::endl;
	iter(tab, 3, &fctIncrement);
	iter(tab, 3, &print);
	std::cout << std::endl;
	std::cout << "Class part:" << std::endl;
	obj.printTab();
	std::cout << std::endl;
	obj.decrease();
	obj.printTab();

	return 0;
}