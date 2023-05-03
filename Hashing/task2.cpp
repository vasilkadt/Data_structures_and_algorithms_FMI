#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main()
{
    int boxSize;
    cin >> boxSize;
    long long maxLenght = 0;
    long long currentIndex = 0;
    map<long long, long long> map;
    queue<int> queue;

    for (int j = 0; j < boxSize; j++)
    {
        long long number;
        cin >> number;

        if (map.count(number) > 0)
        {
            long long indexRepeat = map[number];

            for (int k = currentIndex; k <= indexRepeat; k++)
            {
                long long elementToDelete = queue.front();
                queue.pop();
                map.erase(elementToDelete);
            }

            currentIndex = indexRepeat + 1;
        }

        map[number] = j;
        queue.push(number);

        if (queue.size() > maxLenght)
        {
            maxLenght = queue.size();
        }
    }
    cout << maxLenght;
}