#include <bits/stdc++.h>
using namespace std;
bool myfunc(pair<int, int> a, pair<int, int>b) {
	if (a.first<b.first)
		return true;
	else if (a.first>b.first)
		return false;
	else {
		return a.second>b.second;
	}
}
struct RSQ {
	int n;
	vector<int> rangeSum;
	RSQ(const vector<int>& arr) {
		n = arr.size();
		rangeSum.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}
	int init(const vector<int>& arr, int left, int right, int node) {
		if (left == right)
			return arr[left];
		int mid = (left + right) / 2;
		int leftSum = init(arr, left, mid, node * 2);
		int rightSum = init(arr, mid + 1, right, node * 2 + 1);
		return rangeSum[node] = leftSum + rightSum;
	}
	int query(int left, int right, int nodeLeft, int nodeRight, int node) {
		if (nodeRight < left || right < nodeLeft) {
			return 0;
		}
		if (left <= nodeLeft && nodeRight <= right)
			return rangeSum[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, nodeLeft, mid, node * 2) + query(left, right, mid + 1, nodeRight, node * 2 + 1);
	}
	int update(int idx, int left, int right, int node) {
		if (idx < left || right < idx)
			return rangeSum[node];
		if (left == right)
			return rangeSum[node] = 1;
		int mid = (left + right) / 2;
		return rangeSum[node] = update(idx, left, mid, node * 2) + update(idx, mid + 1, right, node * 2 + 1);
	}
};
int main(void)
{
	int T, N;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N;
		long long cnt = 0;
		vector<pair<int, int>> yx, xy;
		vector<int> val(N, 0);
		for (int i = 0; i < N; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			yx.push_back(make_pair(b, a));
			xy.push_back(make_pair(a, b));
		}
		sort(yx.begin(), yx.end(), myfunc);
		sort(xy.begin(), xy.end(), myfunc);

		RSQ tree(val);
		for (int i = 0; i < N; ++i) {
			auto it = lower_bound(xy.begin(), xy.end(), make_pair(yx[i].second, yx[i].first), myfunc);
			int idx = it - xy.begin();
			cnt += tree.query(idx,N-1,0,N-1,1);
			tree.update(idx, 0, N - 1, 1);
		}
		printf("%lld\n", cnt);
	}
	return 0;
}