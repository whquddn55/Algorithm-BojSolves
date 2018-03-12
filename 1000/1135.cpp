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

int n;
vector<vector<int> > edges;

int getDepth(int here) {
	vector<int> arr;
	for (int i = 0; i < edges[here].size(); i++)
		arr.push_back(getDepth(edges[here][i]));
	sort(arr.begin(), arr.end(), greater<int>());
	
	int maxValue = 0;
	for (int i = 0; i < arr.size(); i++)
		maxValue = max(maxValue, arr[i] + (i + 1));
	return maxValue;
}

int main() {
	scanf("%d", &n);
	edges.resize(n);
	for (int i = 0; i < n; i++) {
		int to;
		scanf("%d", &to);
		if (to == -1)
			continue;
		
		edges[to].push_back(i);
	}

	printf("%d\n", getDepth(0));
}