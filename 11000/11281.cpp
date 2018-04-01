#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_V 20001

int n, m;

int cnt, sccSize; // cnt : dfsn세기 위해 필요, sccSize : scc개수
int dfsn[MAX_V]; // dfsn
bool finished[MAX_V]; // scc가 구성됬는지 체크하는 배열
stack<int> st; // scc구성하기위해 필요
int sn[MAX_V]; // i번째 vertex가 들어간 scc의 번호
vector<int> adj[MAX_V]; // 인접리스트
vector<vector<int>> scc; // scc와 scc의 원소들을 저장

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

int notOp(int value) {
	if (value > n)
		return value - n;
	else
		return value + n;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a < 0)
			a = -a + n;
		if (b < 0)
			b = -b + n;
		adj[notOp(a)].push_back(b);
		adj[notOp(b)].push_back(a);
	}

	for (int i = 1; i <= n * 2; i++)
		if (dfsn[i] == 0)
			dfs(i);

	bool possible = true;
	for (int i = 1; i <= n; i++)
		if (sn[i] == sn[i + n])
			possible = false;
	
	cout << possible << endl;

	if (possible) {
		int result[MAX_V];
		fill(result, result + MAX_V, -1);
		pii p[MAX_V];
		for (int i = 1; i <= n * 2; i++)
			p[i] = pii(sn[i], i);
		sort(p, p + n * 2 + 1);

		for (int i = n * 2; i >= 1; i--) {
			int var = p[i].second;
			if (result[var] == -1) {
				result[var] = 0;
				result[notOp(var)] = 1;
			}
		}
		for (int i = 1; i <= n; i++)
			cout << result[i] << ' ';
		cout << endl;
	}

	return 0;
}
