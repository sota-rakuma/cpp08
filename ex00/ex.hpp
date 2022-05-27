#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <class T>
struct EasyFind
{
	typedef typename T::iterator t_itr;
	static t_itr	easyfind(T& container, int num);
};

template <class T>
typename EasyFind<T>::t_itr	EasyFind<T>::easyfind(T& container, int num)
{
	t_itr	res;

	res = std::find(container.begin(), container.end(), num);
	if (res == container.end())
		throw (std::range_error("could not find"));
	return (res);
}

#endif /* EASYFIND_HPP */
