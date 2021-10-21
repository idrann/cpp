#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iterator>
using std::placeholders::_1;

using namespace std;
bool check_size(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

int main() {
	vector<string>str;
	str.push_back("hello");
	str.push_back("world");
	str.push_back("uestc");
	str.push_back("chinese");
	str.push_back("republic");
	//auto check6 = bind(check_size, _1, 8);
	//auto wc = find_if(str.begin(), str.end(), check6);
	ostream_iterator<string>out_iter(cout, " ");
	copy(str.rbegin(), str.rend(), out_iter);
	cout << endl;
	return 0;
}