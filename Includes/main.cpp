/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:02:46 by hcherpre          #+#    #+#             */
/*   Updated: 2023/01/10 17:50:48 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main()
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

  return 0;
}

    // ft::vector<int> foo;
    // ft::vector<int>::iterator it;

    // foo.push_back(8);
    // foo.assign(7, 100);
    // std::cout<<"size foo = "<<foo.size()<<std::endl;
    // it = foo.begin();
    // for(; it != foo.end(); it++)
    //     std::cout<<*it<<std::endl;
        
    // std::cout<<"------------------------------------------------"<<std::endl;
    
    // ft::vector<int> bar(20);
    // std::cout<<"size bar 1 = "<<bar.size()<<std::endl;
    // ft::vector<int>::iterator it2;
    // bar = foo;
    // bar.pop_back();
    // bar.push_back(500);
    // std::cout<<"size bar 2 = "<<bar.size()<<std::endl;
    // std::cout<<"capacity bar 2 = "<<bar.capacity()<<std::endl;
    
    // it2 = bar.begin();
    // for(; it2 != bar.end(); it2++)
    //     std::cout<<*it2<<std::endl;