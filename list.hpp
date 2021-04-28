/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:23:34 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/28 16:07:13 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <limits>

#include "./AIterator.hpp"

//================== start of testing ====================
#include <vector>
#include <iterator>
#include <list>

std::vector<int> vec;
std::list<int> lst;
std::list<int>::reverse_iterator it = lst.rbegin();

void func()
{
	if (*it < *(it - 1))
		std::cout << "hi" << std::endl;
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
		typedef size_t							size_type;
		typedef T								value_type;
		typedef value_type &					reference;
		typedef value_type const &				const_reference;
		typedef listIterator<T>					iterator;
		typedef listIterator<T>	const			const_iterator;
		typedef listReverseIterator<T>			reverse_iterator;
		typedef listReverseIterator<T> const	const_reverse_iterator;
		// typedef Node<T>*						pointer;
		// typedef Node<T> const *					const_pointer;

		list<T>() : _size(0)
		{
			_start = _end = new listIterator<T>();
		}

		list<T>(size_t n, const value_type &val = static_cast<T>(0)):
		_start(new listIterator<T>()),
		_end(this->_start),
		_size(n)
		{
			for (; n > 0; --n)
			{
				this->push_back(val);
			}
		}

		list<T>(const list<T> &) {}

		list<T> &operator=(const list<T> &src) {}

		~list<T>() {}

		void push_back(value_type const &value)
		{
			Node<T> *holder = new Node<value_type>(value);
			if (!this->_size++)
				this->begin = holder;
			this->_end->link(holder);
		}

		void push_front(value_type const &value)
		{
			Node<T> *holder = new Node<value_type>(value);
			this->_end->link(holder);
			this->_start = holder;
			this->_size++;
		}

		// iterators
		iterator begin()
		{
			return (iterator(this->_start));
		}
		
		const_iterator begin() const
		{
			return (static_cast<const_iterator>(iterator(this->_start)));
		}
				
		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->_start));
		}
		
		const_reverse_iterator rbegin() const
		{
			return (static_cast<const_reverse_iterator>(reverse_iterator(this->_start)));
		}

		iterator end()
		{
			return (iterator(this->_end));
		}
		
		const_iterator end() const
		{
			return (static_cast<const_iterator>(iterator(this->_end)));
		}
		
		reverse_iterator rend()
		{
			return (reverse_iterator(this->_end));
		}
		
		const_reverse_iterator rend() const
		{
			return (static_cast<const_reverse_iterator>(reverse_iterator(this->_end)));
		}

		// capacity
		bool empty() const
		{
			return (this->_size == 0);
		}

		size_type size() const
		{
			return (this->_size);
		}

		size_type max_size() const
		{
			// needs fix
		}

		// Element access
		reference back()
		{
			return (*iterator(this->_end->prev));
		}
		
		const_reference back() const
		{
			return (*iterator(this->_end->prev));
		}
		
		reference front()
		{
			return (*iterator(this->_start));
		}
		
		const_reference front() const
		{
			return (*iterator(this->_start));
		}

	private:
		Node<T>* 	_start;
		Node<T>*	_end;
		size_t		_size;
	};
} // namespace ft
#endif // !LIST_HPP
