#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 1005
#define MOD 1'000'000'007

int n, m;
bool arr[MAX_N];
vector<pii> adj[MAX_N];

int dist[MAX_N][MAX_N];
pii spfa() {
	pii ans = {n, INF};
	queue<pii> q;
	bool inQ[MAX_N][MAX_N] = {false, };
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dist[i][j] = INF;

	dist[0][0] = 0;
	q.emplace(0, 0);
	inQ[0][0] = true;
	while(q.size()) {
		int hereR = q.front().first;
		int here = q.front().second;
		q.pop();
		inQ[hereR][here] = false;

		for (pii e : adj[here]) {
			int nxt = e.first;
			int cost = e.second;
			int nxtR = hereR + (arr[here] != arr[nxt]);

			if (nxtR > ans.first)
				continue;

			if (dist[nxtR][nxt] > dist[hereR][here] + cost) {
				dist[nxtR][nxt] = dist[hereR][here] + cost;
				if (nxt == m)
					ans = min(ans, pii(nxtR, dist[nxtR][nxt]));
				if (!inQ[nxtR][nxt]) {
					q.emplace(nxtR, nxt);
					inQ[nxtR][nxt] = true;
				}
			} 
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int t;
			cin >> t;
			if (t)
				adj[i].emplace_back(j, t);
		}

	cout << spfa() << endl;;


	return 0;
}