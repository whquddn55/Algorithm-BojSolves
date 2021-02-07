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
int arr[MAX_N];
vector<int> adj[MAX_N];
int indegree[MAX_N];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int from;
			cin >> from;
			from--;
			adj[from].emplace_back(i);
		}
		indegree[i] = m;
	}

	priority_queue<pii,vector<pii>,greater<pii>> q;
	for (int i = 0; i < n; ++i)
		if (!indegree[i])
			q.emplace(arr[i], i);

	int ret = -INF;
	while (q.size()) {
		int here = q.top().second;
		int cost = q.top().first;
		q.pop();

		ret = max(ret, cost);

		for (auto next : adj[here]) {
			indegree[next]--;
			if (!indegree[next]) 
				q.emplace(cost + arr[next], next);
		}
	}

	cout << ret << endl;

	return 0;
}