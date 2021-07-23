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
#define MAX_N 100005
#define MOD 1000000007

int n, m;
int parent[MAX_N];
int dist[MAX_N];
pii find(int u) {
	if (parent[u] == u) 
		return {u, 0};
	pii ret = find(parent[u]);
	parent[u] = ret.first;
	return {ret.first, dist[u] += ret.second};
}

void merge(int u, int v, int c) {
	int pu = find(u).first;
	int pv = find(v).first;

	if (pu == pv)
		return;
	parent[pu] = pv;
	dist[pu] = -dist[u] + dist[v] + c;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);


	while(true) {
		for (int i = 0; i < MAX_N; ++i)
			parent[i] = i;
		memset(dist, 0, sizeof(dist));
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		while(m--) {
			
			char c;
			cin >> c;
			if (c == '!') {
				int f, t, c;
				cin >> f >> t >> c;
				
				merge(f, t, c);
			}
			else {
				int f, t;
				cin >> f >> t;
				if (find(f).first != find(t).first)
					cout << "UNKNOWN" << endl;
				else
					cout << dist[f] - dist[t] << endl;
			}
		}
	}
	
	return 0;
}
