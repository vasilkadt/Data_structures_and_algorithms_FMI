#include <iostream>
#include <list>
#include <map>
#include <set>
using namespace std;

void dfs(map<char, set<char>>& graph, map<char, bool>& visited, list<char>& sortedNodes, char node)
{
    visited[node] = true;

    for (auto child : graph[node])
    {
        if (!visited[child])
        {
            dfs(graph, visited, sortedNodes, child);
        }
    }

    sortedNodes.push_front(node);
}

int main()
{
    int N;
    cin >> N;
    map<char, set<char>> graph;

    string first;
    cin >> first;
    for (int i = 0; i < N - 1; i++)
    {
        string second;
        cin >> second;

        int minLen = min(first.length(), second.length());
        for (int j = 0; j < minLen; j++)
        {
            if (first[j] != second[j])
            {
                graph[first[j]].insert(second[j]);
                break;
            }
        }

        first = second;
    }

    list<char> sortedNodes;
    map<char, bool> visited;

    for (auto element : graph)
    {
        if (!visited[element.first])
        {
            dfs(graph, visited, sortedNodes, element.first);
        }
    }

    for (auto sortedNode : sortedNodes)
    {
        cout << sortedNode << " ";
    }
}
