#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using std::cout;
using std::endl;

int main() {
	std::vector<int>a;
	a.push_back(2);
	a.push_back(5);
	/*for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}*/
	cout << a.front() << endl;
	cout << a.back() << endl;
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	return 0;
}