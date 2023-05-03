#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Mach
{
	long long min;
	long long max;
};

int main()
{
	long long N, Q;
	cin >> N;
	cin >> Q;
	vector<long long> weights;
	vector<Mach> maches;

	for (long long i = 0; i < N; i++)
	{
		long long weight;
		cin >> weight;
		weights.push_back(weight);
	}

	for (long long i = 0; i < Q; i++)
	{
		Mach mach;
		cin >> mach.min;
		cin >> mach.max;
		maches.push_back(mach);
	}

	sort(weights.begin(), weights.end());

	long long counter = 0;
	for (long long i = 0; i < maches.size(); i++)
	{
		auto lower = lower_bound(weights.begin(), weights.end(), maches[i].min);
		long long lowerIndex = lower - weights.begin();
		auto upper = upper_bound(weights.begin(), weights.end(), maches[i].max);
		long long upperIndex = upper - weights.begin();

		if (lowerIndex >= upperIndex)
		{
			counter = 0;
		}
		else
			counter = upperIndex - lowerIndex;

		cout << counter << "\n";
		counter = 0;
	}
}
