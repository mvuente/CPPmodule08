#include <iostream>
#include <list>
#include "mutantstack.hpp"

void listchecker(std::list<int> mylisti)
{
	mylisti.push_back(5);
	mylisti.push_back(17);
	std::cout << mylisti.back() << std::endl;
	mylisti.pop_back();
	std::cout << mylisti.size() << std::endl;
	mylisti.push_back(3);
	mylisti.push_back(5);
	mylisti.push_back(737);
	std::list<int>::reverse_iterator itr = mylisti.rbegin();
	std::cout << "Mylist int reverse begin now is: " << *itr << std::endl;
	std::cout << "\n";
	std::list<int>::reverse_iterator itre = mylisti.rend();
	while (itr != itre)
	{
		std::cout << "Reverse moving; current value is: " << *itr << std::endl;
		++itr;
	}
	//std::cout << "MutantStack reverse end now is: " << *itre << std::endl;

	mylisti.push_back(0);
	std::list<int>::iterator it = mylisti.begin();
	std::cout << "MutantStack begin now is: " << *it << std::endl;
	std::list<int>::iterator ite = mylisti.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Direct moving; current value is: " << *it << std::endl;
		++it;
	}
}

int main()
{
	std::list<int>				mylisti;
	MutantStack<int> 			mstack;
	MutantStack<std::string>	mystacks;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	MutantStack<int>::reverse_iterator itr = mstack.rbegin();
	std::cout << "MutantStack reverse begin now is: " << *itr << std::endl;
	std::cout << "\n";
	MutantStack<int>::reverse_iterator itre = mstack.rend();
	while (itr != itre)
	{
		std::cout << "Reverse moving; current value is: " << *itr << std::endl;
		++itr;
	}
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "MutantStack begin now is: " << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Direct moving; current value is: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\nMutant top from the stack is           " << s.top() << std::endl;
	std::cout << "Mutant top from the mutant is          " << mstack.top() << "\n" << std::endl;

	mystacks.push("mama");
	mystacks.push("myla");
	mystacks.push("ramu");
	MutantStack<std::string>::iterator its = mystacks.begin();
	MutantStack<std::string>::iterator ites = mystacks.end();
	while (its != ites)
	{
		std::cout << "STD::STRING        " << *its << std::endl;
		++its;
	}
	std::cout << "end of Mystack" << std::endl;

	listchecker(mylisti);
	return 0;
}
