#include <iostream>
#include <climits>
#include <vector>

std::vector<int> inputArr(int length)
{
	std::vector<int> numbers;
	int number;
	for (int i = 0; i < length; i++)
	{
		std::cin >> number;
		numbers.push_back(number);
	}
	return numbers;
}

int AnalyzeArray(std::vector<int> vector, int length)
{
	int profit = 0;
	int min = INT_MAX;

	for (size_t i = 0; i < length - 1; i++)
	{
		if (vector[i] < min)
		{
			min = vector[i];
		}

		if (i + 2 == length && vector[i] < vector[i + 1])
		{
			profit += vector[i + 1] - min;
		}
		else
		{
			if (vector[i] > vector[i + 1])
			{
				profit += vector[i] - min;
				min = INT_MAX;
			}
		}
	}

	return profit;
}

int main()
{
	std::vector<int> v;
	int length;
	std::cin >> length;
	std::cout << AnalyzeArray(inputArr(length), length);
}