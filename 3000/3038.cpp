#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_N 40000

int n;
int value;
vector<int> tree[16];

void makeTree(int level) {
	if (level == n + 1)
		return;

	int size = pow(2, level);
	tree[level].resize(size);
	tree[level][0] = value;

	int d = size / 2;
	int copySize = 1;
	int s = 1, e = 1;
	while (e < size) {
		for (int i = s; i <= e; i++)
			tree[level][i] = tree[level][i - copySize] - d;
		d /= 2;
		copySize *= 2;
		s = e + 1;
		e += copySize;
	}

	value -= size;

	makeTree(level + 1);
}

void dfs(int level, int idx) {
	if (level == n)
		return;
	cout << tree[level][idx] << ' ';
	dfs(level + 1, idx * 2);
	dfs(level + 1, idx * 2 + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	value = pow(2, n) - 1;
	makeTree(0);
	reverse(tree[n - 1].begin(), tree[n - 1].end());
	/*for (int i = 0; i < n; i++, cout << endl)
		for (auto e : tree[i])
			cout << e << ' ';*/
	dfs(0, 0);
	
	return 0;
}