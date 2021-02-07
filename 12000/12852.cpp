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

#define MAX_N 1000005

int n;
int pre[MAX_N];

int bfs() {
	queue<pii> q;
	q.emplace(n, 0);
	pre[n] = n;

	int ret = INF;
	while (q.size()) {
		int here = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (here == 1) {
			ret = cost;
			break;
		}
		else {
			if (here % 3 == 0 && !pre[here / 3]) {
				q.emplace(here / 3, cost + 1);
				pre[here / 3] = here;
			}
			if (here % 2 == 0 && !pre[here / 2]) {
				q.emplace(here / 2, cost + 1);
				pre[here / 2] = here;
			}
			if (!pre[here - 1]) {
				q.emplace(here - 1, cost + 1);
				pre[here - 1] = here;
			}
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	cout << bfs() << endl;
	stack<int> s;
	int here = 1;
	while (here != n) {
		s.push(here);
		here = pre[here];
	}
	cout << n << ' ';
	while (s.size()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}