#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> masks;
    int num;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        masks.insert(num);

        for (int j = 0; j < num; j++)
        {
            if ((num | j) == num)
            {
                masks.insert(j);
            }
        }
    }

    cout << masks.size();
}