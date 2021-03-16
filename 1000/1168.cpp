#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100005

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

int k_th(int k, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	
	if (nodeLeft == nodeRight)
		return nodeRight;
	if (tree[id * 2] < k)
		return k_th(k - tree[id * 2], id * 2 + 1, mid + 1, nodeRight);
	else
		return k_th(k, id * 2, nodeLeft, mid);
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

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;

	init();

	vector<int> result;
	result.emplace_back(k_th(m));
	update(result.back(), 0);
	n--;
	while (n) {
		int offset = query(0, result.back());
		int nextQuery = offset + m;
		nextQuery %= n;
		if (nextQuery == 0)
			nextQuery = n;
		result.emplace_back(k_th(nextQuery));
		//cout << offset << ' ' << nextQuery << ' ' << result.back() << endl;
		update(result.back(), 0);
		n--;
	}


	//output
	cout << '<';
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] + 1;
		if (i != result.size() - 1)
			cout << ", ";
	}
	cout << '>' << endl;

	return 0;
}