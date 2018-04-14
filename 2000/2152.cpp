#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 10001

int n, m, s, t;

int sSum[MAX_SIZE];
int sIndegree[MAX_SIZE];
bool sToFind[MAX_SIZE];
int sMax[MAX_SIZE];
vector<int> sAdj[MAX_SIZE];

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

int bfs(int from, int to) {
	queue<int> q;
	if (from == to)
		return sSum[from];
	for (int i = 0; i < sccsize; i++) 
		if (!sIndegree[i]) 
			q.emplace(i);
		
	sToFind[from] = true;
	sMax[from] = sSum[from];
	while (!q.empty()) {
		int here = q.front();
		q.pop();


		for (int i = 0; i < sAdj[here].size(); i++) {
			int there = sAdj[here][i];

			if (sToFind[here]) {
				sToFind[there] = true;
				sMax[there] = max(sMax[there], sMax[here] + sSum[there]);
			}
			sIndegree[there]--;
			if (!sIndegree[there])
				q.emplace(there);
		}
	}
	return sToFind[to] ? sMax[to] : 0;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
	}

	for (int i = 1; i <= n; i++) // dfs를 돌며 scc 구성
		if (dfsn[i] == 0)
			dfs(i);

	for (int i = 1; i <= n; i++) {
		sSum[sn[i]]++;
		for (int j = 0; j < adj[i].size(); j++) 
			if (sn[i] != sn[adj[i][j]]) {
				sAdj[sn[i]].push_back(sn[adj[i][j]]);
				sIndegree[sn[adj[i][j]]]++;
			}
	}

	cout << bfs(sn[s], sn[t]) << endl;


	return 0;
}
