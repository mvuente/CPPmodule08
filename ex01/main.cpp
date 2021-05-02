#include <iostream>
#include "span.hpp"
#include <cstdlib>

int		randomiser(void)
{
	int res = rand();
	int tmp = rand()%3;
	if (!tmp)
		res = -res;
	return res;
}

void	arrcrtr(int** arr)
{
	for (unsigned int i = 0; i < 9998; ++i)
		(*arr)[i] = randomiser();
}

int main()
{
	int 		a = 2;
	int* 		ptr = &a;
	size_t 		r = (size_t)ptr;
	srand(static_cast<int>(r));

	Span 		sp = Span(10000);
	try
	{
		//int*	nullarr(NULL);
		//sp.addNumber(nullarr, 5);
		sp.addNumber(randomiser());
		std::cout << "Vector size now is " << sp.getVector()->size() << std::endl;
		//std::cout << sp.shortestSpan() << std::endl;
		//std::cout << sp.longestSpan() << std::endl;
		int* 	arr = new int[9998];
		arrcrtr(&arr);
		sp.addNumber(arr, 9998);
		std::cout << "Vector size now is " << sp.getVector()->size() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(randomiser());
		std::cout << "Vector size now is " << sp.getVector()->size() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		//sp.addNumber(randomiser());
	}
	catch (std::exception &e)
	{}
	return 0;
}
