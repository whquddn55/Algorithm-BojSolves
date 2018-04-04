#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 51

int n, m;
int vcnt = 0;
int source[MAX_V];
int sink[MAX_V];
int visited[MAX_V];
int matched[MAX_V][MAX_V];

int dfs(int here) {
	visited[here] = vcnt;
	for (int i = 0; i < m; i++) {
		if (matched[here][i])
			continue;
		if (sink[i]) {
			--sink[i];
			matched[here][i] = 1;
			return 1;
		}
		for (int j = 0; j < n; j++) {
			if (!matched[j][i])
				continue;
			if (visited[j] == vcnt)
				continue;
			if (dfs(j)) {
				matched[j][i] = 0;
				matched[here][i] = 1;
				return 1;
			}
		}
	}
	return 0;
}

int cycle(int here, int there, pii low) {
	visited[here] = vcnt;
	for (int i = 0; i < m; i++) {
		if (matched[here][i])
			continue;
		if (make_pair(here, i) <= low)
			continue;
		if (i == there) {
			matched[here][i] = 1;
			return 1;
		}

		for (int j = 0; j < n; j++) {
			if (!matched[j][i])
				continue;
			if (make_pair(j, i) <= low)
				continue;
			if (visited[j] == vcnt)
				continue;
			if (cycle(j, there, low)) {
				matched[j][i] = 0;
				matched[here][i] = 1;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> source[i];
	for (int i = 0; i < m; i++)
		cin >> sink[i];

	if (accumulate(source, source + n, 0) != accumulate(sink, sink + m, 0)) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < source[i]; j++) {
			++vcnt;
			if (!dfs(i)) {
				cout << -1 << endl;
				return 0;
			}
		}
	if (accumulate(sink, sink + m, 0) != 0) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!matched[i][j])
				continue;
			++vcnt;
			if (cycle(i, j, make_pair(i, j)))
				matched[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << matched[i][j];
		cout << endl;
	}

	return 0;
}
