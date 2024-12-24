#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility> // for std::pair
#include <algorithm> // for std::sort

using namespace std;

struct Position {
    int x, y;
};

class KnightTour {
public:
    KnightTour(int r, int c, int m, int n, const set<Position>& water)
        : R(r), C(c), M(m), N(n), waterSquares(water) {}

    void calculateMarkedSquares() {
        vector<vector<int>> reachableCount(R, vector<int>(C, 0));
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        // Directions based on knight's moves
        vector<Position> directions = {
            {M, N}, {N, M}, {-M, N}, {-N, M},
            {M, -N}, {N, -M}, {-M, -N}, {-N, -M}
        };

        // BFS or DFS from (0, 0)
        queue<Position> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            Position current = q.front();
            q.pop();

            // Count reachable squares from current position
            for (const auto& dir : directions) {
                Position next = {current.x + dir.x, current.y + dir.y};

                if (isValid(next) && !visited[next.x][next.y]) {
                    reachableCount[next.x][next.y]++;
                    visited[next.x][next.y] = true;
                    q.push(next);
                }
            }
        }

        countEvenOddSquares(reachableCount);
    }

private:
    int R, C; // Rows and Columns
    int M, N; // Knight's move parameters
    set<Position> waterSquares; // Water positions

    bool isValid(const Position& pos) {
        return pos.x >= 0 && pos.x < R && pos.y >= 0 && pos.y < C && 
               waterSquares.find(pos) == waterSquares.end();
    }

    void countEvenOddSquares(const vector<vector<int>>& reachableCount) {
        int evenCount = 0;
        int oddCount = 0;

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (reachableCount[i][j] > 0) {
                    if (reachableCount[i][j] % 2 == 0) {
                        evenCount++;
                    } else {
                        oddCount++;
                    }
                }
            }
        }

        cout << "Even: " << evenCount << ", Odd: " << oddCount << endl;
    }
};

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int R, C, M, N;
        cin >> R >> C >> M >> N;

        int W;
        cin >> W;

        set<Position> waterSquares;
        for (int i = 0; i < W; ++i) {
            int x, y;
            cin >> x >> y;
            waterSquares.insert({x, y});
        }

        KnightTour knight(R, C, M, N, waterSquares);
        
        cout << "Case " << t << ": ";
        knight.calculateMarkedSquares();
    }

    return 0;
}