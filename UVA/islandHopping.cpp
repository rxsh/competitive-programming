#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_ISLANDS = 64;
double posX[MAX_ISLANDS], posY[MAX_ISLANDS], population[MAX_ISLANDS];

struct Connection {
    int start, end;
    double distance;
    Connection(int u = 0, int v = 0, double d = 0) : start(u), end(v), distance(d) {}
    bool operator<(const Connection &other) const {
        return distance < other.distance;
    }
};

vector<Connection> connections;
int root[MAX_ISLANDS], componentSize[MAX_ISLANDS];
double componentWeight[MAX_ISLANDS];

int findRoot(int island) {
    return root[island] == island ? island : root[island] = findRoot(root[island]);
}

bool uniteIslands(int islandA, int islandB) {
    islandA = findRoot(islandA);
    islandB = findRoot(islandB);
    if (islandA == islandB) return false;

    if (componentSize[islandA] > componentSize[islandB]) {
        root[islandB] = islandA;
        componentSize[islandA] += componentSize[islandB];
        componentWeight[islandA] += componentWeight[islandB];
    } else {
        root[islandA] = islandB;
        componentSize[islandB] += componentSize[islandA];
        componentWeight[islandB] += componentWeight[islandA];
    }
    return true;
}

double calculateAverageDistance(int islandCount) {
    sort(connections.begin(), connections.end());

    double totalPopulation = 0, totalDistance = 0;
    for (int i = 0; i < islandCount; i++) {
        root[i] = i;
        componentSize[i] = 1;
        componentWeight[i] = population[i];
        totalPopulation += population[i];
    }

    for (const auto &conn : connections) {
        int u = conn.start, v = conn.end;
        if (findRoot(u) != findRoot(v)) {
            if (findRoot(u) == findRoot(0))
                totalDistance += componentWeight[findRoot(v)] * conn.distance;
            if (findRoot(v) == findRoot(0))
                totalDistance += componentWeight[findRoot(u)] * conn.distance;
            uniteIslands(u, v);
        }
    }

    return totalDistance / totalPopulation;
}

int main() {
    int islandCount, testCase = 0;

    while (scanf("%d", &islandCount) == 1 && islandCount) {
        for (int i = 0; i < islandCount; i++) {
            scanf("%lf %lf %lf", &posX[i], &posY[i], &population[i]);
        }

        connections.clear();
        for (int i = 0; i < islandCount; i++) {
            for (int j = i + 1; j < islandCount; j++) {
                double dist = hypot(posX[i] - posX[j], posY[i] - posY[j]);
                connections.push_back(Connection(i, j, dist));
            }
        }

        double result = calculateAverageDistance(islandCount);

        printf("Island Group: %d Average %.2lf\n", ++testCase, result);
        puts("");
    }

    return 0;
}
