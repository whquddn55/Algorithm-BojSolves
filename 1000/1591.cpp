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
#define MAX_N 1005
#define MOD 1000000007

int n, m;
int arr[MAX_N][MAX_N];
int adj[MAX_N * 2][MAX_N * 2];

map<vector<int>, int> indexer;
int vcnt = 0;
vector<int> vertex[MAX_N];
int ind[MAX_N * 2];
int outd[MAX_N * 2];

vector<int> path;

void dfs(int here) {
	for (int i = 0; i < vcnt; ++i) {
		if (adj[here][i]) {
			adj[here][i]--;
			dfs(i);
		}
	}
	path.emplace_back(here);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n - m + 1; ++i) 
		for (int j = 0; j < m; ++j) 
			cin >> arr[i][j];

	for (int i = 0; i < n - m + 1; ++i) {
		vector<int> from(arr[i], arr[i] + m - 1);
		int fromIdx;
		if (indexer.find(from) == indexer.end()) {
			vertex[vcnt] = from;
			indexer[from] = vcnt;
			fromIdx = vcnt++;
		}
		else 
			fromIdx = indexer[from];
		

		vector<int> to(arr[i] + 1, arr[i] + m);
		int toIdx;
		if (indexer.find(to) == indexer.end()){
			vertex[vcnt] = to;
			indexer[to] = vcnt;
			toIdx = vcnt++;
		}
		else
			toIdx = indexer[to];
		adj[fromIdx][toIdx]++;
		outd[fromIdx]++;
		ind[toIdx]++;
	}

	int start = 0;
	for (int i = 0; i < vcnt; ++i)
		if (ind[i] == outd[i] - 1) {
			start = i;
			break;
		}

	dfs(start);

	reverse(path.begin(), path.end());

	for (int e : path)
		cout << vertex[e][0] << ' ';
	for (int i = 1; i < vertex[path.back()].size(); ++i)
		cout << vertex[path.back()][i] << ' ';
	
    return 0;
}