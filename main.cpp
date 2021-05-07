/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:38:16 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/07 02:43:37 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
// #include "glagan/include/List.hpp"
#include <list>
#include <iostream>


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
	// erase()
	{
		
	}	
	return 0;
}

// #include <list>
// #include <iostream>

// template < typename T >
// void print_list(std::list<T> &lst)
// {
// 	std::cout << "\nList Size: " << lst.size();
// 	std::cout << "\nList contains:";
// 	for (std::list<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); ++it)
// 	{
// 		std::cout << "\t[ " << *it << " ]";
// 	}
// 	std::cout << std::endl;
// }

// int main(void)
// {
// 	std::list<int> lst;
// 	for (int i = 0; i < 3; i++)
// 	{
// 		lst.push_front(i);
// 	}
// 	print_list(lst);
// 	lst.pop_back();
// 	lst.pop_back();
// 	lst.pop_back();
// 	// lst.pop_back();
// 	print_list(lst);
// 	return 0;
// }
