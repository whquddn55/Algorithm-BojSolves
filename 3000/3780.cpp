#include <bits/stdc++.h>
using namespace std;

vector<int> dist; // i에서 parent까지의 거리
int n, m;

struct Nds{
	vector<int> parent;
	Nds(int n)
		: parent(n) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (parent[u] == u)
			return u;

		int prevParent = parent[u];
		parent[u] = find(parent[u]);
		dist[u] += dist[prevParent];

		return parent[u];
	}

	void merge(int u, int v) {
		dist[u] = abs(u - v) % 1000;
		u = find(u);
		if (u == v)
			return;

		parent[u] = v;
	}

};



int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		int n;
		scanf("%d", &n);
		Nds set(n + 1);
		dist.resize(n + 1);
		fill(dist.begin(), dist.end(), 0);
		while (true) {
			char command;
			scanf("%c", &command);
			if (command == 'E') {
				int a;
				scanf("%d", &a);
				set.find(a);
				
				printf("%d\n",dist[a]);
			}
			else if (command == 'I') {
				int a, b;
				scanf("%d %d", &a, &b);
				set.merge(a, b);
			}
			else if (command == 'O')
				break;
		}
	}

	return 0;
}