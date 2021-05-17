/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:35:38 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/17 19:58:05 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <limits>
#include <stdexcept>

namespace ft
{

	template <typename T>
	class vectorIterator
	{
	public:
		//typenames aliases
		typedef T value_type;
		typedef value_type *pointer;
		typedef value_type const *const_pointer;
		typedef value_type &reference;
		typedef value_type const &const_reference;
		typedef size_t size_type;

		// default constructor
		vectorIterator() : ptr(NULL) {}

		// constructor with parameter
		vectorIterator(pointer p) : ptr(p) {}

		// copy constructor
		vectorIterator(vectorIterator const &rhs) : ptr(rhs.ptr) {}

		// destructor
		virtual ~vectorIterator() {}

		/**
		* operators overloadings
		**/

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

		size_type asIndex(pointer p) const
		{
			if (this->ptr - p < 0L)
				throw std::invalid_argument("vector iterator: invalid argument for asIndex");
			return (this->ptr - p);
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

		ptrdiff_t operator-(vectorIterator const &rhs) const
		{
			return (this->ptr - rhs.ptr);
		}

		ptrdiff_t operator+(vectorIterator const &rhs) const
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

	protected:
		pointer ptr;
	};

	template <class T>
	class vectorReverseIterator : public vectorIterator<T>
	{
	public:
		// types aliases for AIterator typenames
		typedef vectorReverseIterator<T> &reference;
		typedef vectorReverseIterator<T> const &const_reference;
		typedef typename vectorIterator<T>::reference type_reference;
		typedef typename vectorIterator<T>::pointer pointer;
		typedef typename vectorIterator<T>::const_pointer const_pointer;

		// default constructor
		vectorReverseIterator() : vectorIterator<T>() {}

		// default constructor
		vectorReverseIterator(pointer inPtr) : vectorIterator<T>(inPtr) {}

		// copy constructor
		vectorReverseIterator(vectorReverseIterator const &src) : vectorIterator<T>(src) {}

		// destructor
		virtual ~vectorReverseIterator() {}

		type_reference operator*()
		{
			vectorIterator<T> tmp = *this;
			return (*--tmp);
		}

		type_reference operator*() const
		{
			vectorIterator<T> tmp = *this;
			return (*--tmp);
		}

		pointer operator->()
		{
			vectorIterator<T> tmp = *this;
			--tmp;
			return (tmp.asPointer());
		}

		const_pointer operator->() const
		{
			vectorIterator<T> tmp = *this;
			--tmp;
			return (tmp.asPointer());
		}

		// pre ++ operator overloading
		reference operator++()
		{
			vectorIterator<T>::operator--();
			return (*this);
		}

		// post ++ operator overloading
		vectorReverseIterator operator++(int)
		{
			vectorReverseIterator iter = *this;
			vectorIterator<T>::operator--();
			return (iter);
		}

		// pre -- operator overloading
		reference operator--()
		{
			vectorIterator<T>::operator++();
			return (*this);
		}

		// post -- operator overloading
		vectorReverseIterator operator--(int)
		{
			vectorReverseIterator iter = *this;
			vectorIterator<T>::operator++();
			return (iter);
		}
	};

	template <typename T>
	class vector
	{

	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T const *const_pointer;
		typedef T &reference;
		typedef T const &const_reference;
		typedef size_t size_type;
		typedef vectorIterator<value_type> iterator;
		typedef vectorIterator<value_type> const const_iterator;
		typedef vectorReverseIterator<value_type> reverse_iterator;
		typedef vectorReverseIterator<value_type> const const_reverse_iterator;

		vector() : _arr(new value_type()), _capacity(1), _size(0) {}

		vector(size_type n, const_reference val = value_type()) : _arr(NULL),
																  _capacity(0),
																  _size(0)
		{
			if (n == 0)
			{
				_arr = new value_type[1];
				_capacity = 1;
				return;
			}
			this->assign(n, val);
		}

		vector(iterator first, iterator last) : _arr(NULL),
												_capacity(0),
												_size(0)
		{
			this->assign(first, last);
		}

		vector(vector const &rhs) : _arr(NULL),
									_capacity(0),
									_size(rhs._size)
		{
			this->reserve(rhs._capacity);
			memcpy(static_cast<void *>(this->_arr), static_cast<void *>(rhs._arr), rhs._size * sizeof(value_type));
		}

		virtual ~vector()
		{
			this->clear();
			delete[] this->_arr;
		}

		vector &operator=(vector const &rhs)
		{
			this->clear();
			if (this->_capacity < rhs._capacity)
				this->reserve(rhs._capacity);
			memcpy(static_cast<void *>(this->_arr), static_cast<void *>(rhs._arr), rhs._size * sizeof(value_type));
			this->_size = rhs._size;
			return (*this);
		}

		// iterators

		iterator begin(void)
		{
			return (iterator(this->_arr));
		}

		const_iterator begin(void) const
		{
			return (const_iterator(this->_arr));
		}

		reverse_iterator rbegin(void)
		{
			return (reverse_iterator(this->_arr + this->_size));
		}

		const_reverse_iterator rbegin(void) const
		{
			return (const_reverse_iterator(this->_arr + this->_size));
		}

		iterator end(void)
		{
			return (iterator(this->_arr + this->_size));
		}

		const_iterator end(void) const
		{
			return (const_iterator(this->_arr + this->_size));
		}

		reverse_iterator rend(void)
		{
			return (reverse_iterator(this->_arr));
		}

		const_reverse_iterator rend(void) const
		{
			return (const_reverse_iterator(this->_arr));
		}

		// Capacity

		size_type size(void) const
		{
			return (this->_size);
		}

		size_type max_size(void) const
		{
			return (std::numeric_limits<long>::max() / sizeof(size_type));
			// needs explanations
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n > this->_size)
			{
				for (size_type i = this->_size; i < n; ++i)
					this->push_back(val);
			}
			else
			{
				for (size_type i = n; i < this->_size; ++i)
					this->pop_back();
			}
		}

		size_type capacity(void) const
		{
			return (this->_capacity);
		}

		bool empty(void) const
		{
			return (this->_size == 0);
		}

		void reserve(size_type n)
		{
			if (n > this->_capacity)
			{
				n = n > this->capacity * 2 ? n : this->_capacity * 2;
				pointer tmp = new value_type[n];
				this->_capacity = n;
				for (size_type i = 0; i < this->_size; i++)
				{
					tmp[i] = this->_arr[i];
				}
				delete [] this->_arr;
				this->_arr = tmp;
			}
		}

		// Element Access
	
		reference operator[](size_type index)
		{
			return (this->_arr[index]);
		}

		const_reference operator[](size_type index) const
		{
			return (this->_arr[index]);
		}

		reference at(size_type index)
		{
			if (index >= this->_size)
				throw std::out_of_range("vector: index is out of range");
			return (this->_arr[index]);
		}

		const_reference at(size_type index) const
		{
			if (index >= this->_size)
				throw std::out_of_range("vector: index is out of range");
			return (this->_arr[index]);
		}

		reference front(void)
		{
			return (this->_arr[0]);
		}

		const_reference front(void) const
		{
			return (this->_arr[0]);
		}

		reference back(void)
		{
			return (this->_arr[this->_size - 1]);
		}

		const_reference back(void) const
		{
			return (this->_arr[this->_size - 1]);
		}

		//Modifiers 
		
		// range (1)	
		void assign(iterator first, iterator last)
		{
			ptrdiff_t diff = last - first;
			if (diff < 0)
				throw std::range_error("vector: invalid range");
			else if (!diff)
				return ;
			size_type count = static_cast<size_type>(diff);
			if (count > this->_capacity)
				this->reserve_no_copy(count);
			for (size_type i = 0; i < count; i++)
			{
				new (&this->_arr[i]) value_type(first[i]);
			}
			if (this->_size > count)
				for (size_type i = count; i < this->_size; i++)
				{
					this->_arr[i].~value_type();
				}
			this->_size = count;
		}

		// fill (2)	
		void assign(size_type n, const value_type& val)
		{
			if (!n)
				return ;
			if (n > this->_capacity)
				this->reserve_no_copy(n);
			for (size_type i = 0; i < n; i++)
			{
				new (&this->_arr[i]) value_type(val);
			}
			if (this->_size > n)
				for (size_type i = n; i < this->_size; i++)
				{
					this->_arr.~value_type();
				}
			this->_size = n;
		}

		void push_back(value_type val)
		{
			if (this->_size + 1 > this->_capacity)
				this->reserve(this->_size + 1);
			new (&this->_arr[this->size++]) value_type(val);
		}
		
		void pop_back()
		{
			if (this->_size)
				this->_arr[--this->size].~value_type();
		}


		// single element (1)	
		iterator insert(iterator position, const value_type& val)
		{
			if (this->_size + 1 > this->_capacity)
				this->reserve(this->_size + 1);
			size_type pos = position.asIndex();
			for (size_t j = this->_size; j > pos; j--)
			{
				new( &this->_arr[j]) value_type(this->_arr[j - 1]); 
			}
			new (&this->_arr[pos]) value_type(val);
			this->_size++;
		}
		
		// fill (2)	
		void insert(iterator position, size_type n, const value_type& val)
		{
			if (!n)
				return ;
			size_type totalRequired = this->_size + n;
			if (totalRequired > this->_capacity)
				this->reserve(totalRequired);
			size_type pos = position.asIndex(this->_arr);
			for (size_t j = this->_size; j > pos; j--)
			{
				new (&this->_arr[j - 1 + n]) value_type(this->_arr[j - 1]);
			}
			this->_size += n;
			while (n--)
			{
				new (&this->_arr[pos + n]) value_type(val);
			}
		}
		
		// range (3)	
		void insert(iterator position, iterator first, iterator last)
		{
			ptrdiff_t diff = last - first;
			if (diff < 0)
				throw std::range_error("vector: invalid range");
			else if (!diff)
				return ;
			size_type count = static_cast<size_type>(diff);
			if (count + this->_size > this->_capacity)
				this->reserve_no_copy(count + this->_size);
			size_type pos = position.asIndex(this->_arr);
			for (size_t j = this->_size; j > pos; j--)
			{
				new (&this->_arr[j - 1 + count]) value_type(this->_arr[j - 1]);
			}
			this->_size += count;
			while (count--)
			{
				new (&this->_arr[pos + count]) value_type(*--last);
			}
		}
		

		void clear()
		{
			while (this->_size != 0)
				this->_arr[this->size - 1].~value_type();
			delete [] this->_arr;
			this->_arr = new value_type[1];
			this->_capacity = 1;
		}
		
	private:
		size_type _size;
		size_type _capacity;
		pointer _arr;

		void	reserve_no_copy(size_type n)
		{
			if (n > this->_capacity)
			{
				delete [] this->_arr;
				n = n > this->capacity * 2 ? n : this->_capacity * 2;
				this->_arr = new value_type[n];
				this->_capacity = n;
				this->_size = 0;
			}
		}
	};  // class vector

	template <typename T>
	bool operator==(vector<T> const &lhs, vector<T> const &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}

	template <typename T>
	bool operator!=(vector<T> const &lhs, vector<T> const &rhs)
	{
		return (!(lhs == rhs));
	}

	template <typename T>
	bool operator<(vector<T> const &lhs, vector<T> const &rhs)
	{
		typename vector<T>::iterator first1 = lhs.begin();
		typename vector<T>::iterator last1 = lhs.end();
		typename vector<T>::iterator first2 = rhs.begin();
		typename vector<T>::iterator last2 = rhs.end();

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

	template <typename T>
	bool operator<=(vector<T> const &lhs, vector<T> const &rhs)
	{
		return (!(rhs < lhs));
	}

	template <typename T>
	bool operator>(vector<T> const &lhs, vector<T> const &rhs)
	{
		return (rhs < lhs);
	}

	template <typename T>
	bool operator>=(vector<T> const &lhs, vector<T> const &rhs)
	{
		return (!(lhs < rhs));
	}

	template <typename T>
	void swap(vector<T> &x, vector<T> &y)
	{
		x.swap(y);
	}
} // namespace ft