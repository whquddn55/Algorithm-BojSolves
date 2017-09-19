#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<int> adj;
vector<bool> visited;

void dfs(int start) {
    if (visited[start]) {
        return;
    }
    visited[start] = true;

    dfs(adj[start]);
}

int main() {
    int testcase;
    scanf("%d", &testcase);

    while (testcase--) {
        int n;
        scanf("%d", &n);

        adj.clear();
        adj.resize(n + 1);
        visited.clear();
        visited.resize(n + 1, false);

        for (int i = 1; i < n + 1; i++) {
            scanf("%d", &adj[i]);
        }

        int result = 0;
        for (int i = 1; i < n + 1; i++){
            if (visited[i]) {
                continue;
            }
            dfs(i);
            result++;
        }

        printf("%d\n", result);
    }


    return 0;
}


