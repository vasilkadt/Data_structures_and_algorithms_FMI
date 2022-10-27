#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(unsigned long int mid, vector<unsigned long int> developers, unsigned long int T)
{
    unsigned long int count = 1;
    unsigned long int sum = 0;
    for (unsigned long int i = 0; i < developers.size(); i++)
    {
        if (developers[i] <= mid)
        {
            sum += developers[i];
        }
        else
        {
            return false;
        }

        if (sum > mid) 
        {
            count++;
            sum = developers[i];
        }
    }

    return (count <= T) ? true : false;
}

unsigned long int binarySearch(vector<unsigned long int> developers, unsigned long int T)
{
    unsigned long int start = *max_element(developers.begin(), developers.end());
    unsigned long int end = 0;
    for (unsigned long int i = 0; i < developers.size(); i++)
    {
        end += developers[i];
    }

    unsigned long int answer = 0;
    while (start <= end) 
    {
        unsigned long int mid = (start + end) / 2;

        if (check(mid, developers, T)) 
        {
            end = mid - 1;
            answer = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return answer;
}

int main()
{
	unsigned long int N, T;
	cin >> N;
	cin >> T;
	vector<unsigned long int> developers;

	for (unsigned long int i = 0; i < N; i++)
	{
		unsigned long int developer;
		cin >> developer;
		developers.push_back(developer);
	}

    cout << binarySearch(developers, T);
}