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
pii arr[MAX_N];
bool visited[MAX_N];

int bfs() {
	queue<pii> q;
	q.emplace(0, 0);
	visited[0] = true;

	while (q.size()) {
		int here = q.front().first;
		int hereCost = q.front().second;
		q.pop();

		if (arr[here].first + arr[here].second >= m)
			return hereCost;

		int nextBound = upper_bound(arr + here, arr + n, pii(arr[here].first + arr[here].second, INF)) - arr;
		int maxNext = -1;
		int maxNextIndex = -1;
		for (int i = here + 1; i < nextBound; ++i) {
			if (!visited[i]) {
				if (maxNext < arr[i].first + arr[i].second) {
					maxNext = arr[i].first + arr[i].second;
					maxNextIndex = i;
				}
			}
		}
		if (maxNext != -1) {
			q.emplace(maxNextIndex, hereCost + 1);
			visited[maxNextIndex] = true;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first;
	for (int i = 0; i < n; ++i)
		cin >> arr[i].second;
	sort(arr, arr + n);


	cout << bfs() << endl;

	return 0;
}