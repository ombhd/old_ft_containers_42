/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:15:44 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/17 00:08:11 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <cmath>


#ifndef NS
# define NS ft
#endif

template <typename T>
void print_namespace(ft::vector<T> const &vec)
{
	if (vec.size())
		vec.empty();
	std::cout << "\nNAMESPACE : ft" << std::endl;
}

template <typename T>
void print_namespace(std::vector<T> const &vect)
{
	if (vect.size())
		vect.empty();
	std::cout << "\nNAMESPACE : std" << std::endl;
}

template < typename T >
void print_vect(NS::vector<T> &vect, char const *label)
{
	std::cout << "\nvect Size: " << vect.size();
	std::cout << "\nvect [" << label <<"] contains:";
	if (!vect.size())
		std::cout << "\tnothing";
	for (typename NS::vector<T>::iterator it = vect.begin(); it != vect.end(); ++it)
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


// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }


int main(void)
{
	NS::vector<int> vectGolbal;
	print_namespace(vectGolbal);
	// front() and back()
	{	
		std::cout << "\nfront() & back()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<int> myvect;

		myvect.push_back(77);
		myvect.push_back(22);
		
		// now front equals 77, and back 22
		
		myvect.front() -= myvect.back();
		
		std::cout << "myvect.front() is now " << myvect.front() << '\n';
		std::cout << "=======================================" << std::endl;
	}
	
	// max_size()
	{	
		std::cout << "\nmax_size()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<size_t> myvect;

		myvect.push_back(77);
		myvect.push_back(22);
		
		std::cout << "myvect.max_size() is: " << myvect.max_size() << '\n';
		std::cout << "=======================================" << std::endl;
	}
	
	// assign()
	{
		std::cout << "\nassign()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<int> first;
		NS::vector<int> second;

		first.assign (7,100);                      // 7 ints with value 100

		second.assign (first.begin(),first.end()); // a copy of first
		print_vect(first, "first");
		print_vect(second, "second");

		NS::vector<int> vect(3);
		first.assign (vect.begin(),vect.end());
		print_vect(first, "first");

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		
		std::cout << "=======================================" << std::endl;
	}

	// push_front()
	{
		std::cout << "\npush_front()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<int> myvect (2,100);         // two ints with a value of 100
		myvect.push_front (200);
		myvect.push_front (300);

		print_vect(myvect, "myvect");
		std::cout << "=======================================" << std::endl;
	}


	// insert()
	{
		std::cout << "\ninsert()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<int> myvect;
		NS::vector<int>::iterator ite;

		// set some initial values:
		for (int i=1; i<=5; ++i) 
		{
			myvect.push_back(i); // 1 2 3 4 5
		}
		ite = myvect.begin();
		++ite;       // it points now to number 2           ^

		print_vect(myvect, "myvect");

		myvect.insert (ite,10);                        // 1 10 2 3 4 5

		// "it" still points to number 2                      ^
		myvect.insert (ite,2,20);                      // 1 10 20 20 2 3 4 5

		--ite;       // it points now to the second 20            ^

		std::vector<int> tmp (2,30);
		NS::vector<int> mytmp (2,30);
		print_vect(mytmp, "mytmp");
		myvect.insert (ite,mytmp.begin(),mytmp.end());
														// 1 10 20 30 30 20 2 3 4 5
														//               ^
		print_vect(myvect, "myvect");
		std::cout << "=======================================" << std::endl;
	}	


	// erase()
	{
		std::cout << "\nerase()" << std::endl;
		std::cout << "=======================================" << std::endl;

		NS::vector<int> myvect;
		NS::vector<int>::iterator it1,it2;

		// set some values:
		for (int i=1; i<10; ++i)
			myvect.push_back(i*10);

														// 10 20 30 40 50 60 70 80 90
		it1 = it2 = myvect.begin(); 					// ^^
		for (size_t i = 0; i < 6; i++, it2++);          // ^                 ^
		++it1;                      					//    ^              ^

		it1 = myvect.erase (it1);   // 10 30 40 50 60 70 80 90
									//    ^           ^

		it2 = myvect.erase (it2);   // 10 30 40 50 60 80 90
									//    ^           ^

		++it1;                      //       ^        ^
		--it2;                      //       ^     ^

		myvect.erase (it1,it2);     // 10 30 60 80 90
									//        ^

		print_vect(myvect, "myvect");

		std::cout << "=======================================" << std::endl;
	}
	
	// swap()
	{
		std::cout << "\nswap()" << std::endl;
		std::cout << "=======================================" << std::endl;
		// ft::vector
		NS::vector<int> first (3, 100) ;   // three ints with a value of 100
		NS::vector<int> second (5,200);  // five ints with a value of 200


		print_vect(first, "first");
		print_vect(second, "second");

		first.swap(second);

		print_vect(first, "first");
		print_vect(second, "second");

		std::cout << "=======================================" << std::endl;
	}

	// resize()
	{
		std::cout << "\nresize()" << std::endl;
		std::cout << "=======================================" << std::endl;

		NS::vector<int> myvect;

		// set some initial content:
		for (int i = 1; i < 10; ++i)
			myvect.push_back(i);

		print_vect(myvect, "myvect");
		myvect.resize(5);
		print_vect(myvect, "myvect");
		myvect.resize(8, 100);
		print_vect(myvect, "myvect");
		myvect.resize(12);
		print_vect(myvect, "myvect");

		
		std::cout << "=======================================" << std::endl;
	}	
	
	// splice()
	{
		
		std::cout << "\nsplice()" << std::endl;
		std::cout << "=======================================" << std::endl;
		// ft::vector
		NS::vector<int> myvect1, myvect2;
		NS::vector<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			myvect1.push_back(i);      // myvect1: 1 2 3 4 0

		for (int i=1; i<=3; ++i)
			myvect2.push_back(i*10);   // myvect2: 10 20 30

		print_vect(myvect1, "myvect1");
		print_vect(myvect2, "myvect2");

		it = myvect1.begin();
		++it;                         // points to 2

		myvect1.splice (it, myvect2); // myvect1: 1 10 20 30 2 3 4
										// myvect2 (empty)
										// "it" still points to 2 (the 5th element)
		print_vect(myvect1, "myvect1");
		print_vect(myvect2, "myvect2");
												
		myvect2.splice (myvect2.begin(),myvect1, it);
										// myvect1: 1 10 20 30 3 4
										// myvect2: 2
										// "it" is now invalid.
		print_vect(myvect1, "myvect1");
		print_vect(myvect2, "myvect2");
		
		it = myvect1.begin();
		++it; ++it; ++it;           // "it" points now to 30
		
		myvect1.splice ( myvect1.begin(), myvect1, it, myvect1.end());
		myvect2.splice(myvect2.begin(), myvect1);
										// myvect1: 30 3 4 1 10 20
		print_vect(myvect1, "myvect1");
		print_vect(myvect2, "myvect2");

		std::cout << "=======================================" << std::endl;
	}

	// remove()
	{
		std::cout << "\nremove()" << std::endl;
		std::cout << "=======================================" << std::endl;
		// ft::vector
		NS::vector<int> myvect;
		myvect.push_back(200);
		myvect.push_back(300);
		myvect.resize(5, 100);
		myvect.push_back(400);
		myvect.push_back(500);
		print_vect(myvect, "myvect");
		myvect.remove(100);
		print_vect(myvect, "myvect");

		std::cout << "=======================================" << std::endl;
	}

	// remove_if()
	{
		std::cout << "\nremove_if()" << std::endl;
		std::cout << "=======================================" << std::endl;
		
		// ft::vector
		NS::vector<int> myvect;   
		myvect.push_back(15);
		myvect.push_back(36);
		myvect.push_back(7);
		myvect.push_back(17);
		myvect.push_back(20);
		myvect.push_back(39);
		myvect.push_back(4);
		myvect.push_back(1); // 15 36 7 17 20 39 4 1
		print_vect(myvect, "myvect");

		myvect.remove_if (single_digit);           // 15 36 17 20 39
		print_vect(myvect, "myvect");

		myvect.remove_if (is_odd());               // 36 20
		print_vect(myvect, "myvect");
		std::cout << "=======================================" << std::endl;
	}
		
	// unique() and sort()
	{
		std::cout << "unique() and sort()" << std::endl;
		std::cout << "=======================================" << std::endl;
		
		double mydoubles[]={ 12.15,  2.72, 73.00,  12.77,  3.14, 12.77, 73.35, 72.25, 15.3,  72.25 };
		NS::vector<double> myvect;
		for (size_t i = 0; i < 10; i++)
			myvect.push_back(mydoubles[i]);

		print_vect(myvect, "myvect");

		myvect.sort();	//  2.72,  3.14, 12.15, 12.77, 12.77,
                         // 15.3,  72.25, 72.25, 73.0,  73.35
		print_vect(myvect, "myvect");
		myvect.unique();    //  2.72,  3.14, 12.15, 12.77
                            // 15.3,  72.25, 73.0,  73.35

		print_vect(myvect, "myvect");    
		myvect.unique (same_integral_part);  //  2.72,  3.14, 12.15
											// 15.3,  72.25, 73.0
		print_vect(myvect, "myvect");
											
		myvect.unique (is_near());     
		print_vect(myvect, "myvect");

		std::cout << "=======================================" << std::endl;
	}

	// merge()
	{
		std::cout << "\nmerge()" << std::endl;
		std::cout << "=======================================" << std::endl;
		
		NS::vector<double> first, second;

		first.push_back (3.1);
		first.push_back (2.2);
		first.push_back (2.9);

		second.push_back (3.7);
		second.push_back (7.1);
		second.push_back (1.4);

		first.sort();
		second.sort();
		print_vect(first, "first");
		print_vect(second, "second");
		first.merge(second);
		print_vect(first, "first");
		print_vect(second, "second");
		// (second is now empty)

		second.push_back (2.1);
		print_vect(second, "second");

		first.merge(second,mycomparison);
		print_vect(first, "first");
		print_vect(second, "second");
		std::cout << "=======================================" << std::endl;
	}

	// reverse()
	{
		std::cout << "\nreverse()" << std::endl;
		std::cout << "=======================================" << std::endl;
		
		NS::vector<int> myvect;

		for (int i=1; i<10; ++i) myvect.push_back(i);

		std::cout << "\nBefore reversing : " << std::endl;
		print_vect(myvect, "myvect");
		myvect.reverse();

		std::cout << "\nAfter reversing : " << std::endl;
		print_vect(myvect, "myvect");

		std::cout << "=======================================" << std::endl;
	}

	// relational operators()
	{
		std::cout << "\relational operators" << std::endl;
		std::cout << "=======================================" << std::endl;

		NS::vector<int> a;
		a.push_back(10);
		a.push_back(20);
		a.push_back(30);
		print_vect(a, "a");
		
		NS::vector<int> b = a;
		print_vect(b, "b");
		
		NS::vector<int> c;
		c.push_back(30);
		c.push_back(20);
		c.push_back(10);
		print_vect(c, "c");
		

		if (a==b) std::cout << "\na and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
		std::cout << "=======================================" << std::endl;
	}
	
	// non-member swap()
	{
		std::cout << "\nnon-member swap()" << std::endl;
		std::cout << "=======================================" << std::endl;
		
		NS::vector<int> foo (3,100);   // three ints with a value of 100
		NS::vector<int> bar (5,200);   // five ints with a value of 200

		print_vect(foo, "foo");
		print_vect(bar, "bar");
		NS::swap(foo,bar);
		print_vect(foo, "foo");
		print_vect(bar, "bar");
		
		std::cout << "=======================================" << std::endl;
	}

	// reverse iterators
	{
		std::cout << "\nreverse iterators" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<int> l;
		l.assign(4, 100);
		l.push_back(1);
		l.push_front(2);
		NS::vector<int>::reverse_iterator ite = l.rbegin();
		NS::vector<int>::reverse_iterator it = l.rend();
		for (int i = 0; it != ite; ite++, i++)
		{
			std::cout << "[" << *ite << "]  ";
		}
		std::cout << "\n=======================================" << std::endl;
	}

	return 0;
}

// // function()
// {
// 	std::cout << "\nfunction()" << std::endl;
// 	std::cout << "=======================================" << std::endl;
	

// 	std::cout << "=======================================" << std::endl;
// }