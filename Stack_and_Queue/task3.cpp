#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main()
{
    long long N, number;
    cin >> N;
    deque<long long> burevo;
    queue<long long> sredec;
    queue<long long> resultBurevo;
    queue<long long> resultSredec;
    bool hasPositiveNumber = false;
    bool haveToFight = false;

    for (int i = 0; i < N; i++)
    {
        cin >> number;

        if (number < 0 && !hasPositiveNumber)
        {
            resultSredec.push(number);
        }
        else if (number > 0)
        {
            if (haveToFight)
            {
                while (burevo.size() && sredec.size())
                {
                    if (burevo.back() > abs(sredec.front()))
                    {
                        sredec.pop();
                    }
                    else if (burevo.back() < abs(sredec.front()))
                    {
                        burevo.pop_back();
                    }
                    else if (burevo.back() == abs(sredec.front()))
                    {
                        burevo.pop_back();
                        sredec.pop();
                    }
                }

                if (burevo.empty())
                {
                    while (!sredec.empty())
                    {
                        resultSredec.push(sredec.front());
                        sredec.pop();
                    }
                }
            }
            hasPositiveNumber = true;
            burevo.push_back(number);
            continue;
        }
        else if (number < 0 && hasPositiveNumber)
        {
            sredec.push(number);
            haveToFight = true;
            continue;
        }
    }

    if (haveToFight)
    {
        while (burevo.size() && sredec.size())
        {
            if (burevo.back() > abs(sredec.front()))
            {
                sredec.pop();
            }
            else if (burevo.back() < abs(sredec.front()))
            {
                burevo.pop_back();
            }
            else if (burevo.back() == abs(sredec.front()))
            {
                burevo.pop_back();
                sredec.pop();
            }
        }
        if (burevo.empty())
        {
            while (!sredec.empty())
            {
                resultSredec.push(sredec.front());
                sredec.pop();
            }
        }
    }

    if (burevo.empty() && resultSredec.empty() && resultBurevo.empty())
    {
        cout << '\n';
    }

    while (!burevo.empty())
    {
        resultBurevo.push(burevo.front());
        burevo.pop_front();
    }
    while (!resultSredec.empty())
    {
        cout << resultSredec.front() << " ";
        resultSredec.pop();
    }
    while (!resultBurevo.empty())
    {
        cout << resultBurevo.front() << " ";
        resultBurevo.pop();
    }
}