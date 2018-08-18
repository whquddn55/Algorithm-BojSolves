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

#define INF (LLONG_MAX / 2)

#define MAX_N 50

int n, m;
char arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int ans = 0;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };
int dfs(int hereY, int hereX) {
	if (hereY >= n || hereY < 0 || hereX >= m || hereX < 0)
		return 0;
	if (arr[hereY][hereX] == -1)
		return 0;
	if (visited[hereY][hereX])
		return -1;

	int& ret = dp[hereY][hereX];
	if (ret != -1)
		return ret;
	ret = 0;

	visited[hereY][hereX] = true;

	for (int i = 0; i < 4; i++) {
		int nextY = hereY + dy[i] * arr[hereY][hereX];
		int nextX = hereX + dx[i] * arr[hereY][hereX];

		int value = dfs(nextY, nextX);
		if (value == -1)
			return -1;
		ret = max(ret, value + 1);
	}
	visited[hereY][hereX] = false;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'H')
				arr[i][j] = -1;
			else
				arr[i][j] -= '0';
		}
	memset(dp, -1, sizeof(dp));
	ans = dfs(0, 0);

	cout << ans << endl;

	return 0;
}