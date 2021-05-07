/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:15:44 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/07 02:42:47 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>

template < typename T >
void print_list(ft::list<T> &lst, char const *label)
{
	std::cout << "\nft::list Size: " << lst.size();
	std::cout << "\nlist [" << label <<"] contains:";
	for (typename ft::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << "\t[ " << *it << " ]";
	}
	std::cout << std::endl;
}

template < typename T >
void print_list(std::list<T> &ls, char const *label)
{
	std::cout << "\nstd::list Size: " << ls.size();
	std::cout << "\nlist [" << label <<"] contains:";
	for (typename std::list<int>::iterator it = ls.begin(); it != ls.end(); ++it)
	{
		std::cout << "\t[ " << *it << " ]";
	}
	std::cout << std::endl;
}


int main(void)
{
	// front() and back()
	{	
		std::cout << "\nfront() & back()" << std::endl;
		std::cout << "=======================================" << std::endl;
		ft::list<int> mylist;
		std::list<int> list;

		mylist.push_back(77);
		mylist.push_back(22);
		
		list.push_back(77);
		list.push_back(22);
		// now front equals 77, and back 22
		
		mylist.front() -= mylist.back();
		list.front() -= list.back();
		
		std::cout << "mylist.front() is now " << mylist.front() << '\n';
		std::cout << "list.front() is now " << list.front() << '\n';
		std::cout << "=======================================" << std::endl;
	}
	
	// assign()
	{
		std::cout << "\nassign()" << std::endl;
		std::cout << "=======================================" << std::endl;
		ft::list<int> first;
		ft::list<int> second;
		std::list<int> stdfirst;
		std::list<int> stdsecond;

		first.assign (7,100);                      // 7 ints with value 100
		stdfirst.assign (7,100);                      // 7 ints with value 100

		second.assign (first.begin(),first.end()); // a copy of first
		stdsecond.assign (stdfirst.begin(),stdfirst.end()); // a copy of first
		print_list(first, "first");
		print_list(stdfirst, "stdfirst");
		print_list(second, "second");
		print_list(stdsecond, "stdsecond");

		ft::list<int> lst(3);
		std::list<int> ls(3);
		first.assign (lst.begin(),lst.end());
		stdfirst.assign (ls.begin(),ls.end());
		print_list(first, "first");
		print_list(stdfirst, "stdfirst");

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';

		std::cout << "Size of first: " << int (stdfirst.size()) << '\n';
		std::cout << "Size of second: " << int (stdsecond.size()) << '\n';
		std::cout << "=======================================" << std::endl;
	}

	// push_front()
	{
		std::cout << "\npush_front()" << std::endl;
		std::cout << "=======================================" << std::endl;
		ft::list<int> mylist (2,100);         // two ints with a value of 100
		std::list<int> list (2,100);         // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);
		list.push_front (200);
		list.push_front (300);

		print_list(list, "list");
		print_list(list, "mylist");
		std::cout << "=======================================" << std::endl;
	}


	// insert()
	{
		std::cout << "\ninsert()" << std::endl;
		std::cout << "=======================================" << std::endl;
		std::list<int> list;
		std::list<int>::iterator it;
		ft::list<int> mylist;
		ft::list<int>::iterator ite;

		// set some initial values:
		for (int i=1; i<=5; ++i) 
		{
			list.push_back(i); // 1 2 3 4 5
			mylist.push_back(i); // 1 2 3 4 5
		}
		it = list.begin();
		ite = mylist.begin();
		++it;       // it points now to number 2           ^
		++ite;       // it points now to number 2           ^

		print_list(list, "list");
		print_list(mylist, "mylist");

		list.insert (it,10);                        // 1 10 2 3 4 5
		mylist.insert (ite,10);                        // 1 10 2 3 4 5

		// "it" still points to number 2                      ^
		mylist.insert (ite,2,20);                      // 1 10 20 20 2 3 4 5
		list.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

		--it;       // it points now to the second 20            ^
		--ite;       // it points now to the second 20            ^

		std::list<int> tmp (2,30);
		ft::list<int> mytmp (2,30);
		print_list(mytmp, "mytmp");
		list.insert (it,tmp.begin(),tmp.end());
		mylist.insert (ite,mytmp.begin(),mytmp.end());
														// 1 10 20 30 30 20 2 3 4 5
														//               ^
		print_list(list, "list");
		print_list(mylist, "mylist");
		std::cout << "=======================================" << std::endl;
	}	


	// erase()
	{
		std::cout << "\nerase()" << std::endl;
		std::cout << "=======================================" << std::endl;
		// ft::list
		ft::list<int> mylist;
		ft::list<int>::iterator it1,it2;

		// set some values:
		for (int i=1; i<10; ++i)
			mylist.push_back(i*10);

														// 10 20 30 40 50 60 70 80 90
		it1 = it2 = mylist.begin(); 					// ^^
		for (size_t i = 0; i < 6; i++, it2++);          // ^                 ^
		++it1;                      					//    ^              ^

		it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
									//    ^           ^

		it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
									//    ^           ^

		++it1;                      //       ^        ^
		--it2;                      //       ^     ^

		mylist.erase (it1,it2);     // 10 30 60 80 90
									//        ^

		print_list(mylist, "mylist");
		// std::list
		std::list<int> list;
		std::list<int>::iterator sit1,sit2;

		// set some values:
		for (int i=1; i<10; ++i)
			list.push_back(i*10);

														// 10 20 30 40 50 60 70 80 90
		sit1 = sit2 = list.begin(); 					// ^^
		for (size_t i = 0; i < 6; i++, sit2++);         // ^                 ^
		++sit1;                      					//    ^              ^

		sit1 = list.erase (sit1);   // 10 30 40 50 60 70 80 90
									//    ^           ^

		sit2 = list.erase (sit2);   // 10 30 40 50 60 80 90
									//    ^           ^

		++sit1;                     //       ^        ^
		--sit2;                     //       ^     ^

		list.erase (sit1,sit2);     // 10 30 60 80 90
									//        ^
		print_list(list, "list");
		std::cout << "=======================================" << std::endl;
	}
	
	return 0;
}
