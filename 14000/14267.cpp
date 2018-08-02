#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100000

int n, m;
int cost[MAX_N];
vector<int> adj[MAX_N];

int ans[MAX_N];

void dfs(int here, int sum) {
	ans[here] = sum + cost[here];

	for (auto e : adj[here])
		dfs(e, ans[here]);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t != -1)
			adj[t - 1].push_back(i);
	}
	while (m--) {
		int u, c;
		cin >> u >> c;
		u--;
		cost[u] += c;
	}

	dfs(0, 0);
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;

	return 0;
}