
#include "span.hpp"

Span::Span(const unsigned int N) : _N(N)
{
	std::vector<int>	mv;
	this->_myvector = mv;
}

Span::~Span(void)
{}

Span::Span(const Span &cpSpan) : _N(cpSpan._N)
{
	*this = cpSpan;
	return ;
}

Span				&Span::operator=(const Span &cpSpan)
{
	if (this != &cpSpan)
	{
		this->_myvector = cpSpan._myvector;
	}
	return (*this);
}

Span::ArrayIsFullException::ArrayIsFullException()
{
	std::cout << "Impossible operation. The array is full already." << std::endl;
}

Span::TooShortArrayException::TooShortArrayException()
{
	std::cout << "Impossible operation. The array is too short." << std::endl;
}

Span::NullPointerException::NullPointerException()
{
	std::cout << "Impossible operation. Null pointer has been provided." << std::endl;
}

void 				Span::addNumber(int newnum)
{
	if (this->_myvector.size() >= this->_N)
		throw ArrayIsFullException();
	this->_myvector.push_back(newnum);
	std::sort(this->_myvector.begin(), this->_myvector.end());
	return;
}

void 				Span::addNumber(int* newarr, int num)
{
	if (!newarr)
		throw NullPointerException();
	if (num + this->_myvector.size() >= this->_N)
	{
		delete[] newarr;
		throw ArrayIsFullException();
	}
	this->_myvector.insert(this->_myvector.begin(), newarr, newarr + num);
	std::sort(this->_myvector.begin(), this->_myvector.end());
	delete[] newarr;
	return;
}

unsigned int		Span::shortestSpan() const
{
	unsigned int diff;
	unsigned int res = std::numeric_limits<unsigned int>::max();
	if (this->_myvector.size() <= 1)
		throw TooShortArrayException();
	for (unsigned int i = 0; i < this->_myvector.size() - 1; ++i)
	{
		if ((diff = this->_myvector[i + 1] - this->_myvector[i]) < res)
			res = diff;
	}

	return (res);
}

unsigned int		Span::longestSpan() const
{
	if (this->_myvector.size() <= 1)
		throw TooShortArrayException();
	return (*std::max_element(this->_myvector.begin(), this->_myvector.end()) -
			*std::min_element(this->_myvector.begin(), this->_myvector.end()));
}

std::vector<int>*	Span::getVector()
{
	return &this->_myvector;
}