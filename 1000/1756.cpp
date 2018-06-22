#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 300005

int d, n;
int arr[MAX_N];
vector<int> tree[MAX_N * 4];

ll ans = 0;

void init(int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	if (nodeLeft == nodeRight) {
		tree[id] = vector<int>(1);
		tree[id][0] = arr[nodeLeft];
		return;
	}
	int mid = (nodeLeft + nodeRight) / 2;
	init(id * 2, nodeLeft, mid);
	init(id * 2 + 1, mid + 1, nodeRight);

	tree[id].resize(nodeRight - nodeLeft + 1, 0);
	merge(tree[id * 2].begin(), tree[id * 2].end(), tree[id * 2 + 1].begin(), tree[id * 2 + 1].end(), tree[id].begin(), greater<int>());
}

// left, right 범위에서 k보다 작은 수 중 가장 왼쪽에 있는 수의 index
int query(int left, int right, int k, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	if (nodeRight < left || nodeLeft > right) 
		return -1;
	if (nodeLeft == nodeRight)
		return arr[nodeLeft] < k ? nodeLeft : -1;
	
	int value = -1;
	if (upper_bound(tree[id * 2].begin(), tree[id * 2].end(), k, greater<int>()) != tree[id * 2].end())
		value = query(left, right, k, id * 2, nodeLeft, mid);
	if (value == -1)
		return query(left, right, k, id * 2 + 1, mid + 1, nodeRight);
	else
		return value;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> d >> n;
	for (int i = 0; i < d; i++) 
		cin >> arr[i];
	init();

	int lastIndex = d;
	for (int i = 0; i < n; i++) {
		int size;
		cin >> size;
		int index = query(0, lastIndex - 1, size);
		if (index == -1)
			lastIndex--;
		else
			lastIndex = index - 1;
		if (lastIndex == -1)
			break;
	}

	cout << lastIndex + 1 << endl;
	return 0;
}