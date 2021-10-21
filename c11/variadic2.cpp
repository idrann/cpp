#include <iostream>

namespace adj1 {
	void printf(const char *s) {
		while (*s) {
			if (*s == '%' && *(++s) != '%')
				throw std::runtime_error("Invalid format string");
			std::cout << *s++;
		}
	}
	template<typename T, typename... Args>

	void printf(const char *s, T value, Args...args) {
		while (*s) {
			if (*s == '%' && *(++s) != '%') {
				std::cout << value << std::endl;
				printf(++s, args...);
				return;
			}
			std::cout << *s++;
		}
		throw std::logic_error("extra arguments provided to printf");
	}
}

int main() {
	int *pi = new int;
	adj1::printf("%d%s%p%f\n", 15, "This is Ace", pi, 3.1415926);
	delete pi;
	return 0;
}

