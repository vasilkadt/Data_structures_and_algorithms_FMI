#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> shots;

    int cells, ships, shipLenght;
    cin >> cells >> ships >> shipLenght;

    int maxBoats = (cells + 1) / (shipLenght + 1);

    shots.insert(0);
    shots.insert(cells + 1);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int shoot;
        cin >> shoot;
        shots.insert(shoot);

        int intervalCounter = 0;
        int leftIntervalCounter = 0;
        int rightIntervalCounter = 0;

        auto itprev = shots.find(shoot);
        auto itnext = shots.find(shoot);

        itprev--;
        itnext++;

        intervalCounter = (*itnext - *itprev) / (shipLenght + 1);

        if (shoot - *itprev >= shipLenght)
        {
            leftIntervalCounter = (shoot - *itprev) / (shipLenght + 1);
        }

        if (*itnext - shoot >= shipLenght)
        {
            rightIntervalCounter = (*itnext - shoot) / (shipLenght + 1);
        }

        if (leftIntervalCounter + rightIntervalCounter < intervalCounter)
        {
            maxBoats--;
        }
        if (maxBoats < ships)
        {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;
    return 0;
}