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
#define MAX_N 51
#define MOD 1'000'000'007

int n, m;
int arr[MAX_N][MAX_N];
vector<pii> virus;
int dist[10][MAX_N][MAX_N];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void bfs(int startIdx) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[startIdx][i][j] = INF;

    queue<pii> q;
    q.emplace(virus[startIdx]);
    dist[startIdx][virus[startIdx].first][virus[startIdx].second] = 0;

    while(q.size()) {
        int hereY = q.front().first;
        int hereX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = hereY + dy[i];
            int nx = hereX + dx[i];

            if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
            if (arr[ny][nx] == 1) continue;
            if (dist[startIdx][ny][nx] != INF) continue;
            q.emplace(ny, nx);
            dist[startIdx][ny][nx] = dist[startIdx][hereY][hereX] + 1;
        }
    }
}

vector<int> picked;
bool isIn[10];
int ans = INF;

void pick() {
    if (picked.size() == m) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] != 0) continue;
                int value = INF;
                for (int k = 0; k < m; ++k) {
                    value = min(value, dist[picked[k]][i][j]);
                }
                res = max(res, value);
            }
        }
        ans = min(ans, res);
        return;
    }

    for (int i = picked.size() == 0 ? 0 : picked.back() + 1; i < virus.size(); ++i) {
        if (isIn[i]) continue;
        isIn[i] = true;
        picked.emplace_back(i);
        pick();
        isIn[i] = false;
        picked.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                virus.emplace_back(i, j);
            }
        }

    for (int i = 0; i < virus.size(); ++i)
        bfs(i);

    pick();

    cout << (ans == INF ? -1 : ans) << endl;
    
    return 0;
}
