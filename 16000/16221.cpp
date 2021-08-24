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
#define MAX_N 1000005
#define MOD 1000003


int q;
int minT[MAX_N * 4];
int sumT[MAX_N * 4];
int maxValue = 1;

void update(int idx, int value, int nl = 1, int nr = MAX_N, int id = 1) {
	if (idx < nl || nr < idx)
		return;
	if (nl == nr) {
		minT[id] += value;
		sumT[id] += value;
		return;
	}
	int mid = (nl + nr) / 2;
	update(idx, value, nl, mid, id * 2);
	update(idx, value, mid + 1, nr, id * 2 + 1);
	minT[id] = min(minT[id * 2], minT[id * 2 + 1]);
	sumT[id] = sumT[id * 2] + sumT[id * 2 + 1];
}

int query(int nl = 1, int nr = MAX_N, int id = 1) {
	if (nl == nr)
		return sumT[id];
	if (minT[id] != 0)
		return sumT[id];
	int mid = (nl + nr) / 2;
	if (minT[id * 2] != 0) 
		return sumT[id * 2] + query(mid + 1, nr, id * 2 + 1);
	else
		return query(nl, mid, id * 2);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> q;
	while(q--) {
		int t, k;
		cin >> t >> k;
		maxValue = max(maxValue, k);
		if (t == 1) {
			update(k, 1);
			cout << query() << endl;
		}
		else {
			update(k, -1);
			cout << query() << endl;
		}
	}
	
	return 0;
}
