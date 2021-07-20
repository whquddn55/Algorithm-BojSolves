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
#define MAX_N 2600
#define MOD 1000000007

int n;
map<string, int> m;
vector<int> adj[MAX_N];

int cnt, sccSize;
int dfsn[MAX_N];
bool finished[MAX_N];
stack<int> st;
int sn[MAX_N];
vector<vector<int>> scc;

int dfs(int here) {
	dfsn[here] = ++cnt;
	st.push(here);

	int result = dfsn[here];
	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];

		if (dfsn[next] == 0)
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

		scc.push_back(curScc);
		sccSize++;
	}

	return result;
}


ll dp[MAX_N];
ll getDp(int idx) {
	ll& ret = dp[idx];
	if (ret != -1)
		return ret;
	ret = 1;
	for (auto e : adj[idx]) {
		if (sn[e] == sn[idx])
			continue;
		ret += getDp(e);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		if (m.find(s) == m.end())
			m[s] = ++cnt;
		int adjSize;
		cin >> adjSize;
		while(adjSize--) {
			string t;
			cin >> t;
			if (m.find(t) == m.end())
				m[t] = ++cnt;
			adj[m[s]].emplace_back(m[t]);
		}
	}

	for (int i = 1; i <= m.size(); i++)
		if (dfsn[i] == 0)
			dfs(i);
	
	string target;
	cin >> target;

	memset(dp, -1 ,sizeof(dp));
	cout << getDp(m[target]) << endl;

	return 0;
}
