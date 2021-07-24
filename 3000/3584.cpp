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
int depth[MAX_N];
int ac[MAX_N][20]; 
vector<int> adj[MAX_N];
int ind[MAX_N];

const int maxLevel = (int)floor(log2(MAX_N));

void getTree(int here, int parent) {
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;

	for (int i = 1; i <= maxLevel; i++)
		ac[here][i] = ac[ac[here][i - 1]][i - 1];

	for (int i = 0; i < adj[here].size(); i++)
		if (adj[here][i] != parent)
			getTree(adj[here][i], here);
}

int getLca(int a, int b) {
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b])
			swap(a, b);

		for (int i = maxLevel; i >= 0; i--)
			if (depth[a] <= depth[ac[b][i]])
				b = ac[b][i];
	}

	int lca = a;
	if (a != b) {
		for (int i = maxLevel; i >= 0; i--) {
			if (ac[a][i] != ac[b][i]) {
				a = ac[a][i];
				b = ac[b][i];
			}
			
		}
        lca = ac[a][0];
	}

	return lca;
}


int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--) {
		for (int i = 0; i < MAX_N; ++i)
			adj[i].clear();
		depth[0] = 0;
		memset(ind, 0, sizeof(ind));

		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			int from, to;
			cin >> from >> to;
			adj[from].push_back(to);
			ind[to]++;
		}
		for (int i = 1; i < n; ++i)
			if (!ind[i]) {
				getTree(i, 0);
				break;
			}

		int a, b;
		cin >> a >> b;
		cout << getLca(a, b) << endl;
		
	}

	return 0;
}
