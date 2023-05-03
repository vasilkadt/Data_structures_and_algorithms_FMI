#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int K, T, B;
    cin >> K >> T >> B;

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> v;
    int counter = 0;

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        minHeap.push(num);

        if (i % T == 0)
        {
            for (int j = 0; j < K; j++)
            {
                v.push_back(minHeap.top());
                minHeap.pop();
            }
            counter++;
        }

        if (counter == B)
        {
            for (int j = i; j < n; j++)
            {
                int num;
                cin >> num;
                minHeap.push(num);
            }
            break;
        }
    }

    while (!minHeap.empty())
    {
        v.push_back(minHeap.top());
        minHeap.pop();
    }

    for (int i = 0; i < K * B; i++)
    {
        cout << v[i] << " ";
    }
}