#include <iostream>

auto I = [](int a, int b)->int {
	return a > b ? a : b;
};

int main() {
	int id = 3;
	auto f = [id]() { /*mutable*/
		std::cout << "id:" << id << std::endl;
		++id;
	};
	id = 42;
	f();
	f();
	f();
	std::cout << id << std::endl;
	return 0;
}