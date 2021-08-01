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
int a, b, c;
vector<pii> adj[MAX_N];
map<int, int> mapper;
int idx[MAX_N];
bool ans[MAX_N];

int dist[3][MAX_N];
queue<int> q;
bool inQ[MAX_N];
void spfa(int index, int start) {
	q.emplace(start);
	inQ[start] = true;
	dist[index][start] = 0;

	while(q.size()) {
		int here = q.front();
		q.pop();

		inQ[here] = false;

		for (auto e : adj[here]) {
			if (dist[index][here] + e.second < dist[index][e.first]) {
				dist[index][e.first] = dist[index][here] + e.second;
				if (!inQ[e.first]) {
					q.emplace(e.first);
					inQ[e.first] = true;
				}
			}
		}
	}
}

int tree[MAX_N * 4];

void init(int nodeLeft = 1, int nodeRight = n, int id = 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (nodeLeft == nodeRight) {
		tree[id] = INF;
		return;
	}
	init(nodeLeft, mid, id * 2);
	init(mid + 1, nodeRight, id * 2 + 1);
	tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}

void update(int index, int value, int nodeLeft = 1, int nodeRight = n, int id = 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (index < nodeLeft || nodeRight < index) 
		return;
	
	if (nodeLeft == nodeRight) {
		tree[id] = min(tree[id], value);
		return;
	}

	update(index, value, nodeLeft, mid, id * 2);
	update(index, value, mid + 1, nodeRight, id * 2 + 1);
	tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}

int query(int left, int right, int nodeLeft = 1, int nodeRight = n, int id = 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (right < nodeLeft || nodeRight < left)
		return INF; 
	if (left <= nodeLeft && nodeRight <= right) 
		return tree[id];

	return min(query(left, right, nodeLeft, mid, id * 2), query(left, right, mid + 1, nodeRight, id * 2 + 1));
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	for (int i = 0; i < 3; ++i)
		fill(dist[i], dist[i] + MAX_N, INF);

	for (int i = 0; i < MAX_N; ++i)
		idx[i] = i;

	cin >> n >> a >> b >> c;
	init();
	cin >> m;
	while(m--) {
		int f, t, c;
		cin >> f >> t >> c;
		adj[f].emplace_back(t, c);
		adj[t].emplace_back(f, c);
	}

	spfa(0, a);
	spfa(1, b);
	spfa(2, c);

	for (int i = 1; i <= n; ++i)
		if (mapper.find(dist[1][i]) == mapper.end()) 
			mapper[dist[1][i]] = 0;

	int cnt = 0;
	for (auto& e : mapper)
		e.second = ++cnt;

	sort(idx + 1, idx + n + 1, [](int x, int y) -> bool {
		if (dist[0][x] == dist[0][y]) {
			if (dist[1][x] == dist[1][y])
				return dist[2][x] < dist[2][y];
			return dist[1][x] < dist[1][y];
		}
		return dist[0][x] < dist[0][y];
	});


	int prv = -1;
	stack<pii> st;
	for (int i = 1; i <= n; ++i) {
		int j = idx[i];
		if (prv == dist[0][j])
			ans[j] = true;
		else 
			while(st.size()) {
				update(st.top().first, st.top().second);
				st.pop();
			}
		if (dist[2][j] > query(1, mapper[dist[1][j]] - 1))
			ans[j] = false;
		else
			ans[j] = true;
		
		prv = dist[0][j];
		st.emplace(mapper[dist[1][j]], dist[2][j]);
	}

	int q;
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		cout << (ans[t] ? "YES" : "NO") << endl;
	}

	return 0;
}
