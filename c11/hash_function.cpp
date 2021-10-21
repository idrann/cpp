#include <iostream>

using namespace std;

int main() {
	void *pi = (void *)(new int (100));
	cout << hash<int>()(123) << endl;
	cout << hash<long>()(123L) << endl;
	cout << hash<string>()(string("hello")) << endl;
	cout << hash<const char *>()("hello") << endl;
	return 0;
}