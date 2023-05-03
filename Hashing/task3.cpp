#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string first, second;
    cin >> first >> second;

    int maxCounter = 0;
    for (int i = 0; i < first.size(); i++)
    {
        for (int j = 0; j < second.size(); j++)
        {
            if (first[i] != second[j])
            {
                continue;
            }

            int counter = 0;
            int countIndex = i;
            while (first[countIndex] == second[j])
            {
                counter++;
                countIndex++;
                j++;
            }

            maxCounter = max(counter, maxCounter);
        }
    }

    cout << maxCounter;
}
