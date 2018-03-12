#include <bits/stdc++.h>
using std::pair;
using std::vector;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::deque;
using std::greater;
using std::max;
using std::min;
using std::sort;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::make_pair;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

struct Score {
	int a, b, c;

	bool operator<(const Score& score) {
		return a > score.a;
	}
};

int n;
vector<Score> ranks;
vector<int> memo;

struct SegmentTree {
	vector<int> tree;

	SegmentTree(int n)
		: tree(n * 4) { 
		init();
	}

	int init(int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
		if (nodeLeft == nodeRight)
			return tree[id] = ranks[memo[nodeLeft]].c;

		int mid = (nodeLeft + nodeRight) / 2;
		return tree[id] = min(init(id * 2, nodeLeft, mid), 
			init(id * 2 + 1, mid + 1, nodeRight));
	}

	int update(int index, int newValue, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
		if (index < nodeLeft || index > nodeRight)
			return tree[id];
		if (nodeLeft == nodeRight)
			return tree[id] = newValue;

		int mid = (nodeLeft + nodeRight) / 2;
		return tree[id] = min(update(index, newValue, id * 2, nodeLeft, mid),
			update(index, newValue, id * 2 + 1, mid + 1, nodeRight));
	}

	int query(int left, int right, int id = 1, int nodeLeft = 0, int nodeRight = n - 1) {
		if (right < nodeLeft || left > nodeRight)
			return INF;
		if (left <= nodeLeft && right >= nodeRight)
			return tree[id];

		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right,id * 2, nodeLeft, mid), 
			query(left, right, id * 2 + 1, mid + 1, nodeRight));
	}
};

int main() {
	scanf("%d", &n);
	ranks.resize(n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		ranks[t - 1].a = i;
	}
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		ranks[t - 1].b = i;
	}
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		ranks[t - 1].c = i;
	}

	sort(ranks.begin(), ranks.end());

	memo.resize(n);
	for (int i = 0; i < n; i++)
		memo[ranks[i].b] = i;

	int result = n;
	SegmentTree sTree(n);
	for (int i = 0; i < n; i++) {
		if (sTree.query(0, ranks[i].b) < ranks[i].c)
			result--;
		sTree.update(ranks[i].b, INF);
	}

	printf("%d\n", result);

	return 0;
}