/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:17:35 by hcherpre          #+#    #+#             */
/*   Updated: 2023/01/04 18:09:44 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <string>
#include <iostream>
#include <iterator>

namespace ft
{

template <typename T, typename Allocator = std::allocator<T>>

class vector
{
	public :
	
		typedef			T							value_type
		typedef			size_t						size_type
		typedef			Allocator					allocator_type
		typedef			ptrdiff_t 					difference_type
		typedef			value_type&					reference
		typedef const	value_type&					const_reference
		typedef			Allocator::pointer			pointer
		typedef const	Allocator::const_pointer	const_pointer
		typedef			T*							iterator
		typedef const	T*							const_iterator
		typedef 									reverse_iterator
		typedef										const_reverse_iterator

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
			_destroy_vector();
		}
		
		vector& operator=(const vector& x)
		{
			if (this = &cpy)
				return (*this);
			_destroy_vector();
			_alloc = x._alloc;
			_capacity = x._capacity;
			_begin = _alloc.allocate(x._capacity);
			_size = x._size;
			for(size_t i = 0; i < x._size; i++)
				_alloc.construct(_begin + i, *(x._begin + i));
			return (*this);
		}
		
	private :
	
		_destroy_vector()
		{
			if (!_size)
				return ;
			for(size_t i = 0; i < _size; i++)
				_alloc.destroy(_begin + i);
			_alloc.deallocate(_begin, _capacity);
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
			if (!_size)
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
				for(size_t i = 0; i < x._size; i++)
					_alloc.construct(tmp + i, *(_begin + i));
				_destroy_vector();
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
				if (n < _capacity)
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
				throw std::exception::out_of_range();
			return(*(_begin + pos));
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
			if (!_size)
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
};

}

#endif
