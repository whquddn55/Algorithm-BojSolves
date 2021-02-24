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
#define MOD 1000000007

int n, m;
int visited[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	queue<int> q;
	for (int i = 0; i < m; ++i) {
		int temp;
		cin >> temp;
		q.emplace(temp);
		visited[temp] = 1;
	}

	while (q.size()) {
		int here = q.front();
		q.pop();

		int bitwise = 1;
		while (bitwise < n) {
			int next = here ^ bitwise;
			bitwise <<= 1;
			if (next > n || visited[next])
				continue;

			visited[next] = visited[here] + 1;
			q.emplace(next);
		}
	}

	int result = 1;
	for (int i = 0; i <= n; ++i)
		result = max(result, visited[i]);
	cout << result - 1 << endl;

	return 0;
}