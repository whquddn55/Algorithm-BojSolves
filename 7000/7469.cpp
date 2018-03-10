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

int n, m;
int arr[100005];
vector<int> tree[400005];
void build(int id = 1, int nodeLeft = 0, int nodeRight = n - 1)
{
	if (nodeLeft == nodeRight) {
		tree[id] = vector<int>(1);
		tree[id][0] = arr[nodeLeft];
		return;
	}
	int mid = (nodeLeft + nodeRight) / 2;
	build(id * 2, nodeLeft, mid);
	build(id * 2 + 1, mid + 1, nodeRight);

	tree[id].resize(nodeRight - nodeLeft + 1, 0);
	merge(tree[id * 2].begin(), tree[id * 2].end(), tree[id * 2 + 1].begin(), tree[id * 2 + 1].end(), tree[id].begin());
}

int query(int left, int right, int k, int id = 1, int nodeLeft = 0, int nodeRight = n - 1)
{
	if (nodeRight<left || right<nodeLeft)
		return 0;
	if (left <= nodeLeft && nodeRight <= right)
		return upper_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin();

	int mid = (nodeLeft + nodeRight) / 2;
	return query(left, right, k, id * 2, nodeLeft, mid) + query(left, right, k, id * 2 + 1, mid + 1, nodeRight);
}

int binarySearch(int minValue, int maxValue) 
{
	int left = minValue, right = maxValue;
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (left <= right) {
		int mid = (left + right) / 2;
		if (query(a - 1, b - 1, mid) >= c)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

int main()
{
	scanf("%d%d", &n, &m);
	
	int minValue = INT_MAX;
	int maxValue = INT_MIN;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		minValue = min(minValue, arr[i]);
		maxValue = max(maxValue, arr[i]);
	}
	
	build();

	while (m--) 
		printf("%d\n" , binarySearch(minValue, maxValue));
}