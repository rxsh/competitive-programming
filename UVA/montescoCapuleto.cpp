#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(const vector<vector<int>>& graph, vector<int>& color, int start) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    int color_count[2] = {1, 0};  

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                color_count[color[v]]++;
                q.push(v);
            } else if (color[v] == color[u]) {
                return 0;
            }
        }
    }


    return max(color_count[0], color_count[1]);
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    for (int t = 0; t < T; ++t) {
        if (t > 0) cin.ignore();  

        int N;
        cin >> N;
        vector<vector<int>> graph(N);

        for (int i = 0; i < N; ++i) {
            int p;
            cin >> p;
            for (int j = 0; j < p; ++j) {
                int enemy;
                cin >> enemy;
                enemy--; 
                graph[i].push_back(enemy);
                graph[enemy].push_back(i);  
            }
        }

        vector<int> color(N, -1); 
        int max_invites = 0;

        for (int i = 0; i < N; ++i) {
            if (color[i] == -1) {
                int result = bfs(graph, color, i);
                if (result == 0) {
                    max_invites = 0;
                    break;
                }
                max_invites += result;
            }
        }

        cout << max_invites << endl;
        if (t < T - 1) cout << endl;  
    }

    return 0;
}
