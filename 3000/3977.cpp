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
vector<int> adj[MAX_N]; // 인접리스트

int cnt, sccSize;
int dfsn[MAX_N];
bool finished[MAX_N];
stack<int> st;
int sn[MAX_N];
vector<vector<int>> scc;
int ind[MAX_N];

int dfs(int here) {
	dfsn[here] = cnt++;
	st.push(here);

	int result = dfsn[here];
	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];

		if (dfsn[next] == -1)
			result = min(result, dfs(next));
		else if (!finished[next])
			result = min(result, dfsn[next]);
	}

	if (result == dfsn[here]) {
		vector<int> curScc;

		while (true) {
			int top = st.top();
			st.pop();
			curScc.push_back(top);
			finished[top] = true;
			sn[top] = sccSize;

			if (top == here)
				break;
		}
        
        sort(curScc.begin(), curScc.end());

		scc.push_back(curScc);
		sccSize++;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < MAX_N; ++i) 
			adj[i].clear();
		scc.clear();
		memset(dfsn, -1, sizeof(dfsn));
		memset(sn, 0, sizeof(sn));
		memset(finished, 0, sizeof(finished));
		memset(ind, 0, sizeof(ind));
		cnt = sccSize = 0;
		
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int from, to;
			cin >> from >> to;
			adj[from].push_back(to);
		}

		for (int i = 0; i < n; i++)
			if (dfsn[i] == -1)
				dfs(i);

		for (int i = 0; i < n; ++i)
			for (auto e : adj[i]) {
				if (sn[e] != sn[i])
					ind[sn[e]]++;
			}

		int ans = -1;
		for (int i = 0; i < sccSize; ++i) {
			if (ind[i] == 0) {
				if (ans == -1)
					ans = i;
				else 
					ans = -2;
			}
		}
		
		if (ans == -2)
			cout << "Confused" << endl;
		else {
			for (auto e : scc[ans])
				cout << e << endl;
		}
		cout << endl;
			
	}

	return 0;
}
