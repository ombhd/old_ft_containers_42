/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:38:16 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/28 15:48:59 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"

int main(void)
{
	ft::Node<int> node_int;
	ft::Node<char> node_char_ptr;
	// ft::Node<std::string> node_string;
	std::cout << sizeof(node_int) << " | " << sizeof(node_char_ptr) << std::endl;
	return 0;
}
