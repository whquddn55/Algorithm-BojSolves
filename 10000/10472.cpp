#include <bits/stdc++.h>
using namespace std;

#define DEBUG

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

#define BIT(x) (1 << x)

int bfs(int dest) {
	queue<pii> q;
	q.emplace(0, 0);
	vector<bool> visited(1024, false);

	int d[] = { BIT(0) + BIT(1) + BIT(3),
				BIT(0) + BIT(1) + BIT(2) + BIT(4),
				BIT(1) + BIT(2) + BIT(5),
				BIT(0) + BIT(3) + BIT(4) + BIT(6),
				BIT(1) + BIT(3) + BIT(4) + BIT(5) + BIT(7),
				BIT(2) + BIT(4) + BIT(5) + BIT(8),
				BIT(3) + BIT(6) + BIT(7),
				BIT(4) + BIT(6) + BIT(7) + BIT(8),
				BIT(5) + BIT(7) + BIT(8)};

	while (!q.empty()) {
		int here = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (visited[here])
			continue;
		visited[here] = true;

		if (here == dest)
			return cost;
		
		for (int i = 0; i < 9; i++) {
			int next = here ^ d[i];

			if (visited[next])
				continue;
			q.emplace(next, cost + 1);
		}
	}

	return INF;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int dest = 0;
		for (int i = 0; i < 9; i++) {
			char temp;
			scanf(" %c", &temp);
			dest += (temp == '*' ? BIT(i) : 0);
		}
		printf("%d\n", bfs(dest));
	}

	

	return 0;
}