/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:44:21 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/31 06:31:35 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define NONE "\033[0m"
#define RED "\033[38;5;160m"
#define GREEN "\033[38;5;82m"
#define SKBL "\033[38;5;033m"
#define PRPL "\033[38;5;129m"
#define YLLW "\033[38;5;226m"

int main()
{
	typedef std::deque<int>	int_deq;
	{
		std::cout << GREEN "test given by PDF" NONE << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << GREEN "test in case of deque" NONE << std::endl;
		int_deq deque;
		deque.push_back(5);
		deque.push_back(17);
		std::cout << deque.back() << std::endl;
		deque.pop_back();
		std::cout << deque.size() << std::endl;
		deque.push_back(3);
		deque.push_back(5);
		deque.push_back(737);
		deque.push_back(0);
		int_deq::iterator it = deque.begin();
		int_deq::iterator ite = deque.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << GREEN "some standard test" NONE << std::endl;
		int_deq		a;
		a.push_back(100);
		MutantStack<int>	b(a);

		std::list<int> aa;
		aa = std::list<int>(a.begin(), a.end());
		exit(0);

		MutantStack<int, std::list<int> >c(b);
		std::cout << *(b.begin()) << std::endl;
		std::cout << *(c.begin()) << std::endl;
		MutantStack<int>	l;
		MutantStack<int>	m;

		l.push(5);
		l.push(17);
		c = l;
		std::cout << *(c.begin()) << std::endl;
		MutantStack<int>::const_iterator	c_it = l.begin();
		MutantStack<int>::const_iterator	c_ite = l.end();
		for (;c_it != c_ite; c_it++)
		{
			std::cout << *c_it << std::endl;
		}

		std::cout << std::endl;
		MutantStack<int>::const_reverse_iterator	cr_it = l.rbegin();
		MutantStack<int>::const_reverse_iterator	cr_ite = l.rend();
		for (;cr_it != cr_ite; cr_it++)
		{
			std::cout << *cr_it << std::endl;
		}
		m = l;
		std::cout << "\n" << *(m.begin()) << std::endl;
	}
	return 0;
}