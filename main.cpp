/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:38:16 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/15 18:48:45 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.hpp"
// #include "./list.hpp"
#include <list>
#include <cmath>
#include <iostream>
#include <string>
#include <exception>


template <typename T>
void print_list(ft::list<T> &lst, char const *label)
{
	std::cout << "\nft::list Size: " << lst.size();
	std::cout << "\nlist [" << label << "] contains:";
	if (!lst.size())
		std::cout << "\tnothing";
	for (typename ft::list<T>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << "  [ " << *it << " ]";
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
	for (typename std::list<T>::iterator it = ls.begin(); it != ls.end(); ++it)
	{
		std::cout << "  [ " << *it << " ]";
	}
	std::cout << std::endl;
}


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
	// remove_if()
	{

		std::cout << "sizeof(NODE<T>): " << sizeof(ft::Node<char*>) << std::endl;
		
		// ft::list<std::string> list;
		// list.push_back ("one");
		// list.push_back ("two");
		// list.push_back ("Three");
		// print_list(list, "list");
		// list.sort();
		// print_list(list, "list");
	
		// ft::list<std::string>::iterator it;
	}
	return 0;
}
