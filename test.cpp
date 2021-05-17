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

class test
{
public:
	int a;
	int b;
	int *ptr;
	test(/* args */):ptr(NULL){}
	test & operator=(test const &rhs)
	{
		a = rhs.a;
		b = rhs.b;
		return *this;
	}
	~test(){ delete [] ptr; ptr = NULL; std::cout << "destructed" << std::endl;}
};




int main() {
	
	// list<int> l;
	// list<int> x;

	// l.push_back(4);
	// l.push_back(3);
	// l.push_back(2);
	// l.push_back(1);
	
	// x.push_back(8);
	// x.push_back(7);
	// x.push_back(6);
	// x.push_back(5);
	// print_list(x, "x");
	// print_list(l, "l");
	// list<int>::iterator it = l.end();
	// it++;
	// std::cout << "*it = " << *it << std::endl;
	// l.splice(it, x);
	// std::cout << "*it = " << *it << std::endl;
	// print_list(l, "l");
	// print_list(x, "x");
	
	// for (size_t i = 0; i < 0; i++)
	// {
	// 	std::cout << "/* message */" << std::endl;
	// }
	test obj;
	obj.a = 1;
	obj.b = 1;
	test obj1;
	obj1.a = 2;
	obj1.b = 2;
	// obj = obj1;
	// arr[0]=obj;
	test *arr = new test[2];
	std::cout << "/* message */" << std::endl;
	arr[0].ptr = new int[2];
	arr[0].ptr[0] = 1337;
	arr[0].~test();
	arr[0].~test();
	std::cout << "/* message */" << std::endl;
	delete [] arr;
	return 0;
}