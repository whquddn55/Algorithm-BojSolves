#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<vector<char> > adj;
vector<vector<bool> > visited;
int n;

void dfs(int y, int x, int& temp) {
    if (visited[y][x]) {
        return;
    }

    visited[y][x] = true;
    temp++;

    int dy[] = {0, -1, 1, 0};
    int dx[] = {-1, 0, 0, 1};

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
            continue;
        }
        if (visited[ny][nx] || adj[ny][nx] == '0') {
            continue;
        }

        dfs(ny, nx, temp);
    }
}

int main() {

    scanf("%d", &n);
    getchar();

    adj.clear();
    adj.resize(n);
    visited.clear();
    visited.resize(n);

    for (int i = 0; i < n; i++) {
        adj[i].resize(n);
        visited[i].resize(n, false);

        for (int j = 0; j < n; j++) {
            scanf("%c", &adj[i][j]);
        }
        getchar();
    }

    int number = 0;
    vector<int> numOfHouse;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] || adj[i][j] == '0') {
                continue;
            }

            int temp = 0;
            dfs(i, j, temp);
            numOfHouse.push_back(temp);
            number++;
        }

    }

    printf("%d\n", number);
    sort(numOfHouse.begin(), numOfHouse.end());

    for (int num : numOfHouse) {
        printf("%d\n", num);
    }

    return 0;
}