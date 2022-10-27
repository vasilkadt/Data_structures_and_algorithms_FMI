#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int N;
	cin >> N;
	vector<int> red;
	vector<int> black;
	for (size_t i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		if (number % 2 == 0)
		{
			red.push_back(number);
		}
		else black.push_back(number);
	}

	for (size_t i = 0; i < red.size(); i++)
	{
		cout << red[i] << "\n";
	}

	for (size_t i = 0; i < black.size(); i++)
	{
		cout << black[i] << "\n";
	}
}