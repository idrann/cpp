#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;


void print(int *p, int n) {
	for (int i = 0; i < n; i++) {
		cout << i << " ";
	}
}

int main() {
	int a[6] = {10, 1, 2, 3, 81, 2};
	double f[6] = {1.1, 1.0, 3.0, 4.0, 6.0, 7.0};
	vector<double>vec3(f, f + 6);
	vector<int>vec(a, a + 6);
	vector<int>b(a, a + 6);
	b.push_back(3);
	auto c = equal(vec.begin(), vec.end(), b.begin());
	auto sum = accumulate(vec3.begin(), vec3.end(), 0);
	cout << sum;
	return 0;
}
