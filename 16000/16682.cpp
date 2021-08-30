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
#define MAX_N 50005
#define MOD 1000003

int n;
vector<pair<int, pair<pii, pii>>> arr;
map<ll, ll> mapper;
ll rMapper[MAX_N];

vector<ll> tree[MAX_N * 4];
ll v[MAX_N * 4][3];

void init() {
	for (int i = 0; i < MAX_N * 4; ++i)
		tree[i].resize(8, 0);
}

void update(int l, int r, int value, char type, int nl = 0, int nr = MAX_N - 1, int id = 1) {
	int mid = (nl + nr) / 2;
	if (r < nl || nr < l)
		return;
	if (l <= nl && nr <= r) {
		if (type == 'C')
			v[id][0] += value;
		else if (type == 'Y')
			v[id][1] += value;
		else
			v[id][2] += value;

		int index = (((!!v[id][0]) << 0) | ((!!v[id][1]) << 1) | ((!!v[id][2]) << 2));

		fill(tree[id].begin(), tree[id].end(), 0);
		if (nl != nr) {
			int remain = rMapper[nr + 1] - rMapper[nl];
			for (int i = 1; i < 8; ++i) {
				if (tree[id * 2][i]) {
					tree[id][i | index] += tree[id * 2][i];
					remain -= tree[id * 2][i];
				}
				if (tree[id * 2 + 1][i]) {
					tree[id][i | index] += tree[id * 2 + 1][i];
					remain -= tree[id * 2 + 1][i];
				}
			}
			tree[id][index] += remain;
		}
		else {
			if (index)
				tree[id][index] = rMapper[nr + 1] - rMapper[nl];
		}
		return;
	}
	update(l, r, value, type, nl, mid, id * 2);
	update(l, r, value, type, mid + 1, nr, id * 2 + 1);

	int index = (((!!v[id][0]) << 0) | ((!!v[id][1]) << 1) | ((!!v[id][2]) << 2));

	fill(tree[id].begin(), tree[id].end(), 0);
	if (nl != nr) {
		int remain = rMapper[nr + 1] - rMapper[nl];
		for (int i = 1; i < 8; ++i) {
			if (tree[id * 2][i]) {
				tree[id][i | index] += tree[id * 2][i];
				remain -= tree[id * 2][i];
			}
			if (tree[id * 2 + 1][i]) {
				tree[id][i | index] += tree[id * 2 + 1][i];
				remain -= tree[id * 2 + 1][i];
			}
		}
		tree[id][index] += remain;
	}
	else {
		if (index)
			tree[id][index] = rMapper[nr + 1] - rMapper[nl];
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		char c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		arr.emplace_back(x1, pair<pii, pii>({y1, y2}, {c, 1}));
		arr.emplace_back(x2, pair<pii, pii>({y1, y2}, {c, -1}));

		mapper[y1] = 1;
		mapper[y2] = 1;
	}
	sort(arr.begin(), arr.end());

	int cnt = 0;
	for (auto p : mapper) {
		mapper[p.first] = cnt;
		rMapper[cnt] = p.first;
		cnt++;
	}
	init();

	ll ans[7] = {0, };
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i].second.second.second == 1)
			update(mapper[arr[i].second.first.first], mapper[arr[i].second.first.second] - 1, 1, arr[i].second.second.first, 0, mapper.size() - 1);
		else
			update(mapper[arr[i].second.first.first], mapper[arr[i].second.first.second] - 1, -1, arr[i].second.second.first, 0, mapper.size() - 1);
		if (i != arr.size() - 1 && (arr[i].first != arr[i + 1].first)) {
			for (int j = 0; j < 7; ++j)
				ans[j] += tree[1][j + 1] * (arr[i + 1].first - arr[i].first);
		}
	}
	cout << ans[0] << ' ' << ans[3] << ' ' << ans[1] << ' ' << ans[5] << ' ' << ans[2] << ' ' << ans[4] << ' ' << ans[6] << endl;

	return 0;
}
