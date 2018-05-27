#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 8

int n, m;
int arr[MAX_N][MAX_N];
int ans = 0;

int dy[] = { 0, -1, 1, 0 };
int dx[] = { -1, 0, 0, 1 };

void get(int score, int time) {
	if (time == 3) {
		ans = max(ans, score);
		return;
	}
	bool visited[MAX_N][MAX_N];
	memset(visited, false, sizeof(visited));

	int cnt = 0;
	vector<vector<pii>> s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			if (!visited[i][j] && arr[i][j] != 0) {
				int v = arr[i][j];

				queue<pii> q;
				q.emplace(i, j);
				visited[i][j] = true;
				s.push_back(vector<pii>());
				s[cnt].emplace_back(i, j);

				while (!q.empty()) {
					int hereY = q.front().first;
					int hereX = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nextY = hereY + dy[k];
						int nextX = hereX + dx[k];
						if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
							continue;
						if (visited[nextY][nextX])
							continue;
						if (arr[nextY][nextX] != v)
							continue;
						
						q.emplace(nextY, nextX);
						visited[nextY][nextX] = true;
						s[cnt].emplace_back(nextY, nextX);
					}
				}
				cnt++;
			}
	if (s.size() == 0) {
		ans = max(ans, score);
		return;
	}

	int temp[MAX_N][MAX_N];
	for (int j = 0; j < n; j++)
		for (int k = 0; k < m; k++)
			temp[j][k] = arr[j][k];

	for (int i = 0; i < cnt; i++) {
		for (auto& p : s[i])
			arr[p.first][p.second] = 0;

		for (int i = n - 1; i >= 1; i--)
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) 
					for (int k = i - 1; k >= 0; k--) 
						if (arr[k][j] != 0) {
							arr[i][j] = arr[k][j];
							arr[k][j] = 0;
							break;
						}
			}

		int sum = s[i].size() * s[i].size();
		get(score + sum, time + 1);

		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				arr[j][k] = temp[j][k];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	get(0, 0);
	cout << ans << endl;

	return 0;
}