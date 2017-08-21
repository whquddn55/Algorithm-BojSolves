#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAXSIZE 100

bool adj[MAXSIZE][MAXSIZE];
bool result[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE];

struct Data{
	int y, x;
	Data(int y, int x)
		: y(y), x(x) {}
};

void bfs(const int n, const int from){
	queue<int> q;
	q.push(from);

	vector<int> visit;

	bool flag = false;
	while(!q.empty()){
		int here = q.front();
		q.pop();

		if(visited[here])
			continue;
		visited[here] = true;
		visited[from] = false;

		if(here != from || flag)
			result[from][here] = true;
		flag = true;

		/*
		int vsize = visit.size();
		for(int i = 0; i < vsize; i++)
			result[visit[i]][here] = true;

		visit.push_back(here);*/

		for(int i = 0; i < n; i++){
			if (!adj[here][i])
				continue;
			if (visited[i])
				continue;

			q.push(i);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			visited[j] = false;
		bfs(n, i);
	}


	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << result[i][j] << ' ';
		cout << endl;
	}

	return 0;
}
