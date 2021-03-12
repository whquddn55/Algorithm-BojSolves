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

#define MAX_N 10005
#define MOD 1000000007

int n;
vector<pii> adj[MAX_N];

pii bfs(int start) {
	bool visited[MAX_N] = { 0, };
	queue<pii> q;
	q.emplace(start, 0);
	visited[start] = true;

	pii ret = pii(start, 0);
	while (q.size()) {
		int here = q.front().first;
		int hereCost = q.front().second;
		q.pop();

		for (pii ele : adj[here]) {
			int next = ele.first;
			int nextCost = ele.second + hereCost;

			if (visited[next])
				continue;

			q.emplace(next, nextCost);
			visited[next] = true;
			if (ret.second < nextCost) {
				ret = { next, nextCost };
			}
		}
	}
	return ret;
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int f, t, d;
		cin >> f >> t >> d;
		f--;
		t--;
		adj[f].emplace_back(t, d);
		adj[t].emplace_back(f, d);
	}

	int endPoint = bfs(0).first;
	cout << bfs(endPoint).second << endl;

	return 0;
}