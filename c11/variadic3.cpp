#include <iostream>

int maximum(int n) {
	return n;
}
template<typename...Args>

int maximum(int n, Args...args) {
	return std::max(n, maximum(args...));
}

int main() {
	std::cout << maximum(8, 1, -2, 99);
	return 0;
}