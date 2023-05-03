#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int from;
    int to;
    int speed;

    bool operator<(const Edge &edge) const {
        return this->speed < edge.speed;
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
        int from, to, speed;
        cin >> from >> to >> speed;
        edges.push_back({from, to, speed});
    }

    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    int minDiff = INT_MAX;
    int newMin = INT_MAX;
    int newMax = INT_MIN;

    vector<Edge> sortedEdges;
    int counter = 0;
    sort(edges.begin(), edges.end());
    while (M - counter >= N - 1) {
        int edgesCount = 0;
        for (int i = 0; i <= N; i++) {
            parents[i] = i;
            rank[i] = 0;
        }

        for (int i = counter; i < M; i++) {
            if (find(parents, edges[i].from) != find(parents, edges[i].to)) {
                sortedEdges.push_back(edges[i]);
                if (maxValue < edges[i].speed) maxValue = edges[i].speed;
                edgesCount++;
                disjointset(rank, parents, edges[i].from, edges[i].to);
            }
        }

        minValue=sortedEdges[0].speed;
        maxValue=sortedEdges[sortedEdges.size()-1].speed;
        if (edgesCount != N - 1) break;

        if (minDiff > maxValue - minValue) {
            minDiff = maxValue - minValue;
            newMin = minValue;
            newMax = maxValue;
        } else{
            if (minValue < newMin) {
                newMin = minValue;
                newMax = maxValue;
            }
        }

        sortedEdges.clear();
        counter++;
    }
    cout << newMin << " " << newMax;
}