#include <iostream>
#include <queue>
#define INF 987654321
#define MAXSIZE 200
using namespace std;

vector<int> adj[MAXSIZE];
bool visited[MAXSIZE];

void bfs(const int n, int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int here = q.front();
        q.pop();

        if (visited[here])
            continue;

        visited[here] = true;

        int asize = adj[here].size();
        for(int i = 0; i < asize; i++){
            int there = adj[here][i];

            if(visited[there])
                continue;

            q.push(there);
        }
    }
}

int main() {
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		n += 2;

		for(int i = 0 ; i < n; i++){
            visited[i] = false;
            adj[i].clear();
		}

		vector<pair<int, int> > vertexs;
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;

			int vsize = vertexs.size();
			for(int j = 0; j < vsize; j++){
                int dx = (vertexs[j].first - x) > 0 ? (vertexs[j].first - x) : -(vertexs[j].first - x);
                int dy = (vertexs[j].second - y) > 0 ? (vertexs[j].second - y) : -(vertexs[j].second - y);
				if(dx + dy <= 1000){
					adj[j].push_back(i);
					adj[i].push_back(j);
                }
			}

			vertexs.push_back(make_pair(x, y));
		}

		bfs(n, 0);

		if(visited[n - 1])
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}

	return 0;
}

