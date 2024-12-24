#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MAX_DIM = 25;
int n;  // Dimension of the square matrix
vector<string> image;
bool visited[MAX_DIM][MAX_DIM];

// Directions for 8 possible neighbors (up, down, left, right, and diagonals)
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Depth-First Search to mark all connected cells
void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Check boundaries and if the neighbor is a '1' and not visited
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && image[nx][ny] == '1') {
            dfs(nx, ny);
        }
    }
}

int main() {
    int imageNumber = 0;

    while (cin >> n) {
        image.clear();
        image.resize(n);
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; ++i) {
            cin >> image[i];
        }

        int warEagleCount = 0;

        // Traverse each cell in the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find an unvisited '1', it's a new war eagle
                if (image[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j);
                    warEagleCount++;
                }
            }
        }

        // Output the result for the current image
        cout << "Image number " << ++imageNumber << " contains " << warEagleCount << " war eagles." << endl;
    }

    return 0;
}
