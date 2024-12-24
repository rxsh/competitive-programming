#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

struct Edge {
    int u, v;
    double ppa;
    Edge(int u, int v, double ppa) : u(u), v(v), ppa(ppa) {}
};

int n, m;
vector<Edge> edges;
vector<vector<pair<int, double>>> graph;
bool visited[501];

bool canAchieveAverage(double avg) {
    // Adjust the graph with the new weights: ppa - avg
    for (int i = 1; i <= n; i++) graph[i].clear();
    for (const auto& edge : edges) {
        double adjustedWeight = edge.ppa - avg;
        graph[edge.u].emplace_back(edge.v, adjustedWeight);
        graph[edge.v].emplace_back(edge.u, adjustedWeight);
    }

    memset(visited, 0, sizeof(visited));
    int maxCities = 0;

    for (int start = 1; start <= n; ++start) {
        if (!visited[start]) {
            int cityCount = 0;
            double totalWeight = 0.0;
            queue<int> q;
            q.push(start);
            visited[start] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                cityCount++;
                for (const auto& [v, weight] : graph[u]) {
                    totalWeight += weight;
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            if (totalWeight > 0) {
                maxCities = max(maxCities, cityCount);
            }
        }
    }

    return maxCities;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int caseNum = 1;
    while (cin >> n >> m, n || m) {
        edges.clear();
        graph.assign(n + 1, vector<pair<int, double>>());

        for (int i = 0; i < m; ++i) {
            int u, v, ppa;
            cin >> u >> v >> ppa;
            edges.emplace_back(u, v, ppa);
        }

        // Binary search on the average PPA
        double left = -100000.0, right = 100000.0;
        double maxAvg = left;
        int resultCities = 0;

        for (int i = 0; i < 50; ++i) {  // Precision loop for binary search
            double mid = (left + right) / 2.0;
            int cities = canAchieveAverage(mid);
            if (cities > 0) {
                maxAvg = mid;
                resultCities = cities;
                left = mid;
            } else {
                right = mid;
            }
        }

        cout << resultCities << endl;
        caseNum++;
    }

    return 0;
}
