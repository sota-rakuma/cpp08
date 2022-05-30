/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:44:47 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/31 06:33:26 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template < class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		MutantStack();
		MutantStack(const MutantStack&);
		MutantStack(const Container&);
		~MutantStack();
		MutantStack&	operator=(const MutantStack&);
		iterator				begin();
		const_iterator			begin() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
};

template <typename T, class Container>
MutantStack<T, Container>::MutantStack()
:std::stack<T, Container>()
{
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& another)
:std::stack<T, Container>(another)
{
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const Container& container)
:std::stack<T, Container>(container)
{
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, class Container>
MutantStack<T, Container>&
MutantStack<T, Container>::operator=(const MutantStack<T, Container>& another)
{
	if (this != &another)
	{
		std::stack<T, Container>::operator=(another);
	}
	return (*this);
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end()
{
	return (this->c.end());
}

template<typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rend()
{
	return (this->c.rend());
}

template <typename T, class Container>
typename MutantStack<T,Container>::const_iterator
MutantStack<T, Container>::end() const
{
	return (this->c.end());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rend() const
{
	return (this->c.rend());
}

#endif /* MUTANTSTACK_HPP */
