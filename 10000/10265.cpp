#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 1001

int n, k;

int sIndegree[MAX_SIZE];
int sSum[MAX_SIZE];
vector<int> sAdj[MAX_SIZE];

int sum[MAX_SIZE];
int inIndex[MAX_SIZE];
int cntOfZero;
int dp[MAX_SIZE][MAX_SIZE];

int cnt, sccSize; // cnt : dfsn세기 위해 필요, sccSize : scc개수
int dfsn[MAX_SIZE]; // dfsn
bool finished[MAX_SIZE]; // scc가 구성됬는지 체크하는 배열
stack<int> st; // scc구성하기위해 필요
int sn[MAX_SIZE]; // i번째 vertex가 들어간 scc의 번호
vector<int> adj[MAX_SIZE]; // 인접리스트

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

		while (true) {
			int top = st.top();
			st.pop();
			finished[top] = true;
			sn[top] = sccSize;

			if (top == here)
				break;
		}
		sccSize++;
	}

	return result;
}

int dfs2(int here) {
	int ret = sum[here];
	for (int there : sAdj[here]) {
		sum[here] += sum[there];
		dfs2(there);
	}
	return ret;
}

int getDp(int idx1, int idx2) {
	if (idx1 >= cntOfZero)
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = getDp(idx1 + 1, idx2);
	if (idx2 >= sSum[inIndex[idx1]]) 
		for (int i = sSum[inIndex[idx1]]; i <= sum[inIndex[idx1]] && i <= idx2; i++)
			ret = max(ret, getDp(idx1 + 1, idx2 - i) + i);
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a == i)
			continue;
		adj[a].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		if (dfsn[i] == 0)
			dfs(i);

	for (int i = 1; i <= n; i++) {
		sSum[sn[i]]++;
		sum[sn[i]]++;
		for (int j = 0; j < adj[i].size(); j++) {
			if (sn[i] != sn[adj[i][j]]) {
				sAdj[sn[i]].push_back(sn[adj[i][j]]);
				sIndegree[sn[adj[i][j]]]++;
			}
		}
	}
	for (int i = 0; i < sccSize; i++) {
		dfs2(i);
		if (!sIndegree[i])
			inIndex[cntOfZero++] = i;
	}
	memset(dp, -1, sizeof(dp));
	cout << getDp(0, k) << endl;

	return 0;
}
