#include <iostream>
#include <memory>
using std::allocator;

int main() {
	int *p = allocator<int>().allocate(512, (int *)0);
	allocator<int>().deallocate(p, 512);
	return 0;

}