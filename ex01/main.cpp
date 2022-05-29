/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:22:04 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/30 03:14:06 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NONE "\033[0m"
#define RED "\033[38;5;160m"
#define GREEN "\033[38;5;82m"
#define SKBL "\033[38;5;033m"
#define PRPL "\033[38;5;129m"
#define YLLW "\033[38;5;226m"

#include <iostream>
#include <functional>
#include <vector>
#ifndef __MACH__
#include <climits>
#include <algorithm>
#endif
#include "Span.hpp"

template<typename T>
static void	test(unsigned int n, typename T::iterator first, typename T::iterator last)
{
	Span sp(n);

	try
	{
		for (; first != last; first++)
		{
			sp.addNumber(*first);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NONE << '\n';
	}

	try
	{
		std::cout << "longest span : " SKBL << sp.longestSpan()
				<< NONE << std::endl;
		#ifdef TEST
		Span::int_mlset::iterator	max =\
			std::max_element(sp.getEle().begin(), sp.getEle().end());
		Span::int_mlset::iterator	min =\
			std::min_element(sp.getEle().begin(), sp.getEle().end());
		std::cout << "max_element: " YLLW << *max << NONE << std::endl;
		std::cout << "min_element: " YLLW << *min << NONE << std::endl;
		#endif
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NONE << '\n';
	}

	try
	{
		std:: cout << "shortest span : " PRPL << sp.shortestSpan()
				<< NONE << std::endl;
		#ifdef TEST
		std::cout << "larger number  : " YLLW << sp.getLarger() << NONE << std::endl;
		std::cout << "smaller number : " YLLW << sp.getSmaller() << NONE << std::endl;
		#endif
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NONE << '\n';
	}
}

int main()
{
	std::cout << GREEN "a test given by pdf" NONE << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << GREEN "test when n == 0" NONE << std::endl;
	typedef std::vector<int> int_vec;
	int_vec a(1);
	test<int_vec>(0, a.begin(), a.end());
	std::cout << GREEN "test when Span's size is only one" NONE << std::endl;
	test<int_vec>(1, a.begin(), a.end());

	std::cout << GREEN "test when given from 0 to 10000" NONE << std::endl;
	int_vec	b(10000);
	for (size_t i = 1; i <= 10000; i++)
	{
		b.at(i - 1) = i;
	}
	test<int_vec>(10000, b.begin(), b.end());

	std::cout << GREEN "test when given from -10000 to 0" NONE << std::endl;
	for (size_t i = 1; i <= 10000; i++)
	{
		b.at(i - 1) = i * (-1);
	}
	test<int_vec>(10000, b.begin(), b.end());

	std::cout << GREEN "test given from INT_MIN to INT_MAX" NONE << std::endl;
	int_vec	c(3);
	c.at(0) = INT_MIN;
	c.at(1) = INT_MIN;
	c.at(2) = INT_MAX;
	test<int_vec>(3, c.begin(), c.end());

	return (0);
}
