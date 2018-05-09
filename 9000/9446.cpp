#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 10001

int n, m;
int cost[MAX_N];
bool bought[MAX_N];
vector<pii> adj[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> cost[i];

	while (m--) {
		int a, x, y;
		cin >> a >> x >> y;

		adj[x].emplace_back(y, a);
		adj[y].emplace_back(x, a);
	}

	for (int i = 1; i <= n; i++) {
		int idx;
		int value = INT_MAX;
		for (int j = 1; j <= n; j++) {
			if (!bought[j] && value > cost[j]) {
				value = cost[j];
				idx = j;
			}
		}
		bought[idx] = true;

		for (int j = 0; j < adj[idx].size(); j++) {
			int parent = adj[idx][j].second;
			int neighbor = adj[idx][j].first;
			
			cost[parent] = min(cost[parent], cost[idx] + cost[neighbor]);
		}
	}

	cout << cost[1] << endl;

	return 0;
}
