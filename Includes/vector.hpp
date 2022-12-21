/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:17:35 by hcherpre          #+#    #+#             */
/*   Updated: 2022/12/21 18:17:39 by hcherpre         ###   ########.fr       */
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
			
			T& operator[](size_t pos)
			{
				return(*(_begin + pos));
			}
		
		private :
		
			_destroy_vector()
			{
				if (!_size)
					return ;
				for(size_t i = 0; i < _size; i++)
					_alloc.destroy(_begin + i);
				_alloc.deallocate(begin, _capacity);
			}
    };

}

#endif