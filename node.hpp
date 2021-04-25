/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:02:42 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/24 12:43:43 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

namespace ft
{
	template <class T>
	class Node
	{
	public:
		T data;
		Node<T> *next;
		Node<T> *prev;

		Node<T>() : next(NULL), prev(NULL) {}

		Node<T>(T inData) : data(inData), next(NULL), prev(NULL) {}

		Node<T>(Node<T> const &src)
		{
			*this = src;
		}

		Node<T> &operator=(Node<T> const &src)
		{
			if (this != &src)
			{
				this->data = src.data;
				this->next = src.next;
				this->prev = src.prev;
			}
			return *this;
		}

		virtual ~Node<T>();

		void	push(Node<T> *nd)
		{
			this->next = nd;
			if (nd)
				nd->prev = this;
		}
	};
} // namespace ft

#endif // !NODE_HPP