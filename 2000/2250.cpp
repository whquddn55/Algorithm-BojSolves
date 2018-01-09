#include <bits/stdc++.h>
using namespace std;

struct Node {
	int parent = 0, lc, rc;
	int leftSubTreeSize;
};

vector<Node> nodes;
vector<int> levels;
vector<int> placed;
int n;

int dfs(int here,int level) {
	levels[here] = level;

	if (nodes[here].lc == -1 && nodes[here].rc == -1)
		return 0;

	int leftSubTreeSize = 0, rightSubTreeSize = 0;
	if (nodes[here].lc != -1)
		leftSubTreeSize = dfs(nodes[here].lc, level + 1) + 1;
	if (nodes[here].rc != -1)
		rightSubTreeSize = dfs(nodes[here].rc, level + 1) + 1;
	nodes[here].leftSubTreeSize = leftSubTreeSize;

	return leftSubTreeSize + rightSubTreeSize;
}

void dfs1(int here, int toPlace) {
	placed[here] = nodes[here].leftSubTreeSize + toPlace;

	if (nodes[here].lc != -1)
		dfs1(nodes[here].lc, toPlace);
	if (nodes[here].rc != -1)
		dfs1(nodes[here].rc, placed[here] + 1);
}

int main() {
	cin >> n;

	nodes.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cin >> nodes[t].lc >> nodes[t].rc;

		if (nodes[t].lc != -1)
			nodes[nodes[t].lc].parent = t;
		if (nodes[t].rc != -1)
			nodes[nodes[t].rc].parent = t;
	}

	int root;
	for (int i = 1; i <= n; i++)
		if (nodes[i].parent == 0) {
			root = i;
			break;
		}
	
	levels.resize(n + 1);
	dfs(root, 1);

	placed.resize(n + 1);
	dfs1(root, 1);

	vector<int> minValue(n + 1, INT_MAX);
	vector<int> maxValue(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		minValue[levels[i]] = min(minValue[levels[i]], placed[i]);
		maxValue[levels[i]] = max(maxValue[levels[i]], placed[i]);
	}

	int maxLevel = 1;
	int result = maxValue[1] - minValue[1];
	for (int i = 2; i <= n; i++) {
		if ((maxValue[i] - minValue[i]) > result) {
			maxLevel = i;
			result = maxValue[i] - minValue[i];
		}
	}

	cout << maxLevel << ' ' << result + 1<< endl;

	return 0;
}