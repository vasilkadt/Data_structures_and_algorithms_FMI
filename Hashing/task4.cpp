#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    unordered_map<long long, int> nums, numsBefore;
    vector<long long> keys;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        nums[num]++;
        keys.push_back(num);
    }

    long long counter = 0;
    for (int i = 0; i < n; i++)
    {
        long long firstCounter = 0;
        long long secondCounter = 0;
        if (nums.find(keys[i] * m) == nums.end())
        {
            nums[keys[i]]--;
            numsBefore[keys[i]]++;
            continue;
        }

        if (keys[i] % m == 0)
        {
            firstCounter = numsBefore[keys[i] / m];
        }

        nums[keys[i]]--;
        secondCounter = nums[keys[i] * m];
        numsBefore[keys[i]]++;

        counter += firstCounter * secondCounter;
    }
    cout << counter;
}