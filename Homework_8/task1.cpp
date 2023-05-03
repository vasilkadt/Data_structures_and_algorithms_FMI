#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Interval {
    long long start;
    long long neededTime;
    int index;
};

struct Comparator1 {
    bool operator()(const Interval& first, const Interval& second) const
    {
        if (first.start == second.start)
        {
            return first.neededTime > second.neededTime;
        }
        return first.start > second.start;
    }
};

struct Comparator2 {
    bool operator()(const Interval& first, const Interval& second) const
    {
        if (first.neededTime == second.neededTime)
        {
            return first.index > second.index;
        }
        return first.neededTime > second.neededTime;
    }
};


int main()
{
    int N;
    cin >> N;

    priority_queue<Interval, vector<Interval>, Comparator1> starts;
    priority_queue<Interval, vector<Interval>, Comparator2> neededTime;
    vector<int> indexes;

    for (int i = 0; i < N; i++)
    {
        long long t, f;
        cin >> t >> f;
        starts.push({ t, f, i });
    }

    Interval first = starts.top();
    starts.pop();
    long long end = first.start + first.neededTime;
    indexes.push_back(first.index);

    while (!starts.empty() || !neededTime.empty())
    {
        bool isAdd = false;
        if (!starts.empty())
        {
            if (starts.top().start <= end)
            {
                neededTime.push(starts.top());
                starts.pop();
                isAdd = true;
            }
        }

        if (starts.empty() && !neededTime.empty())
        {
            end += neededTime.top().neededTime;
            indexes.push_back(neededTime.top().index);
            neededTime.pop();
            continue;
        }
        else if (!starts.empty() && neededTime.empty())
        {
            end = starts.top().start + starts.top().neededTime;
            indexes.push_back(starts.top().index);
            starts.pop();
            continue;
        }

        if (!isAdd)
        {
            end += neededTime.top().neededTime;
            indexes.push_back(neededTime.top().index);
            neededTime.pop();
        }
    }

    for (int i = 0; i < indexes.size(); i++)
    {
        cout << indexes[i] << " ";
    }
}