#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n;
int treeSize;
vector<int> tree;
vector<int> check;

vector<pair<pii, int>> arr;
void update(int left, int right, int value, int id = 1, int nodeLeft = 0, int nodeRight = treeSize - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (right < nodeLeft || left > nodeRight)
		return;

	if (left <= nodeLeft && right >= nodeRight) 
		check[id] += value;
	else {
		update(left, right, value, id * 2, nodeLeft, mid);
		update(left, right, value, id * 2 + 1, mid + 1, nodeRight);
	}

	if (check[id]) 
		tree[id] = nodeRight - nodeLeft + 1;
	else {
		if (nodeLeft == nodeRight)
			tree[id] = 0;
		else
			tree[id] = tree[id * 2] + tree[id * 2 + 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	arr.resize(n * 2);
	treeSize = 30001;
	tree.resize(treeSize * 4, 0);
	check.resize(treeSize * 4, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i * 2].first.first >> arr[i * 2].first.second;
		cin >> arr[i * 2 + 1].first.first >> arr[i * 2 + 1].first.second;
		arr[i * 2].second = arr[i * 2 + 1].first.second - arr[i * 2].first.second;
		arr[i * 2 + 1].second = -(arr[i * 2 + 1].first.second - arr[i * 2].first.second);
	}

	sort(arr.begin(), arr.end());
	int ans = 0;
	int prevX = 0;
	for (int i = 0; i < arr.size(); i++) {
		ans += tree[1] * (arr[i].first.first - prevX);
		prevX = arr[i].first.first;
		if (arr[i].second > 0)
			update(arr[i].first.second, arr[i].first.second + arr[i].second - 1, 1);
		else
			update(arr[i].first.second + arr[i].second, arr[i].first.second - 1, -1);
	}
	cout << ans << endl;

	return 0;
}
