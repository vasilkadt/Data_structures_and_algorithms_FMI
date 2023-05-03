#include <iostream>
#include <queue>
using namespace std;

struct ApplePosition
{
    long long row;
    long long col;

    ApplePosition(long long row, long long col)
    {
        this->row = row;
        this->col = col;
    }
};

bool visited[1000][1000] = { 0 };
int rowDirections[] = { -1, 0, 1, 0 };
int colDirections[] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<ApplePosition> q;
    long long rows, cols, days;
    cin >> rows >> cols >> days;
    long long sum = 0;

    for (int i = 0; i < 2; i++)
    {
        long long row, col;
        row = col = -1;
        cin >> row >> col;
        if (row != -1)
        {
            ApplePosition apple(row - 1, col - 1);
            q.push(apple);
        }
    }

    for (int i = 0; i < days; i++)
    {
        long long size = q.size();
        for (int j = 0; j < size; j++)
        {
            ApplePosition cell = q.front();
            long long x = cell.row;
            long long y = cell.col;

            if (!visited[x][y])
            {
                visited[x][y] = true;
                sum += 1;
            }

            for (int k = 0; k < 4; k++)
            {
                long long newX = x + rowDirections[k];
                long long newY = y + colDirections[k];

                if (newX >= 0 && newY >= 0 && newX < rows && newY < cols && !visited[newX][newY])
                {
                    q.push({ newX, newY });
                    visited[newX][newY] = true;
                    sum += 1;
                }
            }

            q.pop();
        }
    }

    cout << (rows * cols) - sum;
}
