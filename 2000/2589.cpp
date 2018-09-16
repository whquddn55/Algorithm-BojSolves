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

#define MAX_N 50

int n, m;
char arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

int ans = 0;

void bfs(int startY, int startX) {
	queue<pair<pii, int>> q;
	q.emplace(pii(startY, startX), 0);
	visited[startY][startX] = true;

	while (q.size()) {
		int hereY = q.front().first.first;
		int hereX = q.front().first.second;
		int hereDist = q.front().second;
		q.pop();


		ans = max(ans, hereDist);

		for (int i = 0; i < 4; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];
			if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
				continue;
			if (visited[nextY][nextX] || arr[nextY][nextX] == 'W')
				continue;

			q.emplace(pii(nextY, nextX), hereDist + 1);
			visited[nextY][nextX] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 'L') {
				memset(visited, false, sizeof(visited));
				bfs(i, j);
			}

	cout << ans << endl;

	return 0;
}