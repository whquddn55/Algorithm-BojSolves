#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;
vector<vector<int> > maze;
vector<vector<int> > dp;
int m, n;

int get(int y, int x){
    if(dp[y][x] != -1){
        return dp[y][x];
    }

    int dy[] = { 0, -1, 1, 0};
    int dx[] = { -1, 0, 0, 1};

    dp[y][x] = 0;
    for(int i = 0; i < 4; i++){
        if( x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= m){
            continue;
        }
        if( maze[y][x] >= maze[y + dy[i]][x + dx[i]]){
            continue;
        }
        dp[y][x] += get(y + dy[i], x + dx[i]);
    }

    return dp[y][x];
}

int main() {
    scanf("%d %d", &m, &n);
    maze.resize(m);
    dp.resize(m);

    for(int i = 0; i < m; i++){
        maze[i].resize(n);
        dp[i].resize(n, -1);

        for(int j = 0; j < n; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    dp[0][0] = 1;

    printf("%d\n", get(m - 1, n - 1));

    return 0;
}
