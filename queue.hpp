/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:49:14 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/18 22:52:53 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "list.hpp"

namespace ft
{
	
	template < typename T, typename Container = ft::list<T> >
	class queue
	{
	public:
		// typenames aliases
		typedef T value_type;
		typedef size_t size_type;
		typedef T* pointer;
		typedef T const * const_pointer;
		typedef T& reference;
		typedef T const & const_reference;

		// default constructor / constr`uctor with parameter
		queue(Container const &c=Container()): c(c) {}
		
		// copy constructor
		queue(queue const &rhs): c(rhs.c) {}
		
		// destructor
		virtual ~queue() {}

		// = operator overloading
		queue &operator=(queue const &rhs) 
		{
			if (this != &rhs)
				this->c = rhs.c;
			return (*this);
		}

		// Member functions

		bool empty(void) const 
		{
			return (this->c.empty());
		}
		size_t size(void) const 
		{
			return (this->c.size());
		}

		reference top(void)
		{
			return (this->c.back());
		}
		
		const_reference top(void) const
		{
			return (this->c.back());
		}

		void push(const_reference val)
		{
			this->c.push_back(val);
		}
		
		void pop(void)
		{
			this->c.pop_back();
		}

		// Non-member function overloads
		// Relational operators
		template<typename ST, typename CT>
		friend bool operator==(queue<ST, CT> const &lhs, queue<ST, CT> const &rhs)
		{
			return (lhs.c == rhs.c);
		}

		template<typename ST, typename CT>
		friend bool operator!=(queue<ST, CT> const &lhs, queue<ST, CT> const &rhs)
		{
			return (lhs.c != rhs.c);
		}

		template<typename ST, typename CT>
		friend bool operator<(queue<ST, CT> const &lhs, queue<ST, CT> const &rhs)
		{
			return (lhs.c < rhs.c);
		}

		template<typename ST, typename CT>
		friend bool operator<=(queue<ST, CT> const &lhs, queue<ST, CT> const &rhs)
		{
			return (lhs.c <= rhs.c);
		}

		template<typename ST, typename CT>
		friend bool operator>(queue<ST, CT> const &lhs, queue<ST, CT> const &rhs)
		{
			return (lhs.c > rhs.c);
		}

		template<typename ST, typename CT>
		friend bool operator>=(queue<ST, CT> const &lhs, queue<ST, CT> const &rhs)
		{
			return (lhs.c >= rhs.c);
		}

	protected:
		Container c;
	}; // class queue
}

#endif // QUEUE_HPP