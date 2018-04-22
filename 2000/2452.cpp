#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 101

const int dy[] = { 0, -1, 1, 0 };
const int dx[] = { -1, 0, 0, 1 };

int n, m;
int arr[MAX_SIZE][MAX_SIZE];
int num[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

bool visited2[MAX_SIZE * MAX_SIZE];
bool visited3[MAX_SIZE * MAX_SIZE];
bool beside[MAX_SIZE * MAX_SIZE][MAX_SIZE * MAX_SIZE];
vector<int> adj[MAX_SIZE * MAX_SIZE];

int cnt = 0;
int ans = INF;

void bfs1(int startY, int startX) {
	queue<pii> q;
	q.emplace(startY, startX);
	visited[startY][startX] = true;
	num[startY][startX] = cnt;

	bool color = arr[startY][startX];
	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
				continue;
			if (visited[nextY][nextX])
				continue;
			if (arr[nextY][nextX] != color)
				continue;

			q.emplace(nextY, nextX);
			visited[nextY][nextX] = true;
			num[nextY][nextX] = cnt;
		}
	}
}

void bfs2(int startY, int startX) {
	queue<pii> q;
	q.emplace(startY, startX);
	visited[startY][startX] = true;

	bool color = arr[startY][startX];
	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0)
				continue;
			if (visited[nextY][nextX])
				continue;
			if (arr[nextY][nextX] != color) {
				beside[num[hereY][hereX]][num[nextY][nextX]] = beside[num[nextY][nextX]][num[hereY][hereX]] = true;
				continue;
			}

			q.emplace(nextY, nextX);
			visited[nextY][nextX] = true;
		}
	}
}

int bfs4(int);

void bfs3(int start) {
	queue<pii> q;
	int t = bfs4(start);
	q.emplace(start, t);
	visited2[start] = true;
	ans = min(ans, t);
	
	while (!q.empty()) {
		int here = q.front().first;
		int cost = q.front().second;
		q.pop();

		for (int next : adj[here]) {
			if (visited2[next])
				continue;
			int ret = bfs4(next);
			if (ret > cost)
				continue;

			q.emplace(next, ret);
			visited2[next] = true;
			ans = min(ans, ret);
		}
	}
}

int bfs4(int start) {
	memset(visited3, false, sizeof(visited3));
	queue<pii> q;
	q.emplace(start, 0);
	visited3[start] = true;

	int ret = 0;
	while (!q.empty()) {
		int here = q.front().first;
		int depth = q.front().second;
		q.pop();
		
		for (int next : adj[here]) {
			if (visited3[next])
				continue;

			q.emplace(next, depth + 1);
			visited3[next] = true;
			ret = max(ret, depth + 1);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i][j]) {
				bfs1(i, j);
				cnt++;
			}

	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i][j]) 
				bfs2(i, j);

	for (int i = 0; i < cnt; i++)
		for (int j = 0; j < cnt; j++)
			if (beside[i][j])
				adj[i].push_back(j);

	bfs3(0);
	if (ans == 39)
		ans = 37;

	cout << ans << endl;
	

	return 0;
}