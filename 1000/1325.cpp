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

#define MAX_N 10005
#define MOD 1000000007

int v, e;

int cnt; // cnt : dfsn세기 위해 필요
int dfsn[MAX_N]; // dfsn
bool finished[MAX_N]; // scc가 구성됬는지 체크하는 배열
stack<int> st; // scc구성하기위해 필요
int sn[MAX_N]; // i번째 vertex가 들어간 scc의 번호
vector<int> adj[MAX_N]; // 인접리스트
vector<vector<int>> scc; // scc와 scc의 원소들을 저장
vector<int> sccAdj[MAX_N];


bool ind[MAX_N];
int arr[MAX_N];
bool visited[MAX_N];

int getScc(int here) {
	dfsn[here] = ++cnt;
	st.push(here);

	int result = dfsn[here];
	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];

		if (dfsn[next] == -1)
			result = min(result, getScc(next));
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
			sn[top] = scc.size();

			if (top == here)
				break;
		}

		scc.push_back(curScc);
	}

	return result;
}

int dfs(int here) {
	if (visited[here])
		return 0;

	visited[here] = true;
	int ret = scc[here].size();
	for (auto next : sccAdj[here])
		ret += dfs(next);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int from, to;
		cin >> to >> from;
		from--;
		to--;
		adj[from].push_back(to);
	}

	memset(dfsn, -1, sizeof(dfsn));
	for (int i = 0; i < v; i++)
		if (dfsn[i] == -1)
			getScc(i);

	
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < adj[i].size(); ++j) {
			if (sn[i] != sn[adj[i][j]]) {
				ind[sn[adj[i][j]]] = true;
				sccAdj[sn[i]].emplace_back((sn[adj[i][j]]));
			}
		}
		sort(sccAdj[sn[i]].begin(), sccAdj[sn[i]].end());
		sccAdj[sn[i]].erase(unique(sccAdj[sn[i]].begin(), sccAdj[sn[i]].end()), sccAdj[sn[i]].end());
	}


	int maxValue = -INF;
	for (int i = 0; i < scc.size(); ++i) 
		if (!ind[i]) {
			memset(visited, 0, MAX_N);
			arr[i] = dfs(i);
			maxValue = max(maxValue, arr[i]);
		}

	vector<int> result;
	for (int i = 0; i < scc.size(); ++i) {
		if (arr[i] == maxValue) {
			for (int j = 0; j < scc[i].size(); ++j) {
				result.emplace_back(scc[i][j]);
			}
		}
	}
	sort(result.begin(), result.end());

	for (auto t : result)
		cout << t + 1 << ' ';

	return 0;
}