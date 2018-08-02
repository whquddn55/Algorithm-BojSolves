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

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 200000

int n, m;
int tree[MAX_N * 4];

int init(int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	// leafNode일 때
	if (nodeLeft == nodeRight)
		return tree[id] = 1;
	// 아닌 경우
	return tree[id] = init(id * 2, nodeLeft, mid) + init(id * 2 + 1, mid + 1, nodeRight);
}

int update(int index, int value, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	// 범위를 완전히 벗어나면 아무 것도 안 한다.
	if (index < nodeLeft || index > nodeRight)
		return tree[id];
	// index에 해당하는 leafNode에 도착하면 값 변경
	if (nodeLeft == nodeRight)
		return tree[id] = value;
	// 그 외의 경우 분할정복
	return tree[id] = update(index, value, id * 2, nodeLeft, mid) + update(index, value, id * 2 + 1, mid + 1, nodeRight);
}

int query(int left, int right, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;

	// 범위를 완전히 벗어나면 아무 것도 안 한다.
	if (right < nodeLeft || left > nodeRight)
		return 0;
	// 범위에 완전히 포함되는 경우 tree의 값이 부분합의 일부분이 된다.
	if (left <= nodeLeft && right >= nodeRight)
		return tree[id];
	// 그 외의 경우 분할정복
	return query(left, right, id * 2, nodeLeft, mid) + query(left, right, id * 2 + 1, mid + 1, nodeRight);
}

int kth(int index, int k) {
	int left = index, right = MAX_N - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = query(index, mid);
		if (sum >= k)
			right = mid - 1;
		else 
			left = mid + 1;
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	init();
	int cnt = n;
	int id = 0;
	vector<int> ans;
	while (cnt >= m) {
		id = kth(id, m);
		update(id, 0);
		if (id >= n) {
			update(id - n, 0);
			id -= n;
		}
		else
			update(id + n, 0);
		ans.push_back(id + 1);
		cnt--;
	}
	while (cnt) {
		if (m % cnt == 0)
			id = kth(id, cnt);
		else
			id = kth(id, m % cnt);
		update(id, 0);
		if (id >= n) {
			update(id - n, 0);
			id -= n;
		}
		else
			update(id + n, 0);
		ans.push_back(id + 1);
		cnt--;
	}

	cout << '<';
	for (int i = 0; i < n; i++)
		cout << ans[i] << (i != n - 1 ? ", " : "");
	cout << ">";
	cout << endl;

	return 0;
}