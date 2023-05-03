#include <iostream>
#include <vector>
using namespace std;

void findMissing(vector<int> numbers, int length)
{
	vector<int> temp;
	for (int i = 0; i <= length; i++) 
	{
		temp.push_back(0);
	}

	for (int i = 0; i < length; i++) 
	{
		temp[numbers[i] - 1] = 1;
	}

	int numberToSearch = 0;
	for (int i = 0; i <= length; i++) 
	{
		if (temp[i] == 0)
		{
			numberToSearch = i + 1;
			break;
		}
	}
	cout << numberToSearch;
}

int main()
{
	int n, number;
	std::cin >> n;
	std::vector<int> tickets;

	int counter = 0;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> number;
		if (number > 0)
			tickets.push_back(number);
		else counter++;
	}

	findMissing(tickets, n - counter);
}
