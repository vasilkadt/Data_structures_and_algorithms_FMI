#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to;
};

void kruskal(vector<int> &components, vector<Edge> &edges) {
    for (Edge edge: edges) {
        if (components[edge.from] != components[edge.to]) {
            int fromNew = components[edge.from];
            int toNew = components[edge.to];
            for (int i = 0; i < components.size(); i++) {
                if (components[i] == fromNew)
                    components[i] = toNew;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M;
    vector<Edge> edges;
    vector<int> components(N + 1);

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        edges.push_back({from, to});
    }

    for (int i = 0; i < N + 1; i++) {
        components[i] = i;
    }

    kruskal(components, edges);

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type, from, to;
        cin >> type >> from >> to;
        if (type == 1) {
            if (components[from] == components[to]) {
                cout << 1;
            } else {
                cout << 0;
            }
        } else if (type == 2){
            edges.push_back({from, to});
            if (components[from] != components[to]) {
                int fromNew = components[from];
                int toNew = components[to];
                for (int i = 0; i < components.size(); i++) {
                    if (components[i] == fromNew)
                        components[i] = toNew;
                }
            }
        }
    }
}
