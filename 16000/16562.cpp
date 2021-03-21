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
#define MOD 1000000007

#define MAX_N 10005

int n, m, k;
int arr[MAX_N];
vector<int> adj[MAX_N];
bool visited[MAX_N];

int dfs(int here) {
	int ret = arr[here];
	for (int next : adj[here]) {
		if (visited[next])
			continue;
		visited[next] = true;
		ret = min(ret, dfs(next));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	while (m--) {
		int f, t;
		cin >> f >> t;
		f--; t--;
		adj[f].emplace_back(t);
		adj[t].emplace_back(f);
	}

	int result = 0;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			result += dfs(i);
		}
	}
	if (result > k)
		cout << "Oh no" << endl;
	else
		cout << result << endl;
	

	return 0;
}