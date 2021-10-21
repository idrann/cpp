#include<iostream>
#include<vector>

using std::cout;
using std::vector;

int main(),
{
	vector<int>a{ 0,1,2,3,4,5,6,7,8,9 };
	a.insert(a.begin(), 13);
	for (auto i : a) cout << i << " " << std::endl;
	vector<int>b(a.begin(), a.end()-2);
	vector<int>::iterator it = b.end() - 1;
	//auto it2 = a.rbegin();
	//const vector<int>::reverse_iterator it2 = a.crbegin()+1;
	cout << *it;
	//cout << *it;
	return 0;
}