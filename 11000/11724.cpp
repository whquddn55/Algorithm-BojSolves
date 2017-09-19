#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<vector<int> > adj;
vector<int> visited;

void dfs(int here) {
    if (visited[here]) {
        return;
    }
    visited[here] = true;

    int asize = adj[here].size();
    for (int i = 0; i < asize; i++) {
        int there = adj[here][i];

        if (visited[there]) {
            continue;
        }

        dfs(there);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    adj.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
                continue;
        }
        dfs(i);
        result++;
    }

    printf("%d\n", result);


    return 0;
}