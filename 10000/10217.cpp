#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 101
#define MAX_M 10001

struct Data {
	int to, cost, dist;

	Data(const int to, const int cost, const int dist) 
		: to(to), cost(cost), dist(dist) { }
};

int n, m, k;
vector<Data> adj[MAX_N];

int dp[MAX_N][MAX_M];

int getDp(int idx1, int idx2) {
	if (idx2 < 0)
		return INF;
	if (idx1 == n)
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	//cout << idx1 << ", " << idx2 << endl;

	ret = INF;
	for (auto data : adj[idx1]) 
		ret = min(ret, getDp(data.to, idx2 - data.cost) + data.dist);
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < MAX_N; i++)
			adj[i].clear();
		memset(dp, -1, sizeof(dp));

		cin >> n >> m >> k;
		while (k--) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;

			adj[u].emplace_back(v, c, d);
		}

		if (getDp(1, m) >= INF)
			cout << "Poor KCM" << endl;
		else
			cout << getDp(1, m) << endl;
	}
	

	return 0;
}
