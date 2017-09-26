#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
#define MAXSIZE 100000
using namespace std;

vector<bool> visited;

int bfs(int n, int k) {
    queue<pair<int, int> >q;
    q.push(make_pair(n, 0));

    while (!q.empty()) {
        int here = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (visited[here]) {
            continue;
        }

        visited[here] = true;

        if (here == k) {
            return cost;
        }

        int next[] = { here - 1, here + 1, here * 2};
        for (int i = 0; i < 3; i++) {
            if (next[i] > MAXSIZE || next[i] < 0) {
                continue;
            }
            if (visited[next[i]]) {
                continue;
            }

            q.push(make_pair(next[i], cost + 1));
        }

    }

    return -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    visited.resize(MAXSIZE + 1, false);
    printf("%d\n", bfs(n, k));

    return 0;
}
