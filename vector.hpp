/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoo <hugoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:33:33 by hugoo             #+#    #+#             */
/*   Updated: 2022/12/13 18:18:41 by hugoo            ###   ########.fr       */
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
        
        	typedef			T			value_type
        	typedef			size_t		size_type
        	typedef			Allocator	allocator_type
			typedef			ptrdiff_t 	difference_type
			typedef			T&			reference
			typedef const	T&			const_reference
			typedef			T*			pointer
			typedef const	T*			const_pointer
			typedef			T*			iterator
			typedef const	T*			const_iterator
			typedef 					reverse_iterator
			typedef						const_reverse_iterator

			

        private :
        
    };

#include "vector.tpp"
}

#endif