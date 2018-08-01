#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 1000

int n, m, k;;
char arr[MAX_N];
vector<pii> adj[MAX_N / 2];

int dp[MAX_N / 2][MAX_N]; // i마을에 있고, j번째 카드일때 최대 점수

int getDp(int idx1, int idx2) {
	if (idx2 == n)
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = 0;
	for (auto e : adj[idx1])
		ret = max(ret, getDp(e.first, idx2 + 1) + (e.second == arr[idx2] ? 10 : 0));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> m >> k;
	while (k--) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		u--;
		v--;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}

	memset(dp, -1, sizeof(dp));
	cout << getDp(0, 0) << endl;

	return 0;
}