#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

class Graph {
public:
    Graph(char largestNode) {
        // Initialize the graph with nodes from 'A' to largestNode
        for (char c = 'A'; c <= largestNode; ++c) {
            adj[c] = vector<char>();
        }
    }

    void addEdge(char u, char v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // because the graph is undirected
    }

    int countMaximalConnectedSubgraphs() {
        set<char> visited;
        int count = 0;

        for (const auto& pair : adj) {
            char node = pair.first;
            if (visited.find(node) == visited.end()) {
                // Start a new DFS/BFS from this node
                dfs(node, visited);
                count++;
            }
        }
        return count;
    }

private:
    map<char, vector<char>> adj; // adjacency list

    void dfs(char node, set<char>& visited) {
        visited.insert(node);
        for (char neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, visited);
            }
        }
    }
};

int main() {
    int cases;
    cin >> cases;
    cin.ignore(); // Ignore the newline after the number of cases

    bool firstCase = true;

    while (cases--) {
        if (!firstCase) {
            cout << endl; // Print a blank line between outputs
        }
        firstCase = false;

        string line;
        getline(cin, line); // Read the blank line before each case

        char largestNode;
        getline(cin, line);
        largestNode = line[0]; // The first character is the largest node

        Graph g(largestNode);

        while (getline(cin, line)) {
            if (line.empty()) break; // Stop reading edges on blank line
            char u = line[0];
            char v = line[1];
            g.addEdge(u, v);
        }

        int result = g.countMaximalConnectedSubgraphs();
        cout << result << endl;
    }

    return 0;
}