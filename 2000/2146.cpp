#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<vector<int> > adj;
vector<vector<bool> > visited;
vector<vector<int> > costs;
int n;

void bfs1(int y, int x, int cnt) {
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
        adj[y][x] = cnt;
        costs[y][x] = 0;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
                continue;
            }
            if (adj[ny][nx] == 0) {
                adj[y][x] = -cnt;
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }

            q.push(make_pair(ny, nx));
        }
    }
}

int bfs2() {
    int result = INF;
    queue<pair<pair<int, int>, pair<int, int> > >q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] < 0) {
                q.push(make_pair(make_pair(i, j), make_pair(-adj[i][j], 0)));
                visited[i][j] = false;
            }
        }
    }

    int dy[] = {0, -1, 1, 0};
    int dx[] = {-1, 0, 0, 1};

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int land = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if (visited[y][x]) {
            continue;
        }

        visited[y][x] = true;
        adj[y][x] = land;
        costs[y][x] = cost;


        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
                continue;
            }
            if (adj[ny][nx] != 0) {
                if (adj[ny][nx] != land && cost != 0) {
                    result = result > cost + costs[ny][nx] ? cost + costs[ny][nx] : result;
                }
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }

            q.push(make_pair(make_pair(ny, nx), make_pair(land, cost + 1)));
        }
    }

    return result;
}

int main() {
    scanf("%d",&n);

    adj.resize(n);
    visited.resize(n);
    costs.resize(n);
    for (int i = 0; i < n; i++) {
        adj[i].resize(n);
        visited[i].resize(n, false);
        costs[i].resize(n, -1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 0 || visited[i][j]) {
                continue;
            }
            bfs1(i, j, cnt);
            cnt++;
        }
    }
    printf("%d\n", bfs2());

    return 0;
}


