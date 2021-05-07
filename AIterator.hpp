/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AIterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:38:10 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/26 11:48:18 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"

namespace ft
{
	template <class T>
	class AIterator
	{
	public:
		// types aliases for node pointers
		typedef Node<T> 		*pointer;
		typedef Node<T> const*	const_pointer;
		typedef T				&type_reference;

		// default constructor
		AIterator() : ptr(NULL) {}

		// default constructor
		AIterator(pointer const &inPtr) : ptr(inPtr) {}

		// copy constructor
		AIterator(AIterator const &src) { *this = src; }

		// destructor
		virtual ~AIterator() {}

		// -> asPointer()
		pointer asPointer() const
		{
			return ptr;
		}

		// = operator overloading
		AIterator &operator=(AIterator const &src)
		{
			if (this != &src)
				ptr = src.ptr;
			return (*this);
		}

		size_t operator-(AIterator const &src)
		{
			return (this->ptr - src.ptr);
		}

		size_t operator+(AIterator const &src)
		{
			return (this->ptr + src.ptr);
		}

		// * operator overloading
		type_reference operator*() const
		{
			return ptr->data;
		}

		// -> operator overloading
		pointer operator->() const
		{
			return ptr;
		}

		// pre ++ operator overloading
		virtual AIterator &operator++() = 0;

		// pre -- operator overloading
		virtual AIterator &operator--() = 0;

		// == operator overloading
		bool operator==(AIterator const &src) const
		{
			return (ptr == src.ptr);
		}
		
		// != operator overloading
		bool operator!=(AIterator const &src) const
		{
			return (ptr != src.ptr);
		}

		// > operator overloading
		bool operator>(AIterator const &src) const
		{
			return (ptr > src.ptr);
		}

		// < operator overloading
		bool operator<(AIterator const &src) const
		{
			return (ptr < src.ptr);
		}

		// >= operator overloading
		bool operator>=(AIterator const &src) const
		{
			return (ptr >= src.ptr);
		}

		// <= operator overloading
		bool operator<=(AIterator const &src) const
		{
			return (ptr <= src.ptr);
		}
	protected:
		pointer ptr;
	};
}