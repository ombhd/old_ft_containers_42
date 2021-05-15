#include <stdlib.h>
#include <iostream>
#include "Node.hpp"

int main() {

	void *p;
	size_t size = 0;
	size_t num = 0;
	int inc = sizeof(ft::Node<int>) * 100;
	while(1) {
	    p = calloc(1, inc);
	    size += inc;
	    num += 100;
	    std::cout << "Allocated nodes: " << num << " Nodes"<< std::endl;
	    std::cout << "Allocated bytes: " << size/(1024 * 1024) << " MB"<< std::endl;
	    if(!p) break;
	    
    	}
}
