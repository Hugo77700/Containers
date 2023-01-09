/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:18:31 by hcherpre          #+#    #+#             */
/*   Updated: 2023/01/09 14:38:03 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include "vector.hpp"

namespace ft
{

template <class T, T v>

struct integral_constant 
{
  static const T value = v;
  typedef T value_type;
  typedef integral_constant<T,v> type;
  
  constexpr operator T() { return v; }
};

template <class T> struct is_integral
constexpr operator value_type() {return value};

}

#endif