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

#define MAX_N 10
#define MOD 1000000007

int n, m;
int arr[MAX_N];
pair<int, pii> edges[27];
int deg[MAX_N];
vector<int> addedEdges;

int parent[MAX_N];
int find(int u) {
	if (parent[u] == u)
		return u;
	else
		return find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return;
	
	parent[u] = v;
}

vector<int> result;
int minValue = INF;
void dfs(int here) {
	if (addedEdges.size() == n - 1) {
		int sum = 0;
		for (auto index : addedEdges)
			sum += edges[index].first;
		if (sum < minValue) {
			minValue = sum;
			result = addedEdges;
		}
		return;
	}
	if (here == m)
		return;
	
	// here추가 가능한지 판별 후 추가
	int f = edges[here].second.first;
	int t = edges[here].second.second;
	// here 추가 안 함
	dfs(here + 1);
	if ((find(f) == find(t)) ||
		(deg[f] == arr[f]) ||
		(deg[t] == arr[t]))
		return;
	
	int tf = find(f);
	merge(f, t);
	++deg[f];
	++deg[t];
	addedEdges.push_back(here);
	dfs(here + 1);
	parent[tf] = tf;
	--deg[f];
	--deg[t];
	addedEdges.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < m; ++i) {
		cin >> edges[i].second >> edges[i].first;
		edges[i].second.first--;
		edges[i].second.second--;
	}
	sort(edges, edges + m);

	for (int i = 0; i < n; ++i) 
		parent[i] = i;
	
	dfs(0);

	if (minValue != INF) {
		cout << "YES" << endl;
		for (auto index : result) {
			pii out = edges[index].second;
			cout << pii(out.first + 1, out.second + 1) << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}
	
	return 0;
}