/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:23:56 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/27 00:35:04 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <map>

int	main(void)
{
	typedef std::vector<int> int_vec;
	int_vec a(5);
	int_vec::iterator	first = a.begin();
	int_vec::iterator	last = a.end();
	int	val = 1;

	for (;first != last; first++, val++)
	{
		*first = val;
	}

	try
	{
		int_vec::iterator itr = easyfind<int_vec>(a,3);
		std::cout << *itr << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	return (0);
}