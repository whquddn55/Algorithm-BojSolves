#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 100001

int n, m, l;
bool visited[MAX_N];
int dist[MAX_N];
int prv[MAX_N];
vector<int> arr;
vector<pii> graph[MAX_N];

int ans;

pii dfs(int here, int parent, int d) {
	visited[here] = true;
	dist[here] = d;
	prv[here] = parent;
	pii ret(0, here);

	for (auto& there : graph[here]) {
		if (there.first == parent)
			continue;

		auto w = dfs(there.first, here, d + there.second);
		w.first += there.second;
		ret = max(ret, w);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> l;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		graph[a].emplace_back(b, t);
		graph[b].emplace_back(a, t);
	}
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;
		pii ans1 = dfs(i, -1, 0);
		pii ans2 = dfs(ans1.second, -1, 0);

		int here = ans2.second;
		int rad = INF;
		while (here != -1) {
			rad = min(rad, max(abs(dist[ans1.second] - dist[here]), abs(dist[ans2.second] - dist[here])));
			here = prv[here];
		}
		ans = max(ans, ans2.first);
		arr.push_back(rad);
	}

	sort(arr.begin(), arr.end(), greater<int>());

	if (arr.size() > 1)
		ans = max(ans, arr[0] + arr[1] + l);
	if (arr.size() > 2)
		ans = max(ans, arr[1] + arr[2] + 2 * l);

	cout << ans << endl;

	return 0;
}
