#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<vector<int> > adj;
vector<int> color;
vector<bool> visited;

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty()) {
        int here = q.front();
        int hereColor = color[here];
        q.pop();

        if (visited[here]) {
            continue;
        }

        visited[here] = true;

        int asize = adj[here].size();
        for (int i = 0; i < asize; i++) {
            int there = adj[here][i];

            if (hereColor == color[there]) {
                return false;
            }
            if (visited[there]) {
                continue;
            }
            q.push(there);
            color[there] = 3 - hereColor;
        }
    }
    return true;
}

int main() {
    int testcase;
    scanf("%d", &testcase);

    while (testcase--) {
        int n, m;
        scanf("%d %d", &n, &m);

        adj.clear();
        adj.resize(n + 1);
        color.clear();
        color.resize(n + 1, 0);
        visited.clear();
        visited.resize(n + 1, false);

        for (int i = 0; i < m; i++) {
            int from, to;
            scanf("%d %d", &from, &to);
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        bool result = true;
        for (int i = 1; i < n + 1; i++){
            if (bfs(i) == false) {
                result = false;
                break;
            }
        }

        printf("%s\n" , result == true ? "YES" : "NO");
    }


    return 0;
}


