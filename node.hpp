/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:02:42 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/07 16:40:12 by obouykou         ###   ########.fr       */
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

		typedef Node<T>*	pointer;
		typedef Node<T>&	reference;
		
		typedef struct	s_range
		{
			pointer first;
			pointer last;
		}				t_range;
		
		// Node's attributes
		T		data;
		pointer next;
		pointer prev;

		Node<T>() : data(static_cast<T>(0)), next(NULL), prev(NULL) {}

		Node<T>(T inData) : data(inData), next(NULL), prev(NULL) {}

		Node<T>(Node<T> const &src)
		{
			*this = src;
		}

		reference operator=(Node<T> const &src)
		{
			if (this != &src)
			{
				this->data = src.data;
				this->next = src.next;
				this->prev = src.prev;
			}
			return *this;
		}

		virtual ~Node<T>(){}

		void	link(pointer node)
		{
			if (!node)
				return ;
			if (this->prev)
				this->prev->next = node;
			node->prev = this->prev;
			node->next = this;
			this->prev = node;
		}

		void	link(pointer first, pointer last)
		{
			if (this->prev)
				this->prev->next = first;
			if (first)
				first->prev = this->prev;
			else
			{
				if (last)	
					last->prev = this->prev;
			}
			if (last)
			{
				last->next = this;
				this->prev = last;
			}
			else
			{
				if (first)
					first->next = this;
				this->prev = first;
			}
		}

		pointer	unlink(void)
		{
			pointer ret = this;
			if (this->next)
				this->next->prev = this->prev;
			if (this->prev)
				this->prev->next = this->next;
			return ret;
		}

		t_range	unlinkRange(pointer last)
		{
			t_range rg;
			
			rg.first = this;
			rg.last = last;
			if (this->prev && last)
				this->prev->next = last->next;
			if (last && last->next)
				last->next->prev = this->prev;
			return rg;
		}

		pointer	erase(void)
		{
			pointer ret = this->next;
			if (this->next)
				this->next->prev = this->prev;
			if (this->prev)
				this->prev->next = this->next;
			delete this;
			return ret;
		}
	};
} // namespace ft

#endif // !NODE_HPP