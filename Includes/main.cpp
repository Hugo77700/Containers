/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:02:46 by hcherpre          #+#    #+#             */
/*   Updated: 2023/01/06 18:03:39 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main()
{
    ft::vector<int> foo;
    ft::vector<int>::iterator it;

    foo.push_back(8);
    foo.assign(7, 100);
    it = foo.begin();
    for(; it != foo.end(); it++)
        std::cout<<*it<<std::endl;
}