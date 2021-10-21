#include <iostream>
#include <vector>
using namespace std;
template<typename T,
         template<typename>
         class Container
         >

class XCls {
	private:
		Container<T>c;
};
template<class T>
using Vec = vector<T, allocator<T>>;

int main() {
	XCls<string, Vec>s;
	return 0;
}