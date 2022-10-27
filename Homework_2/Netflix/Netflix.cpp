#include <iostream>
using namespace std;

int main()
{
	string input;
	cin >> input;
	int letters[256] = { 0 };

	for (size_t i = 0; i < input.size(); i++)
	{
		letters[input[i]] += 1;
	}

	for (int i = 0; i < input.size(); i++)
	{
		if (letters[input[i]] == 1)
		{
			cout << i <<" ";
		}
	}
}