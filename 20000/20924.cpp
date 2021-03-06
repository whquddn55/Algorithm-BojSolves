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

#define MAX_N 200005
#define MOD 1000000007

int n, r;
vector<pii> adj[MAX_N];

void bfs() {
	queue<pii> q;
	bool visited[MAX_N] = { 0, };
	pii result(0, 0);

	q.emplace(r, 0);
	visited[r] = true;
	bool gigaFound = false;
	while (q.size()) {
		int here = q.front().first;
		int hereCost = q.front().second;
		q.pop();

		if (!gigaFound && 
			((adj[here].size() > 2) || (here != r && adj[here].size() ==  1) || (here == r && adj[here].size() > 1))) {
			result.first = hereCost;
			gigaFound = true;
			hereCost = 0;
		}

		if (gigaFound)
			result.second = max(result.second, hereCost);

		for (pii next : adj[here]) {
			if (!visited[next.first]) {
				q.emplace(next.first, hereCost + next.second);
				visited[next.first] = true;
			}
		}
	}
	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> r;
	r--;
	for (int i = 0; i < n - 1; ++i) {
		int a, b, d;
		cin >> a >> b >> d;
		a--;
		b--;
		adj[a].emplace_back(b, d);
		adj[b].emplace_back(a, d);
	}

	bfs();
	
	return 0;
}