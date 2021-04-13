#include <bits/stdc++.h>
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
 
#define INF (INT_MAX / 2)
 
#define MAX_N 1005

int n, m;
char arr[MAX_N][MAX_N];
int result[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int dfs(int hereY, int hereX, int start) {
    result[hereY][hereX] = 1;
    visited[hereY][hereX] = start;

    for (int i = 0; i < 4; ++i) {
        int nextY = hereY + dy[i];
        int nextX = hereX + dx[i];

        if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
            continue;
        if (visited[nextY][nextX] || arr[nextY][nextX] == '1')
            continue;
        result[hereY][hereX] += dfs(nextY, nextX, start);
    }
    return result[hereY][hereX];
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (visited[i][j] || arr[i][j] == '1')
                continue;
            result[i][j] = dfs(i, j, i * m + j + 1);
        }

    for (int i = 0; i < n; ++i, cout << endl)
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == '1') {
                vector<pii> coords;
                for (int k = 0; k < 4; ++k) {
                    int nextY = i + dy[k];
                    int nextX = j + dx[k];
                    if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
                        continue;
                    if (arr[nextY][nextX] == '1')
                        continue;
                    int y = (visited[nextY][nextX] - 1) / m;
                    int x = (visited[nextY][nextX] - 1) % m;
                    coords.emplace_back(y, x);
                }
                sort(coords.begin(), coords.end());
                coords.erase(unique(coords.begin(), coords.end()), coords.end());
                int ret = 1;
                for (auto& c : coords) 
                    ret += result[c.first][c.second];
                cout << ret % 10;
            }
            else
                cout << 0;
        }
	return 0;
}