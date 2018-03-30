#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 10001

int v, e;

int cnt,  sccSize;
int dfsn[MAX_V];
bool finished[MAX_V];
stack<int> st;
int sn[MAX_V];
vector<int> adj[MAX_V];
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

		sort(curScc.begin(), curScc.end());

		scc.push_back(curScc);
		sccSize++;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
	}

	for (int i = 1; i <= v; i++)
		if (dfsn[i] == 0) 
			dfs(i);

	sort(scc.begin(), scc.end());
	cout << sccSize << endl;

	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++)
			cout << scc[i][j] << ' ';
		cout << -1 << endl;
	}

	return 0;
}
