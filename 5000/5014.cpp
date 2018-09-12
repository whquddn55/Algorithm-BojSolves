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

#define MAX_N 1000001

int f, s, g, u, d;
int dist[MAX_N];

int bfs() {
	queue<int> q;
	memset(dist, -1, sizeof(dist));
	q.emplace(s);
	dist[s] = 0;

	while (q.size()) {
		int here = q.front();
		q.pop();

		if (here == g)
			return dist[here];

		if (here + u <= f && dist[here + u] == -1) {
			q.emplace(here + u);
			dist[here + u] = dist[here] + 1;
		}
		if (here - d >= 1 && dist[here - d] == -1) {
			q.emplace(here - d);
			dist[here - d] = dist[here] + 1;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> f >> s >> g >> u >> d;

	int res = bfs();
	if (res == -1)
		cout << "use the stairs" << endl;
	else
		cout << res << endl;

	return 0;
}