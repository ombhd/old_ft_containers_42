/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:23:34 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/21 16:03:57 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "./node.hpp"

#include <vector>
#include <list>

std::vector<int> vec;
std::list<int> lst;

namespace ft
{
	template <class T>
	class list
	{
	private:
		Node<T> *_head;
		Node<T> *_tail;
		size_t _len;

	public:
		list<T>() : _len(0)
		{
			_head = _tail = new Node<T>();
		}

		list<T>(size_t n, const T &val = static_cast<T>(0))
		{
			_len = n;
			for (size_t i = 0; i < _len; i++)
			{
			}
		}

		list<T>(const list<T> &) {}

		list<T> &operator=(const list<T> &) {}

		~list<T>() {}
	};
} // namespace ft
#endif // !LIST_HPP
