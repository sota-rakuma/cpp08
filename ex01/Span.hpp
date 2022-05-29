/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:47:34 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/30 03:07:00 by srakuma          ###   ########.fr       */
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
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		#ifdef TEST
		int_mlset&	getEle();
		int			getLarger();
		int			getSmaller();
		#endif
};

#endif /* SPAN_HPP */
