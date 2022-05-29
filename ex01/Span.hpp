/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:47:34 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/30 03:50:57 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <set>
#include <stdexcept>
#include "Greater.hpp"

class Span
{
	private:
		unsigned int						_size;
		std::multiset<int, Greater<int> >	_ele;
		Span();
		#ifdef TEST
		int									_l_num;
		int									_s_num;
		#endif
	public:
		class NotEnoughElements : public std::exception
		{
			const char* _msg;
			public:
				NotEnoughElements();
				virtual const char*	what() const throw();
		};
		class	MaxElements : public std::exception
		{
			const char* _msg;
			public:
				MaxElements();
				virtual const char*	what() const throw();
		};
		typedef std::multiset<int, Greater<int> > int_mlset;
		Span(const Span&);
		Span(unsigned int);
		~Span();
		Span&			operator=(const Span&);
		void			addNumber(int);
		template <typename T>
		void			addNumber(typename T::iterator, typename T::iterator);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		#ifdef TEST
		int_mlset&	getEle();
		int			getLarger();
		int			getSmaller();
		#endif
};

template<typename T>
void	Span::addNumber(typename T::iterator first, typename T::iterator last)
{
	typename T::iterator	tmp = first;
	unsigned int			size = 0;
	for (; tmp != last; tmp++)
	{
		size++;
	}
	if (_size < size)
	{
		for (; size != _size; size--, last--) ;
		_ele.insert(first, last);
		throw (MaxElements());
	}
	_ele.insert(first, last);
}

#endif /* SPAN_HPP */
