#include <iostream>
#include <vector>
using namespace std;
#define MAXSIZE 100

vector<int> adj[MAXSIZE];
bool visited[MAXSIZE];
int cnt = -1;

void dfs(int here){
	if(visited[here])
		return;
	visited[here] = true;
	cnt++;

	int asize = adj[here].size();
	for(int i = 0; i < asize; i++){
		int next = adj[here][i];
		if(visited[next])
			continue;

		dfs(next);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int from, to;
		cin >> from >> to;

		from--; to--;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	dfs(0);

	cout << cnt << endl;



	return 0;
}
