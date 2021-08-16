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
#define MAX_N 10005
#define MOD 1000000007

int n, m;
vector<pii> adj[MAX_N];
vector<pair<pii, int>> reverseAdj[MAX_N];
int ind[MAX_N];
int s, e;
int dist[MAX_N];


void tpSort() {
	queue<int> q;
	q.emplace(s);
	dist[s] = 0;
	while(q.size()) {
		int here = q.front();
		q.pop();

		for (auto e : adj[here]) {
			int nxt = e.first;
			int nxtCost = e.second;

			dist[nxt] = max(dist[nxt], dist[here] + nxtCost);
			--ind[nxt];
			if (!ind[nxt])
				q.emplace(nxt);
		}
	}

	cout << dist[e] << endl;
}

void edgeCnt() {
	queue<int> q;
	bool visited[MAX_N * 10] = {0, };
	q.emplace(e);
	int cnt = 0;
	while(q.size()) {
		int here = q.front();
		q.pop();

		for (auto e : reverseAdj[here]) {
			int nxt = e.first.first;
			int nxtCost = e.first.second;
			int idx = e.second;
			if (visited[idx] || (dist[here] - nxtCost) != dist[nxt])
				continue;
 			visited[idx] = true;
			q.emplace(nxt);
			++cnt;
		}
	}
	cout << cnt << endl;
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	while(m--) {
		int f, t, c;
		cin >> f >> t >> c;
		adj[f].emplace_back(t, c);
		reverseAdj[t].emplace_back(pii(f, c), m);
		++ind[t];
	}

	cin >> s >> e;

	tpSort();
	edgeCnt();
	
	return 0;
}
