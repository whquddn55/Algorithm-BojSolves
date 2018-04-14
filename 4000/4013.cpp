#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 500001

int n, m, s, p;
int sccSum[MAX_SIZE];
bool sccRes[MAX_SIZE];

vector<int> sAdj[MAX_SIZE];
int indegree[MAX_SIZE];
int sMax[MAX_SIZE];
bool sToFind[MAX_SIZE];

vector<int> adj[MAX_SIZE]; // 인접리스트
int cnt, sccsize; // cnt : dfsn세기 위해 필요
int dfsn[MAX_SIZE]; // dfsn
bool finished[MAX_SIZE]; // scc가 구성됬는지 체크하는 배열
stack<int> st; // scc구성하기위해 필요
int sn[MAX_SIZE]; // i번째 vertex가 들어간 scc의 번호

int dfs(int here) { // scc구성하기 위한 dfs
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
		while (true) {
			int top = st.top();
			st.pop();
			finished[top] = true;
			sn[top] = sccsize;

			if (top == here)
				break;
		}
		sccsize++;
	}

	return result;
}

int bfs(int start) {
	queue<int> q;
	for (int i = 0; i < sccsize; i++) 
		if (!indegree[i]) 
			q.emplace(i);
	sToFind[start] = true;
	sMax[start] = sccSum[start];

	int ret = sccRes[start] ? sccSum[start] : 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int there : sAdj[here]) {
			if (sToFind[here]) {
				sMax[there] = max(sMax[there], sMax[here] + sccSum[there]);
				sToFind[there] = true;
				if (sccRes[there])  // 다음 scc가 레스토랑이 있는 scc이면 ret을 업데이트
					ret = max(ret, sMax[there]);
			}
			indegree[there]--;
			if (!indegree[there])
				q.emplace(there);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
	}

	for (int i = 1; i <= n; i++) // dfs를 돌며 scc 구성
		if (dfsn[i] == 0)
			dfs(i);

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		sccSum[sn[i]] += a;
		for (int there : adj[i])
			if (sn[i] != sn[there]) {
				sAdj[sn[i]].push_back(sn[there]);
				indegree[sn[there]]++;
			}
	}

	cin >> s >> p;
	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;
		sccRes[sn[a]] = true;
	}

	cout << bfs(sn[s]) << endl;

	return 0;
}
