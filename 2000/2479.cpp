#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int from, to;
vector<string> arr;
vector<vector<int> > adj;
vector<int> previous;
vector<bool> visited;

bool haming(string& a, string& b) {
	bool result = true;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (a[i] != b[i])
			cnt++;
		if (cnt == 2) {
			result = false;
			break;
		}
	}
	if (cnt == 0)
		result = false;

	return result;
}

bool bfs() {
	queue<int> q;
	q.push(from);
	visited[from] = true;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		if (here == to)
			return true;

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			if (visited[next])
				continue;

			q.push(next);
			previous[next] = here;
			visited[next] = true;
		}
	}

	return false;
}

void print(int here) {
	if (here == from) {
		printf("%d ", here + 1);
		return;
	}

	print(previous[here]);
	printf("%d ", here + 1);
}

int main() {
	scanf("%d %d", &n, &k);
	arr.resize(n);
	adj.resize(n);
	previous.resize(n);
	for (int i = 0; i < n; i++)
		previous[i] = i;
	visited.resize(n, false);

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	scanf("%d %d", &from, &to);
	from--; to--;

	for (int i = 0; i < n; i++) 
		for (int j = i + 1; j < n; j++) 
			if (haming(arr[i], arr[j])) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		
	if (bfs()) {
		print(to);
		printf("\n");
	}
	else 
		printf("-1\n");
	


	return 0;
}