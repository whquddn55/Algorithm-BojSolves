#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

struct Edge {
	int to, capacity, reverse;
	Edge(int to, int capacity, int reverse)
		:to(to), capacity(capacity), reverse(reverse) {}
};

vector<vector<Edge>> graph;
vector<int> level;
vector<int> iter;

vector<int> arr;
bool isPrime[100001];
int n, m;
int v;

void bfs(int s) {
	fill(level.begin(), level.end(), -1);
	queue<int> q;
	q.push(s);
	level[s] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (Edge& e : graph[v]) {
			if (e.capacity > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				q.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f) {
	if (v == t)
		return f;
	for (int& i = iter[v]; i < graph[v].size(); i++) {
		Edge& e = graph[v][i];
		if (e.capacity > 0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f, e.capacity));
			if (d > 0) {
				e.capacity -= d;
				graph[e.to][e.reverse].capacity += d;
				return d;
			}
		}
	}

	return 0;
}

int maxFlow(int s, int t) {
	int flow = 0;
	while (true) {
		bfs(s);
		if (level[t] < 0)
			return flow;
		fill(iter.begin(), iter.end(), 0);
		int f;
		while ((f = dfs(s, t, INF)) > 0)
			flow += f;
	}
	return flow;
}

void checkPrimes() {
	for (int i = 2; i <= 100000; i++)
		isPrime[i] = true;

	for (int i = 2; i <= 100000; i++)
		if (isPrime[i])
			for (int j = i * 2; j <= 100000; j += i)
				isPrime[j] = false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	checkPrimes(); // 소수 체크
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin() + 1, arr.end()); // 오름차순 출력을 위해 정렬

	vector<int> odds, evens; // 홀수, 짝수 미리 처리
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2)
			odds.push_back(arr[i]);
		else
			evens.push_back(arr[i]);
	}

	if (odds.size() != evens.size()) {
		cout << -1 << '\n';
		return 0;
	}

	bool check = false;
	v = n + 2;
	graph.resize(v);
	level.resize(v);
	iter.resize(v);
	int source = 0;
	int sink = v - 1;
	int oddStart = 1; // 홀수들의 index의 시작지점
	int evenStart = n / 2 + 1; // 짝수들의 index의 시작지점
	for (int i = 1; i < n; i++) {
		if (isPrime[arr[0] + arr[i]]) { // arr[0] + arr[i]가 소수이면 arr[0]과 arr[i]로 가거나 나오는 Edge들의 capacity를 0으로 설정
			// init
			for (int i = 0; i < graph.size(); i++)
				graph[i].clear();
			//

			for (int j = 0; j < odds.size(); j++) { // source to odd
				graph[0].emplace_back(oddStart + j, !(odds[j] == arr[0] || odds[j] == arr[i]), graph[oddStart + j].size());
				graph[oddStart + j].emplace_back(0, 0, graph[0].size() - 1);
			}

			for (int j = 0; j < odds.size(); j++) { // odd to even
				for (int k = 0; k < evens.size(); k++) {
					if (isPrime[odds[j] + evens[k]]) { // odd to even를 가르키는 Edge는 prime일 때에만
						graph[oddStart + j].emplace_back(evenStart + k, !(odds[j] == arr[0] || odds[j] == arr[i] || evens[k] == arr[0] || evens[k] == arr[i]), graph[evenStart + k].size());
						graph[evenStart + k].emplace_back(oddStart + j, 0, graph[oddStart + j].size() - 1);
					}
				}
			}

			for (int j = 0; j < evens.size(); j++) { // even to sink
				graph[evenStart + j].emplace_back(sink, !(evens[j] == arr[0] || evens[j] == arr[i]), graph[sink].size());
				graph[sink].emplace_back(evenStart + j, 0, graph[evenStart + j].size() - 1);
			}

			if (maxFlow(0, sink) == n / 2 - 1) {
				cout << arr[i] << ' ';
				check = true;
			}
  		}
	}

	if (!check) // 경우가 없다면 -1 출력
		cout << "-1" << '\n';

	return 0;
}
