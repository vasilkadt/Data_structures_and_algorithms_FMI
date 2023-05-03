#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;
int main() {
    long long pancackes, cooks;
    cin>>pancackes>>cooks;
    vector<long long> timeForCooks;
    for(int i=0; i<cooks; i++)
    {
        int time;
        cin>>time;
        timeForCooks.push_back(time);
    }

    long long start=1;
    long long end=1e13;
    long long answer = 0;

    while(start<=end)
    {
        long long middle=(start+end)/2;
        long long currentPancakes = 0;
        for (int initialCooker : timeForCooks) {
            currentPancakes += middle / initialCooker;

            if (currentPancakes >= pancackes) {
                break;
            }
        }

        if (currentPancakes >= pancackes) {
            answer=middle;
            end = middle - 1;
        } else{
            start = middle + 1;
        }
    }

    cout<<answer;
}