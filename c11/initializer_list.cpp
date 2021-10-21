#include <iostream>
#include <algorithm>

void print(std::initializer_list<int> vals) {
	for (auto p = vals.begin(); p != vals.end(); ++p) {
		std::cout << *p << "\n";
	}
}

int main() {
	print({1, 2, 3, 4, 5});
	std::cout << std::max({1, 2, 3, 4, 96});

	return 0;
}