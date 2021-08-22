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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 100005
#define MOD 1000003

int n;
int arr[MAX_N];
vector<pii> adj[MAX_N];
pll sparse[MAX_N][20];

void dfs(int here, int parent) {
	for (auto e : adj[here]) {
		if (e.first == parent)
			continue;
		sparse[e.first][0] = {here, e.second};
		dfs(e.first, here);
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	dfs(0, -1);
	for (int j = 1; j < 20; ++j) 
		for (int i = 0; i < n; ++i) 
			sparse[i][j] = {sparse[sparse[i][j - 1].first][j - 1].first, sparse[i][j - 1].second + sparse[sparse[i][j - 1].first][j - 1].second};

	for (int i = 0; i < n; ++i) {
		int here = i;
		int remain = arr[i];
		while(true) {
			int nxt = -1;
			for (int j = 19; j >= 0; --j) {
				if (sparse[here][j].second <= remain) {
					nxt = sparse[here][j].first;
					remain -= sparse[here][j].second;
					break;
				}
			}
			
			if (nxt == -1 || nxt == here) {
				cout << here + 1 << endl;
				break;
			}
			here = nxt;
		}
	}
	
	return 0;
}
