/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:23:34 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/06 16:14:30 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <limits>
#include <algorithm>

#include "./AIterator.hpp"

//================== start of testing ====================
#include <vector>
#include <iterator>
#include <list>

std::vector<int> vec;
std::list<int> lst;
std::list<int> lst1;
std::list<int>::iterator it = lst.begin();

void func()
{
	if (*it < *(it))
		std::cout << "hi" << std::endl;
	lst.assign(10, 20);
	lst.insert(it, 2, 12);
	lst.erase(it);
	lst.resize(12);
	lst.splice(it, lst1, it);
}
//=================== end of testing =====================

namespace ft
{
	template <class T>
	class listIterator : public AIterator<T>
	{
	public:
		// types aliases for AIterator typenames
		typedef typename AIterator<T>::pointer pointer;
		typedef typename AIterator<T>::const_pointer const_pointer;

		// default constructor
		listIterator() : AIterator<T>() {}

		// default constructor
		listIterator(pointer inPtr) : AIterator<T>(inPtr) {}

		// copy constructor
		listIterator(listIterator const &src) : AIterator<T>(src) {}

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
		typedef typename AIterator<T>::pointer pointer;
		typedef typename AIterator<T>::const_pointer const_pointer;

		// default constructor
		listReverseIterator() : AIterator<T>() {}

		// default constructor
		listReverseIterator(pointer inPtr) : AIterator<T>(inPtr) {}

		// copy constructor
		listReverseIterator(listReverseIterator const &src) : AIterator<T>(src) {}

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
		typedef size_t size_type;
		typedef T value_type;
		typedef value_type &reference;
		typedef value_type const &const_reference;
		typedef listIterator<T> iterator;
		typedef listIterator<T> const const_iterator;
		typedef listReverseIterator<T> reverse_iterator;
		typedef listReverseIterator<T> const const_reverse_iterator;
		typedef typename Node<T>::t_range t_range;
		typedef Node<T> *pointer;
		typedef Node<T> const *const_pointer;

		list<T>() : _size(0)
		{
			_start = _end = new Node<T>();
		}

		list<T>(size_t n, const value_type &val = static_cast<T>(0)) : _start(new Node<T>()),
																	   _end(this->_start),
																	   _size(n)
		{
			while (n--)
			{
				this->push_back(val);
			}
		}

		list<T>(const list<T> &src) { *this = src; }

		list<T> &operator=(const list<T> &src)
		{
			this->clear();
			for (iterator it = src.begin(); it != src.end(); it++)
			{
				this->push_back(*it);
			}
		}

		~list<T>() { this->clear(); }

		/**************
		*  iterators  *
		***************/

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

		/**************
		 *  Capacity  *
		 **************/

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

		/********************
		 *  Element access  *
		 ********************/

		reference back()
		{
			return (*(iterator(this->_end->prev)));
		}

		const_reference back() const
		{
			return (*(iterator(this->_end->prev)));
		}

		reference front()
		{
			return (*(iterator(this->_start)));
		}

		const_reference front() const
		{
			return (*(iterator(this->_start)));
		}

		/***************
		 *  Modifiers  *
		 ***************/

		// assign()
		//
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			for (; first != last && it != ite; first++, it++)
			{
				*it = *first;
			}
			if (it == ite)
				this->insert(ite, first, last);
			else
				this->erase(it, ite);
		}

		void assign(size_type n, const value_type &val)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			for (; n != 0 && it != it; --n, it++)
			{
				*it = val;
			}
			if (it == ite)
				this->insert(ite, n, val);
			else
				this->erase(it, ite);
		}

		// insert()
		// single element (1)
		iterator insert(iterator position, const value_type &val)
		{
			iterator resIt = position;
			position.asPointer()->link(new Node<value_type>(val));
			this->_size++;
			return resIt;
		}

		// fill (2)
		void insert(iterator position, size_type n, const value_type &val)
		{
			this->_size += n;
			while (n--)
			{
				position.asPointer()->link(new Node<value_type>(val));
			}
		}

		// range (3)
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			if (first >= last)
				return last;
			this->size += last - first;
			for (; first != last; first++)
			{
				position.asPointer()->link(new Node<value_type>(*first));
			}
		}

		// erase()
		iterator erase(iterator position)
		{
			this->_size--;
			return (iterator(position.asPointer()->erase()));
		}

		iterator erase(iterator first, iterator last)
		{
			if (first >= last)
				return last;
			this->size -= last - first;
			for (iterator it = first; it != last;)
			{
				it = iterator((*it)->erase());
			}
			return it;
		}

		// push_front()
		void push_front(value_type const &value)
		{
			Node<T> *holder = new Node<value_type>(value);
			this->_start->link(holder);
			this->_start = holder;
			this->_size++;
		}

		// pop_front()
		void pop_front()
		{
			if (!this->_size)
				return;
			_start = this->_start->erase();
			this->_size--;
		}

		// push_back()
		void push_back(value_type const &value)
		{
			Node<T> *holder = new Node<value_type>(value);
			if (!this->_size++)
				this->begin = holder;
			this->_end->link(holder);
		}

		// pop_front()
		void pop_back()
		{
			if (!this->_size)
				return;
			this->_end->prev->erase();
			this->_size--;
		}

		// swap()
		void swap(list &x)
		{
			iterator first1 = this->begin();
			iterator last1 = this->end();
			iterator first2 = x.begin();
			iterator last2 = x.end();
			pointer tmp;

			for (; first1 != last1 && first2 != last2; first1++, first2++)
			{
				tmp = first1.asPointer()->unlink();
			}

			// list<value_type> tmp = *this;
			// *this = x;
			// x = tmp;
		}

		// resize()
		void resize(size_type n, value_type val = static_cast<value_type>(0))
		{
			if (n == this->_size)
				return;
			if (n < this->_size)
			{
				iterator itp = this->begin();
				while (n--)
					itp++;
				this->erase(itp, this->end());
			}
			else if (n > this->_size)
			{
				this->insert(this->end(), n, val);
			}
		}

		// clear()
		void clear()
		{
			while (this->_size)
			{
				this->pop_back();
			}
		}

		/***************
		*  Operations  *
		****************/

		// splice()
		// entire list (1)
		void splice(iterator position, list &x)
		{
			// if (position > this->end() || position < this->begin())
			// {
			// 	// error
			// 	return ;
			// }
			this->_size += x._size;
			position.asPointer()->link(x.begin().asPointer(), x.end().asPointer()->prev);
			x._size = 0;
			x._start = x._end;
		}

		// single element (2)
		void splice(iterator position, list &x, iterator it)
		{
			// if (position > this->end() || position < this->begin())
			// {
			// 	// error
			// 	return ;
			// }
			pointer unlinkedNode = it.asPointer()->unlink();
			x._size--;
			position.asPointer()->link(unlinkedNode);
			this->_size++;
		}

		// element range (3)
		void splice(iterator position, list &x, iterator first, iterator last)
		{
			// if (position > this->end() || position < this->begin())
			// {
			// 	// error
			// 	return ;
			// }
			t_range rg = first.asPointer()->unlinkRange(last.asPointer()->prev);
			x._size -= rg.last - rg.first + 1;
			position.asPointer()->link(first.asPointer(), last.asPointer()->prev);
			this->_size += rg.last - rg.first + 1;
		}

		// remove()
		void remove(const value_type &val)
		{
			for (iterator it = this->begin(); it != this->end();)
			{
				if (*it == val)
					it = this->erase(it);
				else
					it++;
			}
		}

		// remove_if()
		template <class Predicate>
		void remove_if(Predicate pred)
		{
			for (iterator it = this->begin(); it != this->end();)
			{
				if (pred(*it) == true)
					it = this->erase(it);
				else
					it++;
			}
		}

		// unique()
		// (1)
		void unique()
		{
			iterator it0 = this->begin();
			iterator it1 = it0;
			it1++;

			for (; it1 != this->end();)
			{
				if (*it1 == *it0)
				{
					it1 = this->erase(it1);
				}
				else
				{
					it0++;
					it1++;
				}
			}
		}

		// (2)
		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{
			iterator it0 = this->begin();
			iterator it1 = it0;
			it1++;

			for (; it1 != this->end();)
			{
				if (binary_pred(*it1, *it0))
				{
					it1 = this->erase(it1);
				}
				else
				{
					it0++;
					it1++;
				}
			}
		}

		// merge()
		// (1)
		void merge(list &x)
		{
			iterator xit = x.begin();
			for (iterator it = this->begin(); it != this->end() && xit != x.end(); it++, xit++)
			{
				if (*xit < *it)
				{
					this->insert(it, *xit);
					x.pop_front();
					xit++;
				}
				else
					it++;
			}
			this->splice(it, x);
		}

		// (2)
		template <class Compare>
		void merge(list &x, Compare comp)
		{
			iterator xit = x.begin();
			for (iterator it = this->begin(); it != this->end() && xit != x.end(); it++, xit++)
			{
				if (comp(*xit, *it))
				{
					this->insert(it, *xit);
					x.pop_front();
					xit++;
				}
				else
					it++;
			}
			this->splice(it, x);
		}

		// reverse()
		void reverse()
		{
			iterator it = this->begin();
			iterator ite = this->end();

			value_type tmp;
			while (it < ite)
			{
				tmp = *it;
				*it = *ite;
				*ite = tmp;
			}
		}

		// sort()
		// (1)
		void sort()
		{
			if (!this->size())
				return;

			iterator curr;
			iterator next;
			iterator nextReserv;
			pointer tmp;
			bool isSorted;

			isSorted = false;
			while (!isSorted)
			{
				isSorted = true;
				curr = this->begin();
				next = curr;
				next++;
				while (next != this->end())
				{
					if (*curr > *next)
					{
						// swapping nodes
						nextReserv = next;
						nextReserv++;
						tmp = next.asPointer()->unlink();
						curr.asPointer()->link(tmp);
						next = nextReserv;
						isSorted = false;
					}
					else
					{
						curr++;
						next++;
					}
				}
			}
		}

		// (2)
		template <class Compare>
		void sort(Compare comp)
		{
			if (!this->size())
				return;

			iterator curr;
			iterator next;
			pointer tmp;
			bool isSorted;

			isSorted = false;
			while (!isSorted)
			{
				isSorted = true;
				curr = this->begin();
				next = curr;
				next++;
				while (next != this->end())
				{
					if (comp(*curr, *next))
					{
						// swapping nodes
						tmp = next.asPointer()->unlink();
						curr.asPointer()->link(tmp);
						isSorted = false;
					}
					curr++;
					next++;
				}
			}
		}

		/*************************************
		 *  NoNon-member function overloads  *
		*************************************/

		// relational operators (list)
		// ==
		friend bool operator==(const list<T> &lhs, const list<T> &rhs);
		// !=
		friend bool operator!=(const list<T> &lhs, const list<T> &rhs);
		// <
		friend bool operator<(const list<T> &lhs, const list<T> &rhs);
		// <=
		friend bool operator<=(const list<T> &lhs, const list<T> &rhs);
		// >
		friend bool operator>(const list<T> &lhs, const list<T> &rhs);
		// >=
		friend bool operator>=(const list<T> &lhs, const list<T> &rhs);

		// swap(list x, list y)
		friend void swap(list<T> &x, list<T> &y);

	private:
		pointer _start;
		pointer _end;
		size_t _size;
	}; // namespace ft

	// (1)
	template <class T>
	bool operator==(const list<T> &lhs, const list<T> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename list<T>::iterator first1 = lhs.begin();
		typename list<T>::iterator last1 = lhs.end();
		typename list<T>::iterator first2 = rhs.begin();
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	// (2)
	template <class T>
	bool operator!=(const list<T> &lhs, const list<T> &rhs)
	{
		return (!(lhs == rhs));
	}

	// (3)
	template <class T>
	bool operator<(const list<T> &lhs, const list<T> &rhs)
	{
		typename list<T>::iterator first1 = lhs.begin();
		typename list<T>::iterator last1 = lhs.end();
		typename list<T>::iterator first2 = rhs.begin();
		typename list<T>::iterator last2 = rhs.end();

		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	// (4)
	template <class T>
	bool operator<=(const list<T> &lhs, const list<T> &rhs)
	{
		return !(rhs < lhs);
	}

	// (5)
	template <class T>
	bool operator>(const list<T> &lhs, const list<T> &rhs)
	{
		return (rhs < lhs);
	}

	// (6)
	template <class T>
	bool operator>=(const list<T> &lhs, const list<T> &rhs)
	{
		return !(lhs < rhs);
	}

	// swap(list x, list y)
	template <class T>
	void swap(list<T> &x, list<T> &y)
	{
		x.swap(y);
	}

} // namespace ft
#endif // !LIST_HPP
