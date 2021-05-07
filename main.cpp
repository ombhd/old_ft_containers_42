/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:38:16 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/07 16:39:40 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>

template <typename T>
void print_list(ft::list<T> &lst, char const *label)
{
	std::cout << "\nft::list Size: " << lst.size();
	std::cout << "\nlist [" << label << "] contains:";
	if (!lst.size())
		std::cout << "\tnothing";
	for (typename ft::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << "\t[ " << *it << " ]";
	}
	std::cout << std::endl;
}

template <typename T>
void print_list(std::list<T> &ls, char const *label)
{
	std::cout << "\nstd::list Size: " << ls.size();
	std::cout << "\nlist [" << label << "] contains:";
	if (!ls.size())
		std::cout << "\tnothing";
	for (typename std::list<int>::iterator it = ls.begin(); it != ls.end(); ++it)
	{
		std::cout << "\t[ " << *it << " ]";
	}
	std::cout << std::endl;
}

int main(void)
{
	// splice()
	{
		ft::list<int> mylist1, mylist2;
		ft::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
										// mylist2 (empty)
										// "it" still points to 2 (the 5th element)
												
		mylist2.splice (mylist2.begin(),mylist1, it);
										// mylist1: 1 10 20 30 3 4
										// mylist2: 2
										// "it" is now invalid.
		it = mylist1.begin();
		++it; ++it; ++it;           // "it" points now to 30

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
										// mylist1: 30 3 4 1 10 20

		std::cout << "mylist1 contains:";
		for (it=mylist1.begin(); it!=mylist1.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "mylist2 contains:";
		for (it=mylist2.begin(); it!=mylist2.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	return 0;
}
