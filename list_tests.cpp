/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:15:44 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/08 10:58:42 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>


template < typename T >
void print_list(ft::list<T> &lst, char const *label)
{
	std::cout << "\nft::list Size: " << lst.size();
	std::cout << "\nlist [" << label <<"] contains:";
	if (!lst.size())
		std::cout << "\tnothing";
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
	
	// swap()
	{
		std::cout << "\nswap()" << std::endl;
		std::cout << "=======================================" << std::endl;
		// ft::list
		ft::list<int> first (3, 100) ;   // three ints with a value of 100
		ft::list<int> second (5,200);  // five ints with a value of 200


		print_list(first, "first");
		print_list(second, "second");

		first.swap(second);

		print_list(first, "first");
		print_list(second, "second");

		// std::list 
		std::list<int> stdfirst (3, 100) ;   // three ints with a value of 100
		std::list<int> stdsecond (5,200);  // five ints with a value of 200


		print_list(stdfirst, "stdfirst");
		print_list(stdsecond, "stdsecond");

		stdfirst.swap(stdsecond);

		print_list(stdfirst, "stdfirst");
		print_list(stdsecond, "stdsecond");
		std::cout << "=======================================" << std::endl;
	}

	// resize()
	{
		std::cout << "\nresize()" << std::endl;
		std::cout << "=======================================" << std::endl;
		ft::list<int> mylist;

		// set some initial content:
		for (int i = 1; i < 10; ++i)
			mylist.push_back(i);

		print_list(mylist, "mylist");
		mylist.resize(5);
		print_list(mylist, "mylist");
		mylist.resize(8, 100);
		print_list(mylist, "mylist");
		mylist.resize(12);
		print_list(mylist, "mylist");

		std::list<int> list;

		// set some initial content:
		for (int i = 1; i < 10; ++i)
			list.push_back(i);

		print_list(list, "list");
		list.resize(5);
		print_list(list, "list");
		list.resize(8, 100);
		print_list(list, "list");
		list.resize(12);
		print_list(list, "list");
		std::cout << "=======================================" << std::endl;
	}	
	

	// splice()
	{
		
		std::cout << "\nsplice()" << std::endl;
		std::cout << "=======================================" << std::endl;
		// ft::list
		ft::list<int> mylist1, mylist2;
		ft::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4 0

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		print_list(mylist1, "mylist1");
		print_list(mylist2, "mylist2");

		it = mylist1.begin();
		++it;                         // points to 2

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
										// mylist2 (empty)
										// "it" still points to 2 (the 5th element)
		print_list(mylist1, "mylist1");
		print_list(mylist2, "mylist2");
												
		mylist2.splice (mylist2.begin(),mylist1, it);
										// mylist1: 1 10 20 30 3 4
										// mylist2: 2
										// "it" is now invalid.
		print_list(mylist1, "mylist1");
		print_list(mylist2, "mylist2");
		
		it = mylist1.begin();
		++it; ++it; ++it;           // "it" points now to 30
		
		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
		mylist2.splice(mylist2.begin(), mylist1);
										// mylist1: 30 3 4 1 10 20
		print_list(mylist1, "mylist1");
		print_list(mylist2, "mylist2");

		// std::list
		std::list<int> stdlist1, stdlist2;
		std::list<int>::iterator std_it;

		// set some instd_itial values:
		for (int i=1; i<=4; ++i)
			stdlist1.push_back(i);      // stdlist1: 1 2 3 4 0

		for (int i=1; i<=3; ++i)
			stdlist2.push_back(i*10);   // stdlist2: 10 20 30

		print_list(stdlist1, "stdlist1");
		print_list(stdlist2, "stdlist2");

		std_it = stdlist1.begin();
		++std_it;                         // points to 2

		stdlist1.splice (std_it, stdlist2); // stdlist1: 1 10 20 30 2 3 4
										// stdlist2 (empty)
										// "std_it" still points to 2 (the 5th element)
		print_list(stdlist1, "stdlist1");
		print_list(stdlist2, "stdlist2");
												
		stdlist2.splice (stdlist2.begin(),stdlist1, std_it);
										// stdlist1: 1 10 20 30 3 4
										// stdlist2: 2
										// "std_it" is now invalid.
		print_list(stdlist1, "stdlist1");
		print_list(stdlist2, "stdlist2");
		
		std_it = stdlist1.begin();
		++std_it; ++std_it; ++std_it;           // "std_it" points now to 30
		
		stdlist1.splice ( stdlist1.begin(), stdlist1, std_it, stdlist1.end());
		stdlist2.splice(stdlist2.begin(), stdlist1);
										// stdlist1: 30 3 4 1 10 20
		print_list(stdlist1, "mylist1");
		print_list(stdlist2, "stdlist2");
		std::cout << "=======================================" << std::endl;
	}

	return 0;
}

// // function()
// {
// 	std::cout << "\nfunction()" << std::endl;
// 	std::cout << "=======================================" << std::endl;
	
// 	std::cout << "=======================================" << std::endl;
// }