#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> ids, low;
vector<bool> onStack;
stack<int> stk;
int id, sccCount;
vector<int> sccComponent;  // Track which SCC each node belongs to
vector<int> sccEdgeCount;  // Track edge count per SCC

void tarjanDFS(int u) {
    ids[u] = low[u] = id++;
    stk.push(u);
    onStack[u] = true;

    for (int v : graph[u]) {
        if (ids[v] == -1) {
            tarjanDFS(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], ids[v]);
        }
    }

    if (ids[u] == low[u]) {
        while (true) {
            int v = stk.top();
            stk.pop();
            onStack[v] = false;
            sccComponent[v] = sccCount;
            if (u == v) break;
        }
        sccCount++;
    }
}

bool isCactus(int n) {
    ids.assign(n, -1);
    low.assign(n, 0);
    onStack.assign(n, false);
    sccComponent.assign(n, -1);
    sccEdgeCount.assign(n, 0);
    id = 0;
    sccCount = 0;

    // Run Tarjan's algorithm to find all SCCs
    for (int i = 0; i < n; ++i) {
        if (ids[i] == -1) {
            tarjanDFS(i);
        }
    }

    // If there are multiple SCCs, the graph is not strongly connected
    if (sccCount > 1) return false;

    // Count edges in each SCC
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            if (sccComponent[u] == sccComponent[v]) {
                sccEdgeCount[sccComponent[u]]++;
            }
        }
    }

    // Verify each SCC forms a single simple cycle (edges = nodes in each SCC)
    for (int i = 0; i < sccCount; ++i) {
        if (sccEdgeCount[i] / 2 != count(sccComponent.begin(), sccComponent.end(), i)) {
            return false;
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        graph.assign(n, vector<int>());
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        cout << (isCactus(n) ? "YES" : "NO") << endl;
    }

    return 0;
}
