/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:02:46 by hcherpre          #+#    #+#             */
/*   Updated: 2023/01/11 18:18:28 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main()
{
  ft::vector<int> vec;
  ft::vector<int> vec2;
  ft::vector<int>::iterator it;
  ft::vector<int>::iterator it2;
  
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  /**********************************/
  vec2.push_back(1);
  vec2.push_back(2);
  vec2.push_back(1);
  vec2.push_back(0);
  vec2.push_back(1);
  vec2.push_back(1);
  /**********************************/
  it = vec.begin();
  it2 = vec2.begin();
  
  vec2.insert((it2 + 2), (it + 1), vec.end());

  for(; it != vec.end(); it++)
    std::cout<<*it<<" ";
  std::cout<<std::endl;
  for(; it2 != vec2.end(); it2++)
    std::cout<<*it2<<" ";
  std::cout<<std::endl;
  return 0;
}
