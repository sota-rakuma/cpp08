/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:47:44 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/29 15:31:38by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iterator>
#include <climits>
#include <algorithm>

Span::NotEnoughElements::NotEnoughElements()
:_msg("do not have enough more elements")
{
}

const char*	Span::NotEnoughElements::what() const throw()
{
	return (_msg);
}

Span::MaxElements::MaxElements()
:_msg("already have max elements stored")
{
}

const char*	Span::MaxElements::what() const throw()
{
	return (_msg);
}

Span::Span()
: _size(0)
#ifdef TEST
,_l_num(0),
_s_num(0)
#endif
{
	_ele = int_mlset();
}

Span::Span(const Span& span)
:_size(span._size)
#ifdef TEST
,_l_num(span._l_num),
_s_num(span._s_num)
#endif
{
	_ele = int_mlset(span._ele.begin(), span._ele.end());
}

Span::Span(unsigned int n)
: _size(n)
#ifdef TEST
,_l_num(0),
_s_num(0)
#endif
{
	_ele = int_mlset();
}

Span::~Span()
{
}

Span&	Span::operator=(const Span& span)
{
	_size = span._size;
	_ele = int_mlset();
	#ifdef TEST
	_l_num = span._l_num;
	_s_num = span._s_num;
	#endif

	/*for (;first != last;first++)
	{
		_ele.insert(*first);
	}*/
	_ele = span._ele;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (_ele.size() == _size)
		throw (MaxElements());
	_ele.insert(n);
}

unsigned int	Span::shortestSpan()
{
	if (_ele.size() < 2)
	{
		throw (NotEnoughElements());
	}

	int					larger_num;
	int					smaller_num;
	unsigned int		shortest = UINT_MAX;
	int_mlset::iterator	first = _ele.begin();
	int_mlset::iterator	last = _ele.end();

	larger_num = *first;
	first++;
	for (;first != last; ++first)
	{
		smaller_num = *first;
		if (static_cast<unsigned int>(larger_num - smaller_num) < shortest)
		{
			shortest = (larger_num - smaller_num);
			#ifdef TEST
			_l_num = larger_num;
			_s_num = smaller_num;
			#endif
		}
		larger_num = smaller_num;
	}
	return (shortest);
}

unsigned int	Span::longestSpan()
{
	if (_ele.size() < 2)
		throw (NotEnoughElements());
	return (*_ele.begin() - *_ele.end());
}

#ifdef TEST
Span::int_mlset&	Span::getEle()
{
	return (_ele);
}

int	Span::getLarger()
{
	return (_l_num);
}

int	Span::getSmaller()
{
	return (_s_num);
}

unsigned int	Span::getSize()
{
	return (_size);
}

#endif