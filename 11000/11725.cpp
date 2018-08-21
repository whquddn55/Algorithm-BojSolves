#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_N 100000

int n;
int parent[MAX_N];
vector<int> adj[MAX_N];

void dfs(int here, int p) {
	parent[here] = p;
	for (auto next : adj[here])
		if (next != p)
			dfs(next, here);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	dfs(0, -1);
	for (int i = 1; i < n; i++)
		cout << parent[i] + 1 << endl;
	
	return 0;
}