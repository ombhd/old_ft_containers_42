/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:23:34 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/16 23:51:59 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <limits>

#include "Node.hpp"

// #include <algorithm>
// #include <unistd.h>

//================== start of testing ====================
#include <vector>
#include <iterator>
#include <list>

std::vector<int> vec;
std::list<int> lst;
std::list<int> lst1;
std::list<int>::iterator itex = lst.begin();

void func()
{
	if (*itex < *(itex))
		std::cout << "hi" << std::endl;
	lst.assign(10, 20);
	lst.insert(itex, 2, 12);
	lst.erase(itex);
	lst.resize(12);
	lst.splice(itex, lst1, itex);
}
//=================== end of testing =====================

namespace ft
{
	template <class T>
	class listIterator
	{
		public:
		// types aliases for node pointers
		typedef listIterator 		&reference;
		typedef listIterator const	&const_reference;
		typedef Node<T> 			*pointer;
		typedef Node<T> const*		const_pointer;
		typedef T					&type_reference;

		// default constructor
		listIterator() : ptr(NULL) {}

		// parameter constructor
		listIterator(pointer const &inPtr) : ptr(inPtr) {}

		// copy constructor
		listIterator(listIterator const &src) { *this = src; }

		// destructor
		virtual ~listIterator() {}

		// -> asPointer()
		pointer asPointer() const
		{
			return ptr;
		}

		// = operator overloading
		listIterator &operator=(listIterator const &src)
		{
			if (this != &src)
				ptr = src.ptr;
			return (*this);
		}

		// * operator overloading
		virtual type_reference operator*()
		{
			return ptr->data;
		}
		
		// * operator overloading const
		virtual type_reference operator*() const
		{
			return ptr->data;
		}

		// -> operator overloading 
		virtual pointer operator->()
		{
			return ptr;
		}

		// -> operator overloading const
		virtual const_pointer operator->() const
		{
			return ptr;
		}

		// == operator overloading
		bool operator==(listIterator const &src) const
		{
			return (ptr == src.ptr);
		}

		// != operator overloading
		bool operator!=(listIterator const &src) const
		{
			return (ptr != src.ptr);
		}

		// pre ++ operator overloading
		listIterator &operator++()
		{
			if (!this->ptr->next)
				while (ptr->prev)
					ptr = ptr->prev;
			else
				this->ptr = this->ptr->next;
			return (*this);
		}

		// post ++ operator overloading
		listIterator operator++(int)
		{
			listIterator it = *this;
			if (!this->ptr->next)
				while (ptr->prev)
					ptr = ptr->prev;
			else
				this->ptr = this->ptr->next;
			return (it);
		}

		// pre -- operator overloading
		listIterator &operator--()
		{
			if (!this->ptr->prev)
				while (ptr->next)
					ptr = ptr->next;
			else
				this->ptr = this->ptr->prev;
			return (*this);
		}

		// post -- operator overloading
		listIterator operator--(int)
		{
			listIterator it = *this;
			if (!this->ptr->prev)
				while (ptr->next)
					ptr = ptr->next;
			else
				this->ptr = this->ptr->prev;
			return (it);
		}
		protected:
			pointer ptr;
	};

	template <class T>
	class listReverseIterator : public listIterator<T>
	{
	public:
		// types aliases for AIterator typenames
		typedef listReverseIterator<T> 			 			&reference;
		typedef listReverseIterator<T> const				&const_reference;
		typedef typename listIterator<T>::type_reference	type_reference;
		typedef typename listIterator<T>::pointer			pointer;
		typedef typename listIterator<T>::const_pointer		const_pointer;

		// default constructor
		listReverseIterator() : listIterator<T>() {}

		// default constructor
		listReverseIterator(pointer inPtr) : listIterator<T>(inPtr) {}

		// copy constructor
		listReverseIterator(listReverseIterator const &src) : listIterator<T>(src) {}

		// destructor
		virtual ~listReverseIterator() {}

		type_reference operator*()
		{
			listIterator<T> tmp = *this;
			return (*--tmp);
		}
		
		type_reference operator*() const 
		{
			listIterator<T> tmp = *this;
			return (*--tmp);
		}
		
		pointer operator->() 
		{
			listIterator<T> tmp = *this;
			--tmp;
			return (tmp.asPointer());
		}
		
		const_pointer operator->() const 
		{
			listIterator<T> tmp = *this;
			--tmp;
			return (tmp.asPointer());
		}

		// pre ++ operator overloading
		reference operator++()
		{
			listIterator<T>::operator--();
			return (*this);
		}

		// post ++ operator overloading
		listReverseIterator operator++(int)
		{
			listReverseIterator iter = *this;
			listIterator<T>::operator--();
			return (iter);
		}

		// pre -- operator overloading
		reference operator--()
		{
			listIterator<T>::operator++();
			return (*this);
		}

		// post -- operator overloading
		listReverseIterator operator--(int)
		{
			listReverseIterator iter = *this;
			listIterator<T>::operator++();
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
		typedef Node<T> *pointer;
		typedef Node<T> const *const_pointer;

		// ////////////////// debugging //////////////////

		void print_list(char const *label) const
		{
			std::cout << "\nft::list Size: " << _size;
			std::cout << "\nlist [" << label << "] contains:";
			if (!this->_size)
				std::cout << "\tnothing";
			iterator it = this->begin();
			// std::cout << "\n================> Reached here!" << *it<< std::endl;
			for (; it != this->end(); ++it)
			{
				std::cout << "\t[ " << *it << " ]";
			}
			std::cout << std::endl;
		}

		// ////////////////// debugging //////////////////

		list<T>() : _start(new Node<T>()),
					_end(_start),
					_size(0)
		{
		}

		list<T>(size_t n, const value_type &val = value_type()) : _start(new Node<T>()),
																	   _end(_start),
																	   _size(0)
		{
			while (n--)
			{
				this->push_back(val);
			}
		}

		list<T>(const list<T> &src) : _start(new Node<T>()),
									  _end(_start),
									  _size(0)
		{
			*this = src;
		}

		list<T> &operator=(const list<T> &src)
		{
			this->clear();
			for (iterator it = src.begin(); it != src.end(); it++)
			{
				this->push_back(*it);
			}
			return (*this);
		}

		~list<T>()
		{
			this->clear();
			delete this->_end;
		}

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
			return (reverse_iterator(this->_end));
		}

		const_reverse_iterator rbegin() const
		{
			return (static_cast<const_reverse_iterator>(reverse_iterator(this->_end)));
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
			return (reverse_iterator(this->_start));
		}

		const_reverse_iterator rend() const
		{
			return (static_cast<const_reverse_iterator>(reverse_iterator(this->_start)));
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
			return (std::numeric_limits<long>::max() / (sizeof(Node<T>) - sizeof(pointer)));
			// needs explanations
		}

		/********************
		 *  Element access  *
		 ********************/

		reference back()
		{
			if (!this->_size)
				return (this->_end->data);
			return (this->_end->prev->data);
		}

		const_reference back() const
		{
			if (!this->_size)
				return (this->_end->data);
			return (this->_end->prev->data);
		}

		reference front()
		{
			if (!this->_size)
				return (this->_end->data);
			return (this->_start->data);
		}

		const_reference front() const
		{
			if (!this->_size)
				return (this->_end->data);
			return (this->_start->data);
		}

		/***************
		 *  Modifiers  *
		 ***************/

		// assign()
		// (1)
		void assign(size_type n, const value_type &val)
		{
			this->clear();
			while (n--)
			{
				this->push_back(val);
			}
		}

		// (2)
		void assign(iterator first, iterator last)
		{
			this->clear();
			for (; first != last; first++)
			{
				this->push_back(*first);
			}
		}

		// insert()
		// single element (1)
		iterator insert(iterator position, const value_type &val)
		{
			bool isCoinsid = (this->_start == position.asPointer());
			iterator resIt = position;
			position.asPointer()->link(new Node<value_type>(val));
			this->_size++;
			if (isCoinsid)
				this->_start = this->_start->prev;
			return resIt;
		}

		// fill (2)
		void insert(iterator position, size_type n, const value_type &val)
		{
			bool isCoinsid = (this->_start == position.asPointer());
			size_type sizeToAdd = n;
			this->_size += n;
			while (n--)
			{
				position.asPointer()->link(new Node<value_type>(val));
			}
			if (isCoinsid)
			while (sizeToAdd--)
			{
				_start = _start->prev;
			}
		}

		// range (3)
		void insert(iterator position, iterator first, iterator last)
		{
			for (; first != last; first++)
			{
				this->insert(position, *first);
			}
		}

		// erase()
		iterator erase(iterator position)
		{
			// checking if the list is empty
			if (!this->_size)
				return (end());
			this->_size--;
			pointer pos = position.asPointer();
			// moving head to its next if it's the case
			if (pos == _start)
				_start = _start->next;
			return (iterator(pos->erase()));
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				first = this->erase(first);
			}
			return first;
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
			pointer holder = new Node<value_type>(value);
			if (!this->_size++)
				this->_start = holder;
			this->_end->link(holder);
		}

		// pop_front()
		void pop_back()
		{
			if (!this->_size)
				return;
			this->_end->prev->erase();
			if (!--this->_size)
				this->_start = this->_end;
		}

		// swap()
		void swap(list &x)
		{
			// _start
			pointer tmp = _start;
			_start = x._start;
			x._start = tmp;

			// _end
			tmp = _end;
			_end = x._end;
			x._end = tmp;
			
			// _size
			size_type size = x._size;
			x._size = this->_size;
			this->_size = size;	
		}


		// resize()
		void resize(size_type n, value_type val = static_cast<value_type>(0))
		{
			if (n == this->_size)
				return;
			if (n < this->_size)
			{
				iterator itp = this->begin();
				size_type lenToErase = this->_size - n;
				while (lenToErase--)
					this->pop_back();
			}
			else
			{
				this->insert(this->end(), n - this->_size, val);
			}
		}

		// clear()
		void clear()
		{
			while (this->_size)
			{
				this->pop_front();
			}
		}


		/***************
		*  Operations  *
		****************/

		// splice()
		// entire list (1)
		void splice(iterator position, list &x)
		{
			this->splice(position, x, x.begin(), x.end());
		}

		// single element (2)
		void splice(iterator position, list &x, iterator it)
		{
			iterator ite = it;
			this->splice(position, x, it, ++ite);
		}

		// element range (3)
		void splice(iterator position, list &x, iterator first, iterator last)
		{
			pointer ptr;
			pointer pos = position.asPointer();
			
			while (first != last)
			{
				ptr = (first++).asPointer();
				// moving heads if it's the case
				if (ptr == x._start)
					x._start = ptr->next;
				if (pos == this->_start)
					this->_start = ptr;
				// unlinking and linking node
				ptr->unlink();
				pos->link(ptr);
				// resizing
				++this->_size;
				--x._size;
			}
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
			iterator it = this->begin();
			iterator end = this->end();
			while (it != end)
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
			iterator ite = this->end();
			iterator it1 = it0;
			it1++;

			while (it1 != ite)
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
			if (this == &x)
				return ;
			iterator xit = x.begin();
			iterator xlast = x.end();
			iterator it = this->begin();
			iterator ite = this->end();

			while (it != ite && xit != xlast)
			{
				if (*xit < *it)
				{
					this->splice(it, x, xit);
					xit = x.begin();
				}
				else
					it++;
			}
			if (x._size != 0)
				this->splice(it, x);
		}

		// (2)
		template <class Compare>
		void merge(list &x, Compare comp)
		{
			if (this == &x)
				return ;
			iterator xit = x.begin();
			iterator xlast = x.end();
			iterator it = this->begin();
			iterator ite = this->end();

			while (it != ite && xit != xlast)
			{
				if (comp(*xit, *it))
				{
					this->splice(it, x, xit);
					xit = x.begin();
				}
				else
					it++;
			}
			if (x._size != 0)
				this->splice(it, x);
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
						// if it's the case, switch to the new head before swaping nodes
						if (curr == this->begin())
							_start = next.asPointer();
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
					if (comp(*curr, *next))
					{
						// if it's the case, switch to the new head before swaping nodes
						if (curr == this->begin())
							_start = next.asPointer();
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
						++curr;
						++next;
					}
				}
			}
		}

		// reverse()
		void reverse()
		{
			if (this->_size < 2)
				return ;
			pointer pos = this->_start;
			pointer ptr;
			// setting up the new head
			this->_start = this->_end->prev;
			
			while (pos->next != this->_end)
			{
				ptr = this->_end->prev;
				ptr->unlink();
				pos->link(ptr);
			}
		}

		/*************************************
		 *  NoNon-member function overloads  *
		*************************************/

		// relational operators (list)
		// ==
		// bool operator==(const list<T> &lhs, const list<T> &rhs);
		// // !=
		// bool operator!=(const list<T> &lhs, const list<T> &rhs);
		// // <
		// bool operator<(const list<T> &lhs, const list<T> &rhs);
		// // <=
		// bool operator<=(const list<T> &lhs, const list<T> &rhs);
		// // >
		// bool operator>(const list<T> &lhs, const list<T> &rhs);
		// // >=
		// bool operator>=(const list<T> &lhs, const list<T> &rhs);

		// // swap(list x, list y)
		// void swap(list<T> &x, list<T> &y);

	private:
		pointer _start;
		pointer _end;
		size_t _size;
	}; // list

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

	// /////////////////////// debugging

	// ///////////////////////// debugging

} // namespace ft

#endif // !LIST_HPP
