/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:23:34 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/26 12:47:49 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "./AIterator.hpp"

//================== start of testing ====================
#include <vector>
#include <iterator>
#include <list>

std::vector<int> vec;
std::list<int>::iterator it;
std::list<int> lst;

void func()
{
	it--;
}
//=================== end of testing =====================

namespace ft
{
	template <class T>
	class listIterator : public AIterator<T>
	{
	public:
		// types aliases for AIterator typenames
		typedef typename AIterator<T>::pointer			pointer;
		typedef typename AIterator<T>::const_pointer	const_pointer;
		
		// default constructor
		listIterator() : AIterator<T>() {}

		// default constructor
		listIterator(pointer inPtr) : AIterator<T>(inPtr) {}

		// copy constructor
		listIterator(listIterator const &src): AIterator<T>(src) {}

		// destructor
		virtual ~listIterator() {}

		// pre ++ operator overloading
		listIterator &operator++()
		{
			this->ptr = this->ptr->next;
			return (*this);
		}

		// post ++ operator overloading
		listIterator &operator++(int)
		{
			listIterator iter = *this;
			this->ptr = this->ptr->next;
			return (iter);
		}

		// pre -- operator overloading
		listIterator &operator--()
		{
			this->ptr = this->ptr->prev;
			return (*this);
		}

		// post -- operator overloading
		listIterator &operator--(int)
		{
			listIterator iter = *this;
			this->ptr = this->ptr->prev;
			return (iter);
		}
	};

	template <class T>
	class listReverseIterator : public AIterator<T>
	{
		public:
		// types aliases for AIterator typenames
		typedef typename AIterator<T>::pointer			pointer;
		typedef typename AIterator<T>::const_pointer	const_pointer;
		
		// default constructor
		listReverseIterator() : AIterator<T>() {}

		// default constructor
		listReverseIterator(pointer inPtr) : AIterator<T>(inPtr) {}

		// copy constructor
		listReverseIterator(listReverseIterator const &src): AIterator<T>(src) {}

		// destructor
		virtual ~listReverseIterator() {}
		
		// pre ++ operator overloading
		listReverseIterator &operator++()
		{
			this->ptr = this->ptr->prev;
			return (*this);
		}

		// post ++ operator overloading
		listReverseIterator &operator++(int)
		{
			listReverseIterator iter = *this;
			this->ptr = this->ptr->prev;
			return (iter);
		}

		// pre -- operator overloading
		listReverseIterator &operator--()
		{
			this->ptr = this->ptr->next;
			return (*this);
		}

		// post -- operator overloading
		listReverseIterator &operator--(int)
		{
			listReverseIterator iter = *this;
			this->ptr = this->ptr->next;
			return (iter);
		}
	};

	template <class T>
	class list
	{
	public:
		typedef T						value_type;
		typedef value_type				&reference;
		typedef listIterator<T>			iterator;
		typedef listReverseIterator<T>	reverse_iterator;
		typedef typename AIterator<T>::pointer			pointer;
		typedef typename AIterator<T>::const_pointer	const_pointer;

		list<T>() : _len(0)
		{
			_start = _end = new Node<T>();
		}

		list<T>(size_t n, const value_type &val = static_cast<T>(0))
		{
			_len = n;
			for (; n > 0; --n)
			{
			}
		}

		list<T>(const list<T> &) {}

		list<T> &operator=(const list<T> &src) {}

		~list<T>() {}

		void push_back(value_type const &value)
		{
			this->_end->push(new Node<value_type>(value)); 
			++this->_end;
		}

		void push_front(value_type const &value)
		{
			this->_start->push(new Node<value_type>(value)); 
			--this->_start;
		}

	private:
		Node<T>		*_start;
		Node<T>		*_end;
		size_t		_len;
	};
} // namespace ft
#endif // !LIST_HPP
