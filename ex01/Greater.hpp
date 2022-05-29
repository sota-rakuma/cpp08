/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Greater.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:20:12 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/29 23:16:45 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GREATER_HPP
#define GREATER_HPP

#include <cstring>

template <class T>
class Greater
{
	public:
		bool	operator()(const T& a, const T& b);
};

template <class T>
bool	Greater<T>::operator()(const T& a, const T& b)
{
	return (a > b);
}

#endif /* GREATER_HPP */
