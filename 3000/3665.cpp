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
#define MAX_N 505
#define MOD 1000003

int n;
int arr[MAX_N];
int m;
bool sw[MAX_N][MAX_N];
vector<int> adj[MAX_N];
int ind[MAX_N];

int ans[MAX_N];
bool tpSort(int index) {
	if (index == n)
		return true;

	int here = -1;
	for (int i = 1; i <= n; ++i)
		if (ind[i] == 0) {
			if (here != -1)
				return false;
			here = i;
			ind[i] = -1;
		}
	if (here == -1)
		return false;
	
	ans[index] = here;
	for (int nxt : adj[here])
		ind[nxt]--;
	return tpSort(index + 1);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--) {
		memset(sw, false, sizeof(sw));
		memset(ind, 0, sizeof(ind));
		for (int i = 0; i < MAX_N; ++i)
			adj[i].clear();

		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cin >> m;
		while(m--) {
			int f, t;
			cin >> f >> t;
			sw[f][t] = sw[t][f] = true;
		}

		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				if (sw[arr[i]][arr[j]]) {
					adj[arr[j]].push_back(arr[i]);
					++ind[arr[i]];
				}
				else{
					adj[arr[i]].push_back(arr[j]);
					++ind[arr[j]];
				}
			}

		bool res = tpSort(0);
		if (!res)
			cout << "IMPOSSIBLE" << endl;
		else {
			for (int i = 0; i < n; ++i)
				cout << ans[i] << ' ';
			cout << endl;
		}
	}
	
	return 0;
}
