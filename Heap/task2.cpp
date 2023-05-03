#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);

    int N;
    cin >> N;
    priority_queue<int> minHeap;
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    vector<double> medians;

    int citizen;
    cin >> citizen;
    maxHeap.push(citizen);
    medians.push_back(citizen);

    for (int i = 1; i < N; i++)
    {
        int citizen;
        cin >> citizen;

        if (citizen > maxHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(citizen);
        }
        else
        {
            minHeap.push(citizen);
        }

        if (minHeap.size() - maxHeap.size() >= 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (maxHeap.size() - minHeap.size() >= 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (maxHeap.size() == minHeap.size())
        {
            medians.push_back((double)(minHeap.top() + maxHeap.top()) / 2);
        }
        else if (minHeap.size() > maxHeap.size())
        {
            medians.push_back(minHeap.top());
        }
        else
        {
            medians.push_back(maxHeap.top());
        }
    }

    for (int i = 0; i < medians.size(); i++)
    {
        cout << medians[i] << '\n';
    }
}
