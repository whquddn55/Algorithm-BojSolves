#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXSIZE 101

vector<int> adj[MAXSIZE];

void dfs(const int n, int here, vector<int>& visited){
	int asize = adj[here].size();

	for(int i = 0; i < asize; i++){
		int next = adj[here][i];

		if(next == n)
			continue;

		int vsize = visited.size();

		for(int i = 0; i < vsize; i++)
			if(visited[i] == next){
				cout << "CYCLE" << endl;
				exit(0);
			}

		visited.push_back(next);
		dfs(n, next, visited);
		visited.pop_back();
	}
}

int main() {
	int n;
	cin >> n;

	for(int i = 1; i < n; i++){
		int t;
		cin >> t;

		while(t--){
			int adjacent;
			cin >> adjacent;

			adj[i].push_back(adjacent);
		}
	}

	vector<int> visited;
	visited.push_back(1);
	dfs(n, 1, visited);
	cout << "NO CYCLE" << endl;

	return 0;
}
