
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <climits>
using namespace std;
const int maxSize = 1e6;
vector<int> parent(maxSize);
vector<int> depth(maxSize);

struct Edge {
    int from;
    int to;
    int speed;
    bool operator<(const Edge& from) {
        return this->speed < from.speed;
    }
};

void make_set(int i) {
    parent[i] = i;
    depth[i] = 0;
}
int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int from, int to) {
    from = find_set(from);
    to = find_set(to);
    if (from != to) {
        if (depth[from] < depth[to]) {
            swap(from, to);
        }
        parent[to] = from;
        if (depth[from] == depth[to]) {
            depth[from]++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int from, to, speed;
        cin >> from >> to >> speed;
        edges.push_back({ from,to,speed });
    }
    int minValue = 0;
    int maxValue = 0;
    int minDiff = INT_MAX;
    int outputMin = 0;
    int outputMax = 0;
    list<Edge> tree;
    int counter=0;
    sort(edges.begin(), edges.end());
    while (m-counter >= n - 1)
    {
        int counterEdges = 0;
        for (int i = 0; i <= n; i++)
        {
            make_set(i);
        }
        for (int i=counter;i<m;i++) {
            if (find_set(edges[i].from) != find_set(edges[i].to)) {
                tree.push_back(edges[i]);
                if (maxValue < edges[i].speed) maxValue = edges[i].speed;
                counterEdges++;
                if (counterEdges == n - 1)break;
                union_set(edges[i].from, edges[i].to);
            }
        }
        auto itr = tree.begin();
        auto itr2 = tree.end();
        itr2--;
        minValue = itr->speed;
        maxValue = itr2->speed;
        if (counterEdges != n - 1) break;
        if (minDiff > (maxValue - minValue))
        {
            minDiff = maxValue - minValue;
            outputMin = minValue;
            outputMax = maxValue;
        }
        else if (minDiff == (maxValue - minValue)) {
            if (minValue < outputMin)
            {
                outputMin = minValue;
                outputMax = maxValue;
            }
        }
        tree.clear();
        counter++;
    }
    cout << outputMin << " " << outputMax;
}
