#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <set>

std::map<int,int> create_map()
{
	std::map<int,int> m;
	m[0] = 2;
	m[1] = 4;
	m[2] = 6;
	m[3] = 2;
	return m;
}

int main()
{
	int 				myints[] = { 10, 20, 30, 20, 50 };
	std::vector<int> 	myvector (myints,myints+5);
	std::list<int> 		mylist;
	mylist.push_back(-5);
	mylist.push_back(10);
	mylist.push_back(35);
	mylist.push_back(-5);
	std::deque<int>		mydeque;
	mydeque.push_back(-100);
	mydeque.push_back(-300);
	mydeque.push_back(-400);
	mydeque.push_back(-400);
	std::set<int>		myset (myints, myints + 3);
	std::map<int,int>	mymap = create_map();

	try
	{
		std::cout << "20 is " << easyfind(myvector, 20) - myvector.begin()	<< "'th member in the vector container." << std::endl;
		//std::cout << "100 is " << easyfind(myvector, 100)  - myvector.begin() << "'th member in the container." << std::endl;
		std::cout << "I've found " << *easyfind(mylist, -5) << " in the list container." << std::endl;
		//std::cout << "I've found " << *easyfind(mylist, -100)<< " in the container." << std::endl;
		std::cout << "-400 is " << easyfind(mydeque, -400) - mydeque.begin() << "'th member in the deque container." << std::endl;
		//std::cout << "0 is " << easyfind(mydeque, 0) - mydeque.begin() << "'th member in the container." << std::endl;
		std::cout << "I've found " << *easyfind(myset, 10) << " in the set container." << std::endl;
		//std::cout << "I've found " << *easyfind(myset, 0)<< " in the container." << std::endl;
		std::cout << "2 is " << easyfind(mymap, 2)	<< "'th member in the map container." << std::endl;
		std::cout << "200 is " << easyfind(mymap, 200)	<< "'th member in the container." << std::endl;
	}
	catch (std::exception &e)
	{}
	return 0;
}
