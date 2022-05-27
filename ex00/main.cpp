/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:23:56 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/27 03:27:586srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

#define NONE "\033[0m"
#define RED "\033[38;5;160m"
#define GREEN "\033[38;5;82m"


template <typename T>
void	test_easy(T container, int num)
{
	try
	{
		typename T::iterator itr = easyfind<T>(container ,num);
		std::cout << GREEN << *itr << " is found" NONE << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NONE << '\n';
	}
}

template <typename T>
void	const_test_easy(T const container, int num)
{
	try
	{
		typename T::const_iterator itr = easyfind<T>(container ,num);
		std::cout << GREEN << *itr << " is found" NONE << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NONE << '\n';
	}
}

int	main(void)
{
	int	arr[5] = {1, 2, 3, 4, 5};

	typedef std::vector<int> int_vec;
	int_vec vec(std::begin(arr), std::end(arr));

	test_easy(vec, 3);
	test_easy(vec, 6);

	typedef std::list<int> int_list;
	int_list list(std::begin(arr), std::end(arr));

	test_easy(list, 3);
	test_easy(list, 6);

	typedef std::deque<int> int_deq;
	int_deq deq(std::begin(arr), std::end(arr));

	test_easy(deq, 3);
	test_easy(deq, 6);

	std::string	str("12345");

	test_easy(str, 3);
	test_easy(str, 6);
	test_easy(str, '3');
	test_easy(str, '6');

	typedef std::set<int> int_set;
	int_set	set(std::begin(arr), std::end(arr));

	test_easy(set, 3);
	test_easy(set, 6);


	typedef const std::vector<int> const_int_vec;
	const_int_vec const_vec(std::begin(arr), std::end(arr));

	const_test_easy(const_vec, 3);
	const_test_easy(const_vec, 6);

	typedef const std::list<int> const_int_list;
	const_int_list const_list(std::begin(arr), std::end(arr));

	const_test_easy(const_list, 3);
	const_test_easy(const_list, 6);

	typedef const std::deque<int> const_int_deq;
	const_int_deq const_deq(std::begin(arr), std::end(arr));

	const_test_easy(const_deq, 3);
	const_test_easy(const_deq, 6);

	const std::string	const_str("12345");

	const_test_easy(const_str, 3);
	const_test_easy(const_str, 6);
	const_test_easy(const_str, '3');
	const_test_easy(const_str, '6');

	typedef const std::set<int> const_int_set;
	const_int_set	const_set(std::begin(arr), std::end(arr));

	const_test_easy(const_set, 3);
	const_test_easy(const_set, 6);

	return (0);
}