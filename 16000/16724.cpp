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

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
int visited[MAX_N][MAX_N];

int dfs(int hereY, int hereX, int cnt) {
    int nextY = hereY + dy[arr[hereY][hereX]];
    int nextX = hereX + dx[arr[hereY][hereX]];

    if (visited[nextY][nextX] == cnt) 
        return 1;
    if (visited[nextY][nextX] && visited[nextY][nextX] < cnt)
        return 0;
    
    visited[nextY][nextX] = cnt;
    return dfs(nextY, nextX, cnt);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            switch(arr[i][j]) {
                case 'L' :
                    arr[i][j] = 0;
                    break;
                case 'U' :
                    arr[i][j] = 1;
                    break;
                case 'R' :
                    arr[i][j] = 2;
                    break;
                case 'D' :
                    arr[i][j] = 3;
                    break;
                default :
                    assert(1);
            }
        }
    }
    
    int cnt = 1;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                visited[i][j] = cnt;
                result += dfs(i, j, cnt);
                ++cnt;
            }
        }
    }

    cout << result << endl;


	return 0;
}