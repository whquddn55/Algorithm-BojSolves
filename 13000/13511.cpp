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
ll dist[MAX_N][20];
vector<pii> adj[MAX_N];

const int maxLevel = (int)floor(log2(MAX_N));

void getTree(int here, int parent, int parentDist) {
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;
	dist[here][0] = parentDist;

	for (int i = 1; i <= maxLevel; i++) {
		ac[here][i] = ac[ac[here][i - 1]][i - 1];
		dist[here][i] = dist[ac[here][i - 1]][i - 1] + dist[here][i - 1];
	}

	for (int i = 0; i < adj[here].size(); i++)
		if (adj[here][i].first != parent)
			getTree(adj[here][i].first, here, adj[here][i].second);
}

ll getDist(int a, int b) {
	ll result = 0;
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b])
			swap(a, b);
		
		for (int i = maxLevel; i >= 0; --i) 
			if (depth[a] <= depth[ac[b][i]]) {
				result += dist[b][i];
				b = ac[b][i];
			}
	}


	if (a != b) {
		for (int i = maxLevel; i >= 0; --i) {
			if (ac[a][i] != ac[b][i]) {
				result += dist[a][i];
				result += dist[b][i];
				a = ac[a][i];
				b = ac[b][i];
			}
		}
		if (ac[a][0] == b)
			result += dist[a][0];
		else if (ac[b][0] == a)
			result += dist[b][0];
		else
			result += dist[a][0] + dist[b][0];
	}
	
	return result;
}

pii getPathLen(int a, int b) {
	pii result = {0, 0};
	if (depth[a] != depth[b]) {
		bool swapped = false;
		if (depth[a] > depth[b]){
			swap(a, b);
			swapped = true;
		}
		for (int i = maxLevel; i >= 0; i--)
			if (depth[a] <= depth[ac[b][i]]) {
				if (swapped)
					result.first += 1 << i;
				result.second += 1 << i;
				b = ac[b][i];
			}
	}

	if (a != b) {
		for (int i = maxLevel; i >= 0; i--) {
			if (ac[a][i] != ac[b][i]) {
				result.first += 1 << i;
				result.second += 1 << (i + 1);
				a = ac[a][i];
				b = ac[b][i];
			}
		}
		result.first += 1;
		result.second += 3;
	}
	else {
		result.first += 1;
		result.second += 1;
	}

	return result;
}

int getKth(int a, int k) {
	int result = a;
	while (k) {
		int an = (int)floor(log2(k));
		result = ac[result][an];
		k -= 1 << an;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int f, t, c;
		cin >> f >> t >> c;
		adj[f].emplace_back(t, c);
		adj[t].emplace_back(f, c);
	}

	getTree(1, 0, 0);

	cin >> m;
	while(m--) {
		int o;
		cin >> o;
		if (o == 1) {
			int f, t;
			cin >> f >> t;
			cout << getDist(f, t) << endl;
		}
		else {
			int f, t, k;
			cin >> f >> t >> k;
			pii len = getPathLen(f, t);
			if (len.first >= k)
				cout << getKth(f, k - 1) << endl;
			else
				cout << getKth(t, len.second - k) << endl;
		}
	}


	return 0;
}
