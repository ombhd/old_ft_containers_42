/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:15:44 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/08 16:08:04 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <cmath>


#ifndef NS
# define NS ft
#endif

template <typename T>
void print_namespcae(ft::list<T> const &l)
{
	if (l.size())
		l.empty();
	std::cout << "\nNAMESPACE : ft" << std::endl;
}

template <typename T>
void print_namespcae(std::list<T> const &l)
{
	if (l.size())
		l.front();
	std::cout << "\nNAMESPACE : std" << std::endl;
}

template < typename T >
void print_list(NS::list<T> &lst, char const *label)
{
	std::cout << "\nlist Size: " << lst.size();
	std::cout << "\nlist [" << label <<"] contains:";
	if (!lst.size())
		std::cout << "\tnothing";
	for (typename NS::list<T>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << "  [ " << *it << " ]";
	}
	std::cout << std::endl;
}


// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

int main(void)
{
	NS::list<int> l;
	print_namespcae(l);
	// front() and back()
	{	
		std::cout << "\nfront() & back()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::list<int> mylist;

		mylist.push_back(77);
		mylist.push_back(22);
		
		// now front equals 77, and back 22
		
		mylist.front() -= mylist.back();
		
		std::cout << "mylist.front() is now " << mylist.front() << '\n';
		std::cout << "=======================================" << std::endl;
	}
	
	// assign()
	{
		std::cout << "\nassign()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::list<int> first;
		NS::list<int> second;

		first.assign (7,100);                      // 7 ints with value 100

		second.assign (first.begin(),first.end()); // a copy of first
		print_list(first, "first");
		print_list(second, "second");

		NS::list<int> lst(3);
		first.assign (lst.begin(),lst.end());
		print_list(first, "first");

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		
		std::cout << "=======================================" << std::endl;
	}

	// push_front()
	{
		std::cout << "\npush_front()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::list<int> mylist (2,100);         // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);

		print_list(mylist, "mylist");
		std::cout << "=======================================" << std::endl;
	}


	// insert()
	{
		std::cout << "\ninsert()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::list<int> mylist;
		NS::list<int>::iterator ite;

		// set some initial values:
		for (int i=1; i<=5; ++i) 
		{
			mylist.push_back(i); // 1 2 3 4 5
		}
		ite = mylist.begin();
		++ite;       // it points now to number 2           ^

		print_list(mylist, "mylist");

		mylist.insert (ite,10);                        // 1 10 2 3 4 5

		// "it" still points to number 2                      ^
		mylist.insert (ite,2,20);                      // 1 10 20 20 2 3 4 5

		--ite;       // it points now to the second 20            ^

		std::list<int> tmp (2,30);
		NS::list<int> mytmp (2,30);
		print_list(mytmp, "mytmp");
		mylist.insert (ite,mytmp.begin(),mytmp.end());
														// 1 10 20 30 30 20 2 3 4 5
														//               ^
		print_list(mylist, "mylist");
		std::cout << "=======================================" << std::endl;
	}	


	// erase()
	{
		std::cout << "\nerase()" << std::endl;
		std::cout << "=======================================" << std::endl;

		NS::list<int> mylist;
		NS::list<int>::iterator it1,it2;

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

		std::cout << "=======================================" << std::endl;
	}
	
	// swap()
	{
		std::cout << "\nswap()" << std::endl;
		std::cout << "=======================================" << std::endl;
		// ft::list
		NS::list<int> first (3, 100) ;   // three ints with a value of 100
		NS::list<int> second (5,200);  // five ints with a value of 200


		print_list(first, "first");
		print_list(second, "second");

		first.swap(second);

		print_list(first, "first");
		print_list(second, "second");

		std::cout << "=======================================" << std::endl;
	}

	// resize()
	{
		std::cout << "\nresize()" << std::endl;
		std::cout << "=======================================" << std::endl;

		NS::list<int> mylist;

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

		
		std::cout << "=======================================" << std::endl;
	}	
	

	// splice()
	{
		
		std::cout << "\nsplice()" << std::endl;
		std::cout << "=======================================" << std::endl;
		// ft::list
		NS::list<int> mylist1, mylist2;
		NS::list<int>::iterator it;

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

		std::cout << "=======================================" << std::endl;
	}

	// remove()
	{
		std::cout << "\nremove()" << std::endl;
		std::cout << "=======================================" << std::endl;
		// ft::list
		NS::list<int> mylist;
		mylist.push_back(200);
		mylist.push_back(300);
		mylist.resize(5, 100);
		mylist.push_back(400);
		mylist.push_back(500);
		print_list(mylist, "mylist");
		mylist.remove(100);
		print_list(mylist, "mylist");

		std::cout << "=======================================" << std::endl;
	}

	// remove_if()
	{
		std::cout << "\nremove_if()" << std::endl;
		std::cout << "=======================================" << std::endl;
		
		// ft::list
		NS::list<int> mylist;   
		mylist.push_back(15);
		mylist.push_back(36);
		mylist.push_back(7);
		mylist.push_back(17);
		mylist.push_back(20);
		mylist.push_back(39);
		mylist.push_back(4);
		mylist.push_back(1); // 15 36 7 17 20 39 4 1
		print_list(mylist, "mylist");

		mylist.remove_if (single_digit);           // 15 36 17 20 39
		print_list(mylist, "mylist");

		mylist.remove_if (is_odd());               // 36 20
		print_list(mylist, "mylist");
		std::cout << "=======================================" << std::endl;
	}
		
	// unique() and sort()
	{
		std::cout << "unique() and sort()" << std::endl;
		std::cout << "=======================================" << std::endl;
		
		double mydoubles[]={ 12.15,  2.72, 73.00,  12.77,  3.14, 12.77, 73.35, 72.25, 15.3,  72.25 };
		NS::list<double> mylist;
		for (size_t i = 0; i < 10; i++)
			mylist.push_back(mydoubles[i]);

		print_list(mylist, "mylist");

		mylist.sort();	//  2.72,  3.14, 12.15, 12.77, 12.77,
                         // 15.3,  72.25, 72.25, 73.0,  73.35
		print_list(mylist, "mylist");
		mylist.unique();    //  2.72,  3.14, 12.15, 12.77
                            // 15.3,  72.25, 73.0,  73.35

		print_list(mylist, "mylist");    
		mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
											// 15.3,  72.25, 73.0
		print_list(mylist, "mylist");
											
		mylist.unique (is_near());     
		print_list(mylist, "mylist");

		std::cout << "=======================================" << std::endl;
	}
		
	return 0;
}

// // function()
// {
// 	std::cout << "\nfunction()" << std::endl;
// 	std::cout << "=======================================" << std::endl;
	
// 	// ft::list
	
// 	// std::list

// 	std::cout << "=======================================" << std::endl;
// }