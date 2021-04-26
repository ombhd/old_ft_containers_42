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

#include "node.hpp"

namespace ft
{
	template <class T>
	class AIterator
	{
	public:
		// types aliases for node pointers
		typedef Node<T> 		*pointer;
		typedef Node<T>	const	*const_pointer;
		typedef T				value_type;
		typedef value_type		&reference;

		// default constructor
		AIterator() : ptr(NULL) {}

		// default constructor
		AIterator(pointer const &inPtr) : ptr(inPtr) {}

		// copy constructor
		AIterator(AIterator const &src) { *this = src; }

		// destructor
		virtual ~AIterator() {}

		// = operator overloading
		AIterator &operator=(AIterator const &src)
		{
			if (this != &src)
				ptr = src.ptr;
			return (*this);
		}

		// * operator overloading
		reference operator*() const
		{
			return ptr->data;
		}

		// -> operator overloading
		reference operator->() const
		{
			return ptr;
		}

		// pre ++ operator overloading
		virtual AIterator &operator++() = 0;

		// post ++ operator overloading
		virtual AIterator &operator++(int) = 0;

		// pre -- operator overloading
		virtual AIterator &operator--() = 0;

		// post -- operator overloading
		virtual AIterator &operator--(int) = 0;

		// == operator overloading
		bool operator==(AIterator const &src) const
		{
			return (ptr == src.ptr);
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