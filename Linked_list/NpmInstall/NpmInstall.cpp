#include <iostream>
#include <list>
using namespace std;

list<unsigned long int> lst;
list<unsigned long int>::iterator it_map[1000000];
bool bool_map[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned long int T, N;
	cin >> T >> N;

	unsigned long int counter = 0;
	for (unsigned long int i = 0; i < T; i++)
	{
		unsigned long int request;
		cin >> request;
		
		if (counter == N)
		{
			if (bool_map[request] == 1)
			{
				cout << "true" << "\n";
				lst.erase(it_map[request]);
				lst.push_back(request);
				list<unsigned long int>::iterator itr = lst.end();
				it_map[request] = --itr;
			}
			else
			{
				cout << "false" << "\n";
				unsigned long int element = lst.front();
				bool_map[element] = 0;
				lst.erase(it_map[element]);
				lst.push_back(request);
				list<unsigned long int>::iterator itr = lst.end();
				it_map[request] = --itr;
				bool_map[request] = 1;
			}
		}
		else
		{
			if (bool_map[request] == 1)
			{
				cout << "true" << "\n";
				lst.erase(it_map[request]);
				lst.push_back(request);
				list<unsigned long int>::iterator itr = lst.end();
				it_map[request] = --itr;
			}
			else
			{
				cout << "false" << "\n";
				lst.push_back(request);
				list<unsigned long int>::iterator itr = lst.end();
				it_map[request] = --itr;
				bool_map[request] = 1;
				counter++;
			}
		}
	}
}