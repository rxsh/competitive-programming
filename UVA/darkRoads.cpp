#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Byteland {
    // carretera bidireccional entre X y Y con longitud z;
    int caminoX; // x 
    int caminoY; // y
    int longitud; // z

    bool operator<(const Byteland& b) const {
        return longitud < b.longitud;
    }
};

int encontrar(vector<int>& roads, int calle) {

    if (!(roads[calle] == calle)) {
        roads[calle] = encontrar(roads, roads[calle]);
    }

    return roads[calle];

}

void conectar(vector<int>& road, vector<int>& rango, int calleX, int calleY) {

    int padreX = encontrar(road, calleX);
    int padreY = encontrar(road, calleY);

    if (padreX != padreY) {
        if (rango[padreX] > rango[padreY]) {
            road[padreY] = padreX;
        }
        if (rango[padreX] < rango[padreY]) {
            road[padreX] = padreY;
        }
        else {
            road[padreY] = padreX;
            rango[padreX]++;
        }
    }

}

int main()
{
	// m = junctions, n = number of roads
	int m, n;
    while (cin >> m >> n && m == n == 0) {
        vector<Byteland> roads(n);
        int costoTotal = 0;
        for (int i = 0; i < n; i++) {
            cin >> roads[i].caminoX >> roads[i].caminoY >> roads[i].longitud;
            costoTotal += roads[i].longitud;
        }

        sort(roads.begin(), roads.end());

        vector<int> road(m), rango(m, 0);
        for (int i = 0; i < m; i++) {
            road[i] = i;
        }

        int ahorroMax = 0;
        for (const auto& cam : roads) {
            if (encontrar(road, cam.caminoX) != encontrar(road, cam.caminoY)) {
                conectar(road,rango,cam.caminoX, cam.caminoY);
                ahorroMax += cam.longitud;
            }
        }

        cout << costoTotal - ahorroMax << endl;

	}

    return 0;
}

