#include <iostream>
#include <vector>
#include <list>
using namespace std;

void print(vector<int> &a) {
	for (auto it = a.begin(); it != a.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "********************" << endl;
}

int main() {
	/*vector<int>a;
	a.push_back(1);
	cout << a.size() << " " << a.capacity() << endl;
	a.push_back(2);
	cout << a.size() << " " << a.capacity() << endl;
	a.push_back(3);
	cout << a.size() << " " << a.capacity() << endl;
	a.shrink_to_fit();
	cout << a.size() << " " << a.capacity() << endl;
	cout << "-------------------------------" << endl;
	vector<int>b(100);
	cout << b.size() << " " << b.capacity() << endl;
	b.resize(10);
	cout << b.size() << " " << b.capacity() << endl;
	b.resize(200);
	cout << b.size() << " " << b.capacity() << endl;
	std::vector<int> myvector (5);

	int *p = myvector.data();
	*p = 10;
	++p;
	*p = 20;
	p[0] = 100; //p´ËÊ±ÔÚmyvec[1]
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';*/

	vector<int>a{1, 3, 11, 4};
	print(a);
	a.push_back(2);
	print(a);
	a.insert(a.begin() + 2, 3, 9);
	print(a);
}