#include <iostream>
#include <deque>

int main()
{
	/* std::lexicographical_compare
	for ( ; first1 != last1 && first2 != last2 ; ++first1, ++first2) {
		if (*first1 < *first2) return true;
		if (*first2 < *first1) return false;
	}
	return first1 == last1 && first2 != last2;
	が使用される。
	つまり、値の違う最初の要素を比較する。要素の短い方が少ない方がtureと見做される。
	*/
	{
		std::deque<int>	a = {8, 2, 3, 4, 5};
		std::deque<int>	b = {3, 4, 5, 6, 7};

		std::cout << std::boolalpha << (a < b) << std::endl;
	}
	{
		std::deque<int>	a = {1, 2, 3, 4, 5};
		std::deque<int>	b = {6, 7, 8, 9, 1};

		std::cout << std::boolalpha << (a < b) << std::endl;
	}
	{
		std::deque<int>	a = {8, 2, 3, 4};
		std::deque<int>	b = {3, 4, 5, 6, 7};

		std::cout << std::boolalpha << (a < b) << std::endl;
	}
	{
		std::deque<int>	a = {3, 5, 3, 4};
		std::deque<int>	b = {3, 4, 5, 6, 7};

		std::cout << std::boolalpha << (a < b) << std::endl;
	}
	{
		std::deque<int>	a = {3, 4, 5, 6};
		std::deque<int>	b = {3, 4, 5, 6, 7};

		std::cout << std::boolalpha << (a < b) << std::endl;
	}
}