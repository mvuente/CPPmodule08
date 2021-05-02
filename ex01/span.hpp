
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
private:
	const unsigned int	_N;
	std::vector<int>	_myvector;
	Span();
public:
	Span(const unsigned int N);
	~Span(void);
	Span(const Span &cpSpan);
	Span					&operator=(const Span &cpSpan);
	void					addNumber(int newnum);
	void					addNumber(int* newarr, int num);
	unsigned int			shortestSpan() const;
	unsigned int			longestSpan() const;
	std::vector<int>*		getVector();
	class ArrayIsFullException : public std::exception
	{
	public:
		ArrayIsFullException();
	};
	class TooShortArrayException : public std::exception
	{
	public:
		TooShortArrayException();
	};
	class NullPointerException : public std::exception
	{
		public:
		NullPointerException();
	};
};

#endif
