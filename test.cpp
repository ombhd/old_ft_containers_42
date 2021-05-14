#include <list>
#include <iostream>

using namespace std;


template <typename T>
void print_list(std::list<T> &ls, char const *label)
{
	std::cout << "\nstd::list Size: " << ls.size();
	std::cout << "\nlist [" << label << "] contains:";
	if (!ls.size())
		std::cout << "\tnothing";
	for (typename std::list<T>::iterator it = ls.begin(); it != ls.end(); ++it)
	{
		std::cout << "  [ " << *it << " ]";
	}
	std::cout << std::endl;
}

int main() {
	
	list<int> l;
	list<int> x;

	l.push_back(4);
	l.push_back(3);
	l.push_back(2);
	l.push_back(1);
	
	x.push_back(8);
	x.push_back(7);
	x.push_back(6);
	x.push_back(5);
	print_list(x, "x");
	print_list(l, "l");
	list<int>::iterator it = l.end();
	it++;
	std::cout << "*it = " << *it << std::endl;
	l.splice(it, x);
	std::cout << "*it = " << *it << std::endl;
	print_list(l, "l");
	print_list(x, "x");
	


	return 0;
}