#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> root;

int findRoot(int node) {
    return (root[node] == node ? node : root[node] = findRoot(root[node]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; ++test) {
        int cityCount;
        double maxRoadDist;
        cin >> cityCount >> maxRoadDist;

        root.assign(cityCount, 0);
        vector<pair<int, int>> cities(cityCount);

        for (int i = 0; i < cityCount; ++i) {
            root[i] = i;
            cin >> cities[i].first >> cities[i].second;
        }

        vector<pair<int, pair<int, double>>> edges;

        for (int i = 0; i < cityCount; ++i) {
            for (int j = i + 1; j < cityCount; ++j) {
                int deltaX = cities[i].first - cities[j].first;
                int deltaY = cities[i].second - cities[j].second;
                int distSquared = deltaX * deltaX + deltaY * deltaY;
                edges.emplace_back(distSquared, make_pair(i, j));
            }
        }

        sort(edges.begin(), edges.end());

        int numStates = 1;
        double totalRoad = 0.0;
        double totalRail = 0.0;
        int connectedComponents = 0;

        for (const auto& edge : edges) {
            int cityA = findRoot(edge.second.first);
            int cityB = findRoot(edge.second.second);

            if (cityA != cityB) {
                root[cityA] = cityB;

                if (edge.first <= maxRoadDist * maxRoadDist) {
                    totalRoad += sqrt(edge.first);
                } else {
                    ++numStates;
                    totalRail += sqrt(edge.first);
                }

                if (++connectedComponents == cityCount - 1) break;
            }
        }

        cout << "Case #" << test << ": " << numStates << " " 
             << static_cast<int>(round(totalRoad)) << " " 
             << static_cast<int>(round(totalRail)) << "\n";
    }

    return 0;
}
