#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Comparator for sorting edges in descending order by weight
bool compareEdge(const Edge &a, const Edge &b) {
    return a.weight > b.weight;
}

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        if (size[rootX] > size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
        return true;
    }

    int componentSize(int x) {
        return size[find(x)];
    }
};

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;

        vector<Edge> edges;
        for (int i = 0; i < m; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            u--; v--;  // convert to zero-indexed
            edges.emplace_back(u, v, weight);
        }

        // Sort edges by weight in descending order
        sort(edges.begin(), edges.end(), compareEdge);

        DSU dsu(n);
        long long sumOfCandidateSizes = 0;

        for (const Edge &edge : edges) {
            int u = edge.u, v = edge.v;

            int rootU = dsu.find(u);
            int rootV = dsu.find(v);

            if (rootU != rootV) {
                // Before union, add the sizes of both components as new candidates
                sumOfCandidateSizes += dsu.componentSize(rootU);
                sumOfCandidateSizes += dsu.componentSize(rootV);

                // Union the components
                dsu.unite(u, v);
            }
        }

        // Add the size of the whole graph as a final candidate (the whole graph is always a candidate)
        sumOfCandidateSizes += n;

        cout << sumOfCandidateSizes << endl;
    }

    return 0;
}
