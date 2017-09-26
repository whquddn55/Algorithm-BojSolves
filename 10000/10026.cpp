#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<vector<char> > adj;
vector<vector<bool> > visited;
int n;

void bfs(int y, int x, char color, bool isblind) {
    queue<pair<int, int> >q;
    q.push(make_pair(y, x));

    int dy[] = {0, -1, 1, 0};
    int dx[] = {-1, 0, 0, 1};

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (visited[y][x]) {
            continue;
        }

        visited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            if (adj[ny][nx] != color) {
                if (!(isblind && (color != 'B') && adj[ny][nx] != 'B')) {
                    continue;
                }
            }

            q.push(make_pair(ny, nx));
        }
    }
}

int main() {
    scanf("%d", &n);
    getchar();

    adj.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; i++) {
        adj[i].resize(n);
        visited[i].resize(n, false);

        for (int j = 0; j < n; j++) {
            scanf("%c", &adj[i][j]);
        }
        getchar();
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                continue;
            }
            bfs(i, j, adj[i][j], false);
            cnt1++;
        }
    }
    for (int i = 0; i < n; i++) {
        visited[i].clear();
        visited[i].resize(n, false);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                continue;
            }
            bfs(i, j, adj[i][j], true);
            cnt2++;
        }
    }

    printf("%d %d\n", cnt1, cnt2);

    return 0;
}
