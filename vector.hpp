/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:35:38 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/15 22:54:07 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>


namespace ft
{
	
template<typename T>
class vectorIterator
{
public:
	typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const * const_pointer;
    typedef value_type& reference;
    typedef value_type const & const_reference;
    typedef size_t size_type;
protected:
	pointer ptr;
public:
	vectorIterator(): ptr(NULL) {}
	
	vectorIterator(pointer p): ptr(p) {}
	
	vectorIterator(vectorIterator const &rhs): ptr(rhs.ptr) {}
	
	virtual ~vectorIterator() {}

	vectorIterator &operator=(vectorIterator const &rhs)
	{
		this->ptr = rhs.ptr;
		return (*this);
	}

	reference operator*() 
	{
		return (*this->ptr);
	}
	
	const_reference operator*() const 
	{
		return (*this->ptr);
	}
	
	pointer operator->() 
	{
		return (this->ptr);
	}
	
	const_pointer operator->() const 
	{
		return (this->ptr);
	}
    
	reference operator[](int val) 
	{
		return (*(this->ptr + val));
	}
    
	const_reference operator[](int val) const 
	{
		return (*(this->ptr + val));
	}

	vectorIterator operator++(int) 
	{
		vectorIterator tmp(*this);
		++this->ptr;
		return (tmp);
	}
	
	vectorIterator &operator++() 
	{
		++this->ptr;
		return (*this);
	}
	
	vectorIterator operator--(int) 
	{
		vectorIterator tmp(*this);
		--this->ptr;
		return (tmp);
	}
	
	vectorIterator &operator--() 
	{
		--this->ptr;
		return (*this);
	}

	vectorIterator &operator+=(int value) 
	{
		this->ptr += value;
		return (*this);
	}

	vectorIterator operator+(int value) const 
	{
		vectorIterator tmp(*this);
		return (tmp += value);
	}

	vectorIterator &operator-=(int value) 
	{
		this->ptr -= value;
		return (*this);
	}

	vectorIterator operator-(int value) const 
	{
		vectorIterator tmp(*this);
		return (tmp -= value);
	}
	
	size_type operator-(vectorIterator const &rhs) const 
	{
		return (this->ptr - rhs.ptr);
	}

	size_type operator+(vectorIterator const &rhs) const 
	{
		return (this->ptr + rhs.ptr);
	}

	bool operator==(vectorIterator const &rhs) const 
	{
		return (this->ptr == rhs.ptr);
	}

	bool operator!=(vectorIterator const &rhs) const 
	{
		return (this->ptr != rhs.ptr);
	}

	bool operator<(vectorIterator const &rhs) const 
	{
		return (this->ptr < rhs.ptr);
	}

	bool operator<=(vectorIterator const &rhs) const 
	{
		return (this->ptr <= rhs.ptr);
	}

	bool operator>(vectorIterator const &rhs) const 
	{
		return (this->ptr > rhs.ptr);
	}

	bool operator>=(vectorIterator const &rhs) const 
	{
		return (this->ptr >= rhs.ptr);
	}
};
	
	template<typename T>
	class vector
	{
		public:
			typedef T	value_type;
			typedef T	&reference;
			typedef size_t	size_type;
		private:
			size_type _size;
			size_type _capacity;
			T *_arr;

	};
}