#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<vector<int> > maze;
vector<vector<int> > dp;
int n, m;

int get(int y, int x){
    int& ret = dp[y][x];
    if (ret != -1){
        return ret;
    }

    ret = 0;
    int dy[] = {0, -1, -1};
    int dx[] = {-1, 0, -1};

    int maximum = -INF;
    for (int i = 0; i < 3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
            continue;
        }

        maximum = max(maximum, get(ny, nx));
    }

    return ret = maximum + maze[y][x];
}

int main() {
    scanf("%d %d", &n, &m);

    maze.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        maze[i].resize(m);
        dp[i].resize(m, -1);
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    dp[0][0] = maze[0][0];

    get(n - 1, m - 1);

    printf("%d\n", dp[n - 1][m - 1]);

    return 0;
}


