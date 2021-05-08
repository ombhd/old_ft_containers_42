/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:38:16 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/08 10:56:28 by obouykou         ###   ########.fr       */
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
		
	}
	return 0;
}
