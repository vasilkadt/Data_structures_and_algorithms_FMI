#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long ternarySearch(long long left, long long right, long long counter, long long index)
{
	if (right == left) return counter;

	long long mid1 = (2 * left + right) / 3;
	long long mid2 = (left + 2 * right) / 3;

	if (mid1 > index)
	{
		return ternarySearch(left, mid1, ++counter, index);
	}
	else if (index >= mid1 + 1 && index <= mid2)
	{
		return counter;
	}
	else
	{
		return ternarySearch(mid2 + 1, right, ++counter, index);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long P;
	cin >> P;
	long long N;
	cin >> N;
	vector<long long> indexes;

	long long allFriends = pow(3, P);

	for (long long i = 0; i < N; i++)
	{
		long long index;
		cin >> index;
		indexes.push_back(index);
	}

	for (long long i = 0; i < indexes.size(); i++)
	{
		long long depth = ternarySearch(1, allFriends, 1, indexes[i]);
		if (depth > 0)
		{
			cout << depth << "\n";
		}
	}
}
