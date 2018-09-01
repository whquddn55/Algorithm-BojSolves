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

#define MAX_N 100001
#define MAX_M 2000000

struct DisjointSet {
	int parent[MAX_N];

	DisjointSet() {
		for (int i = 0; i < MAX_N; i++) 
			parent[i] = i;
	}

	int find(int u) {
		if (parent[u] == u)
			return u;
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u != v) 
			parent[v] = u;
	}
};

int n, m;
vector<int> adj[MAX_N];
DisjointSet dset;

map<int, int> group;
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for (int i = 1; i <= n; i++)
		group.emplace(i, 1);

	for (int i = 1; i <= n; i++) {
		map<int, int> toErase = group;
		int u = dset.find(i);
		for (auto e : adj[i])
			--toErase[dset.find(e)];

		toErase[u] = 0;
		for (auto e : toErase) {
			if (e.second) {
				dset.merge(u, e.first);
				group[u] += group[e.first];
				group.erase(e.first);
			}
		}
	}

	cout << group.size() << endl;
	for (auto e : group)
		ans.emplace_back(e.second);
	sort(ans.begin(), ans.end());
	for (auto e : ans)
		cout << e << ' ';
	cout << endl;

	return 0;
}