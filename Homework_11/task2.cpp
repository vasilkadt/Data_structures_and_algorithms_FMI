#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int index;
    long long from;
    long long to;
    long long effort;
    long long profit;

    bool operator<(const Edge &edge) const {
        if (this->effort == edge.effort) {
            return this->profit > edge.profit;
        }
        return this->effort < edge.effort;
    }
};

int find(vector<int> &parents, long long element) {
    if (parents[element] == element)
        return element;

    return parents[element] = find(parents, parents[element]);
}

void disjointset(vector<int> &rank, vector<int> &parents, long long first, long long second) {
    long long root1 = find(parents, first);
    long long root2 = find(parents, second);

    if (rank[root1] > rank[root2]) {
        parents[root2] = root1;
    } else if (rank[root1] == rank[root2]) {
        parents[root1] = root2;
        rank[root1]++;
    } else {
        parents[root1] = root2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    vector<int> parents(N + 1);
    vector<int> rank(N + 1);

    for (int i = 0; i < M; ++i) {
        long long from, to, effort, profit;
        cin >> from >> to >> effort >> profit;
        edges.push_back({i, from, to, effort, profit});
    }

    for (int i = 0; i <= N; ++i) {
        parents[i] = i;
        rank[i] = 0;
    }

    sort(edges.begin(), edges.end());
    for (auto edge: edges) {
        if (find(parents, edge.from) != find(parents, edge.to)) {
            cout << edge.index + 1 << endl;
            disjointset(rank, parents, edge.from, edge.to);
        }
    }
}