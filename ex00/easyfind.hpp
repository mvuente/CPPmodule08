
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <exception>
#include <map>

class NoNumberException : public std::exception
{
public:
	NoNumberException()
	{
		std::cout << "  ... No! I hadn't found." << std::endl;
	}
};

template< class Tc>
typename Tc::iterator	easyfind(Tc & cont, int num)
{
	typename Tc::iterator 		it;

	it = find(cont.begin(), cont.end(), num);
	if (it != cont.end())
		return (it);
	throw NoNumberException();
}

int						easyfind(std::map<int, int> & cont, int num)
{
	std::pair<int, int> 		highest = *cont.rbegin();
	std::map<int,int>::iterator it = cont.begin();

	while (cont.value_comp()(*it, highest))
	{
		if (it->second == num)
			return it->first;
		it++;
	}
	throw NoNumberException();
}

#endif
