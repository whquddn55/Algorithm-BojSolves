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

#define MAX_N 100000

int n, k;
int arr[MAX_N];
int minTree[MAX_N * 4];
int maxTree[MAX_N * 4];

pii init(int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	// leafNode일 때
	if (nodeLeft == nodeRight)
		return { minTree[id] = arr[nodeLeft], maxTree[id] = arr[nodeLeft] };
	// 아닌 경우
	pii leftValue = init(id * 2, nodeLeft, mid);
	pii rightValue = init(id * 2 + 1, mid + 1, nodeRight);
	return { minTree[id] = min(leftValue.first, rightValue.first), maxTree[id] = max(leftValue.second, rightValue.second) };
}

pii update(int index, int value, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	// 범위를 완전히 벗어나면 아무 것도 안 한다.
	if (index < nodeLeft || index > nodeRight)
		return { minTree[id], maxTree[id] };
	// index에 해당하는 leafNode에 도착하면 값 변경
	if (nodeLeft == nodeRight)
		return { minTree[id] = value, maxTree[id] = value };
	// 그 외의 경우 분할정복
	pii leftValue = update(index, value, id * 2, nodeLeft, mid);
	pii rightValue = update(index, value, id * 2 + 1, mid + 1, nodeRight);
	return { minTree[id] = min(leftValue.first, rightValue.first), maxTree[id] = max(leftValue.second, rightValue.second) };
}

pii query(int left, int right, int id = 1, int nodeLeft = 0, int nodeRight = MAX_N - 1) {
	int mid = (nodeLeft + nodeRight) / 2;
	// 범위를 완전히 벗어나면 아무 것도 안 한다.
	if (right < nodeLeft || left > nodeRight)
		return { INF, -INF };
	// 범위에 완전히 포함되는 경우 tree의 값이 부분합의 일부분이 된다.
	if (left <= nodeLeft && right >= nodeRight)
		return { minTree[id], maxTree[id] };
	// 그 외의 경우 분할정복
	pii leftValue = query(left, right, id * 2, nodeLeft, mid);
	pii rightValue = query(left, right, id * 2 + 1, mid + 1, nodeRight);
	return { min(leftValue.first, rightValue.first), max(leftValue.second, rightValue.second) };
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			arr[i] = i;
		init();
		while (k--) {
			int q, a, b;
			cin >> q >> a >> b;
			if (!q) {
				update(a, arr[b]);
				update(b, arr[a]);
				swap(arr[a], arr[b]);
			}
			else {
				pii qValue = query(a, b);
				if (qValue.first == a && qValue.second == b)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
	}

	return 0;
}