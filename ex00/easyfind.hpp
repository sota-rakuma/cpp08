#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T& container, int num)
{
	typename T::iterator res;

	res = std::find(container.begin(), container.end(), num);
	if (res == container.end())
		throw (std::range_error("could not find"));
	return (res);
}

#endif /* EASYFIND_HPP */
