#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

bool dfs(char node, unordered_map<char, vector<char>>& graph, unordered_set<char>& visited, 
         unordered_set<char>& recStack, vector<char>& path, vector<string>& cycles) {
    visited.insert(node);
    recStack.insert(node);
    path.push_back(node);

    for (char neighbor : graph[node]) {
        if (recStack.count(neighbor)) {
            // Cycle detected, build the cycle path
            auto cycleStart = find(path.begin(), path.end(), neighbor);
            vector<char> cycle(cycleStart, path.end());
            cycle.push_back(neighbor);  // Closing the cycle
            string cycleString;
            for (size_t i = 0; i < cycle.size(); ++i) {
                cycleString += (i > 0 ? "-" : "") + string(1, cycle[i]);
            }
            cycles.push_back(cycleString);
            return true;  // Cycle found
        } else if (!visited.count(neighbor)) {
            if (dfs(neighbor, graph, visited, recStack, path, cycles)) {
                return true;  // Continue searching for cycles
            }
        }
    }

    recStack.erase(node);
    path.pop_back();
    return false;  // No cycle found
}

int main() {
    int T;
    cin >> T;
    cin.ignore();  // Ignore newline after T

    for (int t = 0; t < T; ++t) {
        if (t > 0) cin.ignore();  // Ignore blank line between test cases

        int N, M, E;
        cin >> N >> M >> E;
        cin.ignore();  // Ignore newline after E

        unordered_map<char, vector<char>> graph;
        for (int i = 0; i < E; ++i) {
            string edge;
            cin >> edge;
            char from = edge[0];
            char to = edge[2];
            graph[from].push_back(to);
        }

        unordered_set<char> visited;
        unordered_set<char> recStack;
        vector<string> deadlockCycles;

        for (auto& entry : graph) {
            char node = entry.first;
            if (!visited.count(node)) {
                vector<char> path;
                dfs(node, graph, visited, recStack, path, deadlockCycles);
            }
        }

        if (!deadlockCycles.empty()) {
            cout << "YES" << endl;
            // Sort cycles by their lengths
            sort(deadlockCycles.begin(), deadlockCycles.end(),
                [](const string& a, const string& b) { return a.length() < b.length(); });

            for (const auto& cycle : deadlockCycles) {
                cout << cycle << endl;
            }
        } else {
            cout << "NO" << endl;
        }

        if (t < T - 1) cout << endl;  // Separate test cases with a blank line
    }

    return 0;
}
