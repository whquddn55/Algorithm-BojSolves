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

int minT[MAX_N * 4];
int maxT[MAX_N * 4];

int n, m, q;
set<int> adj[MAX_N];

void init(int nodeLeft = 1, int nodeRight = n, int id = 1) {
	if (nodeLeft == nodeRight) {
		minT[id] = *adj[nodeLeft].begin();
		maxT[id] = *adj[nodeLeft].rbegin();
		return;
	}
	int mid = (nodeLeft + nodeRight) / 2;
	init(nodeLeft, mid, id * 2);
	init(mid + 1, nodeRight, id * 2 + 1);
	minT[id] = min(minT[id * 2], minT[id * 2 + 1]);
	maxT[id] = max(maxT[id * 2], maxT[id * 2 + 1]);
}

void update(int idx, pii value, int nodeLeft = 1, int nodeRight = n, int id = 1) {
	if (idx < nodeLeft || idx > nodeRight)
		return;
	if (nodeLeft == nodeRight) {
		minT[id] = value.first;
		maxT[id] = value.second;
		return;
	}
	int mid = (nodeLeft + nodeRight) / 2;
	update(idx, value, nodeLeft, mid, id * 2);
	update(idx, value, mid + 1, nodeRight, id * 2 + 1);
	minT[id] = min(minT[id * 2], minT[id * 2 + 1]);
	maxT[id] = max(maxT[id * 2], maxT[id * 2 + 1]);
}

pii query(int left, int right, int nodeLeft = 1, int nodeRight = n, int id = 1) {
	if (right < nodeLeft || nodeRight < left)
		return pii(INF, -INF);
	if (left <= nodeLeft && nodeRight <= right)
		return pii(minT[id], maxT[id]);
	int mid = (nodeLeft + nodeRight) / 2;
	pii l = query(left, right, nodeLeft, mid, id * 2);
	pii r = query(left, right, mid + 1, nodeRight, id * 2  + 1);
	return pii(min(l.first, r.first), max(l.second, r.second));
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m >> q;
	while(m--) {
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
	}

	for (int i = 1; i <= n; ++i) 
		adj[i].insert(i);

	init();
	while(q--) {
		int c, f, t;
		cin >> c >> f >> t;
		if (c == 1) {
			pii res = query(f, t);
			if (f <= res.first && res.second <= t)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if (c == 2) {
			bool check = (t == *adj[f].begin()) || (t == *adj[f].rbegin());
			adj[f].erase(t);
			if (check) 
				update(f, pii(*adj[f].begin(), *adj[f].rbegin()));
		} 
		else {
			bool check = (t < *adj[f].begin()) || (t > *adj[f].rbegin());
			adj[f].insert(t);
			if (check)
				update(f, pii(*adj[f].begin(), *adj[f].rbegin()));
		}
	}
	
	return 0;
}
