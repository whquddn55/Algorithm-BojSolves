#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define	MAX_SIZE 201

int n, m;
int dist[MAX_SIZE][MAX_SIZE];
int prv[MAX_SIZE][MAX_SIZE];
vector<int> ans;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					prv[i][j] = k;
				}
}

void getPath(int u, int v) {
	if (prv[u][v] != 0) {
		getPath(u, prv[u][v]);
		ans.push_back(prv[u][v]);
		getPath(prv[u][v], v);
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + MAX_SIZE * MAX_SIZE, INF);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		dist[from][to] = cost;
		dist[to][from] = cost;
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "- ";
			else {
				ans.clear();
				getPath(i, j);
				if (ans.size() == 0)
					cout << j << ' ';
				else
					cout << ans[0] << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}
