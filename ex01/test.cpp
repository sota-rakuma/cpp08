#include <deque>
#include <set>
#include <iostream>
#include <iterator>

int main(void)
{
	int	arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	typedef std::deque<int>	int_deq;
	int_deq	*a = new int_deq(std::begin(arr), std::end(arr));

	int_deq::iterator	last = a->end();

	std::cout << std::distance(a->begin(), last) << std::endl;

	std::cout << "first pointer: " << &*a->begin() << std::endl;
	std::cout << "last pointer : " << &*a->end() << std::endl;
	a->push_back(100);
	std::cout << "first pointer: " << &*a->begin() << std::endl;
	std::cout << "last pointer : " << &*a->end() << std::endl;

	std::cout << std::distance(a->begin(), last) << std::endl;
	std::cout << std::distance(a->begin(), a->end()) << std::endl;

	typedef std::multiset<int> int_mlset;
	int_mlset	b(std::begin(arr), std::end(arr));

	int_mlset::iterator	l_ml = b.end();

	std::cout << std::distance(b.begin(), l_ml) << std::endl;

	std::cout << "first pointer: " << &*b.begin() << std::endl;
	std::cout << "last pointer : " << &*b.end() << std::endl;
	b.insert(100);
	std::cout << "first pointer: " << &*b.begin() << std::endl;
	std::cout << "last pointer : " << &*b.end() << std::endl;

	std::cout << std::distance(b.begin(), l_ml) << std::endl;
	std::cout << std::distance(b.begin(), b.end()) << std::endl;

	int_mlset	d;
	d.insert(a->begin(), a->end());
}
