#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
    os << pai.first << ' ' << pai.second;
    return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
    is >> pai.first >> pai.second;
    return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 1505
#define MOD 1'000'000'007

int r, c;
char arr[MAX_N][MAX_N];

pii parent[MAX_N][MAX_N];
pii find(pii u) {
    if (parent[u.first][u.second] == u) 
        return u;
    return parent[u.first][u.second] = find(parent[u.first][u.second]);
}

void merge(pii u, pii v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    parent[u.first][u.second] = v;
}

queue<pii> q;
bool visited[MAX_N][MAX_N] = {0, };
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void bfs(int startY, int startX) {
    q.emplace(startY, startX);
    visited[startY][startX] = true;

    while(q.size()) {
        pii here = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = here.first + dy[i];
            int nextX = here.second + dx[i];

            if (nextY >= r || nextY < 0 || nextX >= c || nextX < 0)
                continue;
            if (visited[nextY][nextX])
                continue;
            if (arr[nextY][nextX] == 'X')
                continue;
            q.emplace(nextY, nextX);
            visited[nextY][nextX] = true;
            merge(pii(startY, startX), pii(nextY, nextX));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> r >> c;

    pii lpos1 = {-1, -1}, lpos2 = {-1, -1};
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'L') {
                if (lpos1.first == -1)
                    lpos1 = {i, j};
                else
                    lpos2 = {i, j};
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            parent[i][j] = {i, j};
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (arr[i][j] != 'X' && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (arr[i][j] != 'X') {
                for (int k = 0; k < 4; ++k) {
                    int nextY = i + dy[k];
                    int nextX = j + dx[k];
                    if (nextY >= r || nextY < 0 || nextX >= c || nextX < 0)
                        continue;
                    if (arr[nextY][nextX] == 'X' && !visited[nextY][nextX]) { 
                        q.emplace(nextY, nextX);
                        visited[nextY][nextX] = true;
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= MAX_N * MAX_N; ++i)  {
        int sz = q.size();
        while(sz--) {
            pii here = q.front();
            q.pop();
            arr[here.first][here.second] = '.';
            for (int k = 0; k < 4; ++k) {
                int nextY = here.first + dy[k];
                int nextX = here.second + dx[k];
                if (nextY >= r || nextY < 0 || nextX >= c || nextX < 0)
                    continue;
                if (arr[nextY][nextX] == 'X' && !visited[nextY][nextX]) { 
                    q.emplace(nextY, nextX);
                    visited[nextY][nextX] = true;
                }
                else if (arr[nextY][nextX] != 'X') {
                    merge(here, pii(nextY, nextX));
                }
            }
        }
        if (find(lpos1) == find(lpos2)) {
            cout << i << endl;
            break;
        }
    }
    

    return 0;
}
