#include <iostream>
using namespace std;

void print() {
}
template<typename T, typename... Types>

void print(const T &fir, const Types &... args) {
	cout << fir << endl;
	print(args...);
}

int main() {
	print("hello", 2.1, true, 4, 5);
	return 0;
}