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

int n;
vector<pair<pii, int>> q1;
vector<pair<pii, pii>> q2; 
map<int, int> mapper;
int rMapper[MAX_N];

ll tree[MAX_N * 4];
ll lazy[MAX_N * 4];

void updateLazy(int nl, int nr, int id) {
	if (lazy[id]) {
		tree[id] += (rMapper[nr + 1] - rMapper[nl]) * lazy[id];
		if (nl != nr) {
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
		}
		lazy[id] = 0;
	}
}

void update(int l, int r, int value, int nl = 0, int nr = MAX_N, int id = 1) {
	updateLazy(nl, nr, id);
	if (r < nl || nr < l)
		return;
	if (l <= nl && nr <= r) {
		lazy[id] += value;
		updateLazy(nl, nr, id);
		return;
	}

	int mid = (nl + nr) / 2;
	update(l, r, value, nl, mid, id * 2);
	update(l, r, value, mid + 1, nr, id * 2 + 1);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
} 

ll query(int l, int r, int nl = 0, int nr = MAX_N, int id = 1) {
	updateLazy(nl, nr, id);
	if (r < nl || nr < l)
		return 0;
	if (l <= nl && nr <= r) {
		return tree[id];
	}
	int mid = (nl + nr) / 2;
	ll lValue = query(l, r, nl, mid, id * 2);
	ll rValue = query(l, r, mid + 1, nr, id * 2 + 1);
	return lValue + rValue;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		mapper.emplace(b, 0);
		mapper.emplace(c + 1, 0);

		if (a == 1) 
			q1.emplace_back(pii(b, c), d);
		else
			q2.emplace_back(pii(b, c), pii(d - 1, cnt++));
	}
	sort(q2.begin(), q2.end(), [](pair<pii, pii>& a, pair<pii, pii>& b) -> bool {
		return a.second.first < b.second.first;
	});

	cnt = 0;
	for (auto p : mapper) {
		mapper[p.first] = ++cnt;
		rMapper[cnt] = p.first;
	}

	for (int i = 0; i < q1.size(); ++i)
		q1[i].first = {mapper[q1[i].first.first], mapper[q1[i].first.second + 1] - 1};
	for (int i = 0; i < q2.size(); ++i)
		q2[i].first = {mapper[q2[i].first.first], mapper[q2[i].first.second + 1] - 1};

	int prv = -1;
	ll ans[MAX_N];
	for (int i = 0; i < q2.size(); ++i) {
		if (prv != q2[i].second.first) {
			for (int j = prv + 1; j <= q2[i].second.first; ++j) {
				update(q1[j].first.first, q1[j].first.second, q1[j].second);
			}
			prv = q2[i].second.first;
		}
		ans[q2[i].second.second] = query(q2[i].first.first, q2[i].first.second);
	}
	for (int i = 0; i < q2.size(); ++i)
		cout << ans[i] << endl;
	
	return 0;
}
