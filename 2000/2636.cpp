#include <iostream>
#include <queue>
using namespace std;
#define MAXSIZE 100

struct Data{
	int r, c;
	int cost;
	Data(int r, int c, int cost)
		:r(r), c(c) , cost(cost) { }
};

int graph[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE];
int costs[MAXSIZE + 1];

bool bfs(const int row, const int column){
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
			visited[i][j] = false;

	queue<Data> q;
	int dc[] = {-1, 0, 0, 1};
	int dr[] = {0, -1, 1, 0};

	q.push(Data(0, 0, -1));

	int cnt = 0;
	while(!q.empty()){
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		if(visited[r][c])
			continue;

		visited[r][c] = true;
		graph[r][c] = -1;

		cnt++;
		for(int i = 0; i < 4; i++){
			int nc = c + dc[i];
			int nr = r + dr[i];

			if(nr < 0 || nr >= row || nc < 0 || nc >= column)
				continue;

			if(visited[nr][nc])
				continue;

			if(graph[nr][nc] == 1)
				continue;

			q.push(Data(nr, nc, -1));
		}
	}

	if(cnt == (row) * (column))
		return false;

	return true;
}

void get(const int row, const int column){
	int dc[] = {-1, 0, 0, 1};
	int dr[] = {0, -1, 1, 0};

	int cost = 0;
	int result = 0;
	while (bfs(row, column)){
		cost++;
		result = cost;
		for(int i = 0; i < row; i++)
			for(int j = 0; j < column; j++){
				if(graph[i][j] == 1){
					bool flag = false;

					for(int k = 0; k < 4; k++){
						int nr = i + dr[k];
						int nc = j + dc[k];

						if(nc < 0 || nc >= column || nr < 0 || nr >= row)
							continue;

						if(graph[nr][nc] == -1){
							flag = true;
							break;
						}
					}
					if(flag){
						costs[cost]++;
						graph[i][j] = 0;
					}
				}
			}
	}
	cout << result << endl << costs[cost] << endl;
}

int main() {
	int r, c;
	cin >> r >> c;

	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			cin >> graph[i][j];

	get(r, c);

	return 0;
}
