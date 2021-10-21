#include <iostream>
#include <list>
#include <algorithm>
//using namespace std;
using std::list;

int main() {
	list<int>a{1, 2, 3, 4, 5};
	auto ite = find(a.begin(), a.end(), 4);
	std::cout << *ite;
	return 0;
}