#include <iostream>
#include <complex>
#include <tuple>

int main() {
	std::tuple<int, int, int>t(1, 31, 41);
	std::cout << sizeof(std::string) << std::endl;
	std::cout << sizeof(double) << std::endl;
	std::cout << sizeof(float) << std::endl;
	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(std::complex<double>) << std::endl;
	std::cout << sizeof(t) << std::endl;
	std::cout << std::get<1>(t) << std::endl;
	typedef std::tuple<int, float, std::string> tp;
	std::cout << std::tuple_size<tp>::value << std::endl;
	return 0;
}