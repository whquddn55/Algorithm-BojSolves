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

struct DATA {
	int lmax = -INF, rmax = -INF, mmax = -INF;
};

int n;
int arr[MAX_N];
int psum[MAX_N];
DATA tree[MAX_N * 4];

void init(int nl = 1, int nr = MAX_N, int id = 1) {
	if (nl == nr) {
		tree[id].lmax = tree[id].rmax = tree[id].mmax = arr[nl];
		return;
	}
	int mid = (nl + nr) / 2;
	init(nl, mid, id * 2);
	init(mid + 1, nr, id * 2 + 1);

	int sum = 0;
	for (int i = nl; i <= nr; ++i) {
		sum += arr[i];
		tree[id].lmax = max(tree[id].lmax, sum);
	}

	sum = 0;
	for (int i = nr; i >= nl; --i) {
		sum += arr[i];
		tree[id].rmax = max(tree[id].rmax, sum);
	}

	tree[id].mmax = max({tree[id * 2].mmax, tree[id * 2 + 1].mmax, tree[id * 2].rmax + tree[id * 2 + 1].lmax});
}

DATA query(int l, int r, int nl = 1, int nr = MAX_N, int id = 1) {
	if (r < nl || nr < l)
		return DATA();
	if (l <= nl && nr <= r)
		return tree[id];
	int mid = (nl + nr) / 2;
	DATA lQuery = query(l, r, nl, mid, id * 2);
	DATA rQuery = query(l, r, mid + 1, nr, id * 2 + 1);
	DATA ret;
	ret.lmax = max(lQuery.lmax, rQuery.lmax + psum[mid] - psum[nl - 1]);
	ret.rmax = max(rQuery.rmax, lQuery.rmax + psum[nr] - psum[mid]);
	ret.mmax = max({lQuery.mmax, rQuery.mmax, lQuery.rmax + rQuery.lmax});
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	
	init();
	int q;
	cin >> q;
	while(q--) {
		int s, e;
		cin >> s >> e;
		DATA res = query(s, e);
		cout << res.mmax << endl;
	}
	
	return 0;
}
