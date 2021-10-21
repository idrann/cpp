#include <iostream>
using namespace std;
template<typename T1, typename T2>

auto add(T1 x, T2 y) { /*-> decltype(x + y)*/
	return x + y;
}

int main() {
	cout << add('a', 'b');
	return 0;
}