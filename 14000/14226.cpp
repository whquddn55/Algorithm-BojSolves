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

#define MAX_N 2005
#define MOD 1000000007

int s;
bool visited[MAX_N][MAX_N];

int bfs() {
	queue<pair<pii, int>> q;
	q.emplace(pii(1, 0), 0);
	visited[1][0] = true;

	while (q.size()) {
		int here = q.front().first.first;
		int clip = q.front().first.second;
		int hereCost = q.front().second;
		q.pop();

		if (here == s)
			return hereCost;

		if (!visited[here][here]) {
			q.emplace(pii(here, here), hereCost + 1);
			visited[here][here] = true;
		}
		if (here + clip < MAX_N && !visited[here + clip][clip]) {
			q.emplace(pii(here + clip, clip), hereCost + 1);
			visited[here + clip][clip] = true;
		}
		if (here > 1 && !visited[here - 1][clip]) {
			q.emplace(pii(here - 1, clip), hereCost + 1);
			visited[here - 1][clip] = true;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> s;
	cout << bfs() << endl;

	return 0;
}