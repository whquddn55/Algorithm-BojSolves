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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 100005
#define MOD 1000003

vector<int> tree[MAX_N * 4];

void init(int nl = 2, int nr = MAX_N - 1, int id = 1) {
	if (nl == nr) {
		int t = nl;
		int v = nl;
		for (int j = 2; j <= sqrt(nl); ++j)
			while(t % j == 0) {
				t /= j;
				v = j;
			}
		tree[id].push_back(max(v, t));
		return;
	}
	int mid = (nl + nr) / 2;
	init(nl, mid, id * 2);
	init(mid + 1, nr, id * 2 + 1);
	tree[id].resize(tree[id*2].size() + tree[id*2+1].size());
	merge(tree[id*2].begin(), tree[id*2].end(), tree[id*2+1].begin(), tree[id*2+1].end(), tree[id].begin());
}

int query(int n, int k, int nl = 2, int nr = MAX_N - 1, int id = 1) {
	if (n < nl || nr < 2)
		return 0;
	if (2 <= nl && nr <= n) 
		return upper_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin();
	int mid = (nl + nr) / 2;
	return query(n, k, nl, mid, id * 2) + query(n, k, mid + 1, nr, id * 2 + 1);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	init();

	int q;
	cin >> q;
	while(q--) {
		int n, k;
		cin >> n >> k;

		cout << query(n, k) << endl;
	}
	
	return 0;
}
