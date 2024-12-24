#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Comparator for sorting edges by descending weight
bool compareEdge(const Edge &a, const Edge &b) {
    return a.weight > b.weight;
}

// Disjoint Set Union (Union-Find with path compression and union by rank)
class DSU {
public:
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<Edge> edges;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back(Edge(u, v, w));
        }

        // Sort edges in descending order by weight
        sort(edges.begin(), edges.end(), compareEdge);

        DSU dsu(n);
        vector<int> heavyEdges;

        // Traverse edges in descending order
        for (const Edge &e : edges) {
            if (!dsu.unite(e.u, e.v)) {
                // If unite fails, this edge creates a cycle (is the heaviest in its cycle)
                heavyEdges.push_back(e.weight);
            }
        }

        // Output result
        if (heavyEdges.empty()) {
            cout << "forest" << endl;
        } else {
            sort(heavyEdges.begin(), heavyEdges.end());
            for (size_t i = 0; i < heavyEdges.size(); i++) {
                if (i > 0) cout << " ";
                cout << heavyEdges[i];
            }
            cout << endl;
        }
    }
    return 0;
}
