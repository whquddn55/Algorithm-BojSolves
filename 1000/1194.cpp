#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 51

int n, m;
int ans = INF;
char arr[MAX_N][MAX_N];
bool visited[1 << 7][MAX_N][MAX_N];
vector<pii> keys;

int dy[] = { 0, -1, 1, 0 };
int dx[] = { -1, 0, 0, 1 };

int bfs1(pii start) {
	queue<pair<pii, pii>> q;
	q.emplace(start, make_pair(0, 0));
	visited[0][start.first][start.second] = true;

	int ans = INF;
	while (!q.empty()) {
		int hereY = q.front().first.first;
		int hereX = q.front().first.second;
		int hereKey = q.front().second.first;
		int cost = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];
			int nextKey = hereKey;
			if (islower(arr[nextY][nextX]))
				nextKey |= 1 << (arr[nextY][nextX] - 'a');

			if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
				continue;
			if (visited[nextKey][nextY][nextX])
				continue;
			if (arr[nextY][nextX] == '#')
				continue;
			if (isupper(arr[nextY][nextX])) 
				if (!(hereKey & (1 << (arr[nextY][nextX] - 'A'))))
					continue;
			
			
			q.emplace(make_pair(nextY, nextX), make_pair(nextKey, cost + 1));
			visited[nextKey][nextY][nextX] = true;

			if (arr[nextY][nextX] == '1')
				ans = min(ans, cost + 1);
		}
	}
	return ans == INF ? -1 : ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m;
	pii start;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0')
				start = { i, j };
		}

	cout << bfs1(start) << endl;


	return 0;
}
