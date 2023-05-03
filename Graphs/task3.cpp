#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

void bfs(int N, int K, set<pair<int, int>>& vertex, vector<int>& output)
{
    vector<bool> visited(N, false);
    queue<int> queue;
    queue.push(K);
    visited[K - 1] = true;
    int level = 0;
    int visitedVertex = 1;

    while (!queue.empty() && visitedVertex < N)
    {
        int currentSize = queue.size();
        level++;

        while (currentSize > 0)
        {
            int currentNode = queue.front();
            queue.pop();
            for (int i = 1; i <= N; i++)
            {
                if (i != currentNode && !visited[i - 1] && vertex.find({ currentNode, i }) == vertex.end())
                {
                    visited[i - 1] = true;
                    queue.push(i);
                    output[i - 1] = level;
                    visitedVertex++;
                }

                if (visitedVertex == N)
                {
                    return;
                }
            }
            currentSize--;
        }
    }
}

int main()
{
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int N, M;
        cin >> N >> M;
        set<pair<int, int>> vertex;

        for (int j = 0; j < M; j++)
        {
            int first, second;
            cin >> first >> second;
            vertex.insert({ first, second });
            vertex.insert({ second, first });
        }

        int K;
        cin >> K;
        vector<int> output(N, 0);

        bfs(N, K, vertex, output);

        for (int j = 0; j < output.size(); j++)
        {
            if (j == K - 1)
            {
                continue;
            }

            if (output[j] == 0)
            {
                cout << -1;
            }
            else
            {
                cout << output[j] << " ";
            }
        }

        cout << "\n";
    }
}