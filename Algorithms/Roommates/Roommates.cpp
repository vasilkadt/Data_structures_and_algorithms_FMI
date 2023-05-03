#include <iostream>
#include <string>

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		long length;
		std::cin >> length;
		std::string list;
		std::cin >> list;

		int counter = 0;
		for (int j = 0; j < length - 1; j++)
		{
			if (list[j] == list[j + 1])
			{
				counter++;
			}
		}

		std::cout << counter << std::endl;
	}
}
