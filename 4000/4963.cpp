#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<vector<int> > adj;
vector<vector<bool> > visited;
int n, m;

void dfs(int y, int x) {
    if (visited[y][x]) {
        return;
    }

    visited[y][x] = true;

    int dy[] = {0, -1, 1, 0, -1, -1, 1, 1};
    int dx[] = {-1, 0, 0, 1, -1, 1, -1, 1};

    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
            continue;
        }
        if (visited[ny][nx] || adj[ny][nx] == 0) {
            continue;
        }

        dfs(ny, nx);
    }
}

int main() {
    while (true) {
        scanf("%d %d", &m, &n);
        if (n == 0 && m == 0) {
            break;
        }

        adj.clear();
        adj.resize(n);
        visited.clear();
        visited.resize(n);

        for (int i = 0; i < n; i++) {
            adj[i].resize(m);
            visited[i].resize(m, false);

            for (int j = 0; j < m; j++) {
                scanf("%d", &adj[i][j]);
            }
        }

        int number = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] || adj[i][j] == 0) {
                    continue;
                }
                dfs(i, j);
                number++;
            }

        }
        printf("%d\n", number);
    }

    return 0;
}