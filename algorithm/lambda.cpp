#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;


int fun(int a, int b) {
	a = a + b;
	auto c = [a](int b) {
		return a * b;
	};
	return a + c(b);
}

int fun1(vector<int>a, int cnt) {
	auto c = count_if(a.begin(), a.end(), [cnt](int a) {
		return a >= cnt;
	});
	return c;
}

int main() {
	int a = 1, b = 2;
	auto sum = [](int a, int b) {
		return a + b;
	};

	int a1[6] = {8, 7, 0, 1, 3, 2};
	vector<int>vec(a1, a1 + 6);

	cout << fun1(vec, 7);
}