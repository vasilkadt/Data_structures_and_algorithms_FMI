#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, k;
    cin >> N >> k;
    deque<long long> people;
    long long sum = 0;
    long long min = INT_MAX;

    for (long long i = 0; i < k; i++)
    {
        long long number;
        cin >> number;
        people.push_back(number);
    }

    deque<long long>::iterator it = min_element(people.begin(), people.end());
    min = *it;
    sum += min;

    for (long long i = k; i < N; i++)
    {
        long long number;
        cin >> number;
        if (people.front() == min)
        {
            people.pop_front();
            people.push_back(number);
            min = *min_element(people.begin(), people.end());
            sum += min;
        }
        else if (number < min)
        {
            people.pop_front();
            people.push_back(number);
            sum += number;
            min = number;
        }
        else
        {
            people.pop_front();
            people.push_back(number);
            sum += min;
        }
    }

    cout << sum;
}