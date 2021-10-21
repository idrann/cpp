#include<iostream>
#include<vector> 
using namespace std;

int main()
{
	int** p = new int*[2];
	for(int i = 0; i < 2; i++)
	{
		p[i] = new int[3];
	} 
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			p[i][j] = i * j;
		}
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << p[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
} 
