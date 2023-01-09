/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:17:35 by hcherpre          #+#    #+#             */
/*   Updated: 2023/01/09 14:14:00 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <string>
#include <iostream>
#include <iterator>
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft
{

template <typename T, typename Allocator = std::allocator<T> >

class vector
{
	public :
	
		typedef			T								value_type;
		typedef			size_t							size_type;
		typedef			Allocator						allocator_type;
		typedef			ptrdiff_t 						difference_type;
		typedef			value_type&						reference;
		typedef const	value_type&						const_reference;
		typedef	typename	Allocator::pointer			pointer;
		typedef typename	Allocator::const_pointer	const_pointer;
		typedef			T*								iterator;
		typedef const	T*								const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	private :

		allocator_type	_alloc;
		size_t 			_capacity;
		pointer			_begin;
		size_t			_size;

	public :

		explicit
		vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _begin(NULL), _size(0)
		{};
		
		explicit
		vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n), _begin(_alloc.allocate(n)), _size(n)
		{
			for(size_t i = 0; i < n; i++)
				_alloc.construct(_begin + i, val);
		};
		
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(std::distance(first, last)), _begin(_alloc.allocate(std::distance(first, last))), _size(std::distance(first, last))
		{
			for(size_t i = 0; first != last; first++, i++)
				_alloc.construct(_begin + i, *first);
				
		}
		
		vector (const vector& x) : _alloc(x._alloc), _capacity(x._capacity), _begin(_alloc.allocate(x._capacity)), _size(x._size)
		{
			for(size_t i = 0; i < x._size; i++)
				_alloc.construct(_begin + i, *(x._begin + i));
		}
		
		~vector()
		{
			destroy_vector();
		}
		
		vector& operator=(const vector& x)
		{
			if (this == &x)
				return (*this);
			destroy_vector();
			_alloc = x._alloc;
			_capacity = x._capacity;
			_begin = _alloc.allocate(x._capacity);
			_size = x._size;
			for(size_t i = 0; i < x._size; i++)
				_alloc.construct(_begin + i, *(x._begin + i));
			return (*this);
		}
		
	private :
	
	void	destroy_vector()
		{
			if (_size)
			{
				for(size_t i = 0; i < _size; i++)
					_alloc.destroy(_begin + i);
				_alloc.deallocate(_begin, _capacity);
			}
		}

	public :

/*******************ITERATORS**************************
******************************************************/	
	
		iterator begin()
		{
			return(_begin);
		}
		
		const_iterator begin() const
		{
			return(const_iterator(_begin));
		}

		iterator	end()
		{
			return(_begin + _size);
		}

		iterator	end() const
		{
			return(const_iterator(_begin + _size));
		}

		reverse_iterator rbegin()
		{
			return(reverse_iterator(_begin + _size));
		}
		
		const_reverse_iterator rbegin() const
		{
			return(const_reverse_iterator(_begin + _size));
		}
		
		reverse_iterator rend()
		{
			return(reverse_iterator(_begin));
		}
		
		const_reverse_iterator rend() const
		{
			return(const_reverse_iterator(_begin));
		}

/*******************CAPACITY**************************
*****************************************************/	

		size_type	capacity() const
		{
			return (_capacity);
		}
		
		bool	empty() const
		{
			if (_size == 0)
				return (1);
			return (0);
		}

		size_type size() const
		{
			return (_size);
		}

		size_type max_size() const
		{
			return (_alloc.max_size());
		}

		void reserve(size_type n)
		{
			if (n > _alloc.max_size())
				throw std::length_error("vector::reserve");
			else if (n > _capacity)
			{
				pointer	tmp = _alloc.allocate(n);
				for(size_t i = 0; i < _size; i++)
					_alloc.construct(tmp + i, *(_begin + i));
				destroy_vector();
				_begin = tmp;
				_capacity = n;
			}
		}
		
		void resize(size_type n, value_type val = value_type())
		{
			if (n < _size)
				erase(_begin + n, end());
			else
			{
				if (n > _capacity)
				{
					if (_capacity * 2 > n)
						reserve(_capacity * 2);
					else
						reserve(n);
				}
				for(; _size < n; _size++)
					_alloc.construct(_begin + _size, val);
			}
		}
		
		
/*******************ELEMENT ACCESS**************************
***********************************************************/	
		
		T& operator[](size_t pos)
		{
			return(*(_begin + pos));
		}
		
		T&	at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("vector::at\n");
			return(*(_begin + n));
		}

		T&	front()
		{
			return(*(_begin));
		}

		T&	back()
		{
			return(*(_begin + (_size - 1)));
		}
		
/*******************MODIFIERS**************************
******************************************************/	

		void	clear()
		{
			if (_size == 0)
				return ;
			for(size_t i = 0; i < _size; i++)
				_alloc.destroy(_begin + i);
		}

		iterator erase(iterator position)
		{
			iterator pos_start = position;
			for(; position + 1 != end(); position++)
			{
				_alloc.destroy(position);
				_alloc.construct(position, *(position + 1));
			}
			_alloc.destroy(position);
			_size -= 1;
			return (pos_start);
		}

		iterator erase(iterator first, iterator last)
		{
			for(; first != last; last--)
				erase(first);
			return(first);
		}

		void assign (size_type n, const value_type& val)
		{
			reserve(n);
			if (_capacity)
				(*this).clear();
			for (size_t j = 0; j < n; j++)
				_alloc.construct(_begin + j, val);
			_size = n;
		}

		template <class InputIterator>
		void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
		{
			reserve(std::distance(first, last));
			if(_capacity)
				(*this).clear();
			for (size_t i = 0; first != last; first++, i++)
				_alloc.construct(_begin + i, *first);
			_size = std::distance(first, last);
		}

		void push_back (const value_type& val)
		{
			if (_size + 1 >= _capacity)
			{
				if (_capacity == 0)
					reserve(1);
				else
					reserve(_capacity * 2);
			}
			_alloc.construct((_begin + _size), val);
			_size += 1;
		}

		void pop_back()
		{
			_size += 1;
			_alloc.destroy(_begin + _size);
		}

		void swap (vector& x)
		{
			allocator_type	tmp_alloc = _alloc;
			size_t 			tmp_capacity = _capacity;
			pointer			tmp_begin = _begin;
			size_t			tmp_size = _size;


			_alloc = x._alloc;
			_capacity = x._capacity;
			_begin = x._begin;
			_size = x._size;

			x._alloc = tmp_alloc;
			x._capacity = tmp_capacity;
			x._begin = tmp_begin;
			x._size = tmp_size;
		}
};

}

#endif
