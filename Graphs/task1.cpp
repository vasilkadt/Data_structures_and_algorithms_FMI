#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void dfs(unordered_map<long long, unordered_set<long long>>& adj, vector<bool>& visited, unordered_map<long long, long long>& connectedComponents, long long node, long long component)
{
    visited[node] = true;
    connectedComponents[node] = component;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            dfs(adj, visited, connectedComponents, child, component);
        }
    }
}

unordered_map<long long, unordered_set<long long>> adj;
vector<bool> visited(1000001, false);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        long long first, second;
        cin >> first >> second;
        adj[first].insert(second);
        adj[second].insert(first);
    }

    unordered_map<long long, long long> connectedComponents;
    long long component = 0;
    for (auto element : adj)
    {
        if (!visited[element.first])
        {
            dfs(adj, visited, connectedComponents, element.first, component);
            component++;
        }
    }

    long long K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        long long first, second;
        cin >> first >> second;

        if (connectedComponents[first] == connectedComponents[second])
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
}
