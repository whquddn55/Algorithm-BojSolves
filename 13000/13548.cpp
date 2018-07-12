#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

#define MAX_N 100000

int n, q;
int arr[MAX_N];
pii query[MAX_N];
int idx[MAX_N];
int ans[MAX_N];
int cnt[MAX_N];
int cnt2[MAX_N];

int ret = 0;

void add(int idx) {
	cnt2[cnt[arr[idx]]]--;
	cnt[arr[idx]]++;
	cnt2[cnt[arr[idx]]]++;
	ret = max(ret, cnt[arr[idx]]);
}

void erase(int idx) {
	cnt2[cnt[arr[idx]]]--;
	cnt[arr[idx]]--;
	cnt2[cnt[arr[idx]]]++;
}

void doQuery(pii prv, pii now) {
	int l1 = prv.first;
	int r1 = prv.second;
	int l2 = now.first;
	int r2 = now.second;

	for (int i = l1 - 1; i >= l2; i--)
		add(i);
	for (int i = l1; i < l2; i++)
		erase(i);
	for (int i = r1 + 1; i <= r2; i++)
		add(i);
	for (int i = r1; i > r2; i--)
		erase(i);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> q;
	for (int i = 0; i < q; i++) {
		idx[i] = i;
		cin >> query[i];
		query[i].first--;
		query[i].second--;
	}

	sort(idx, idx + q, [](int a, int b)->bool {
		return pii{ query[a].first / 300, query[a].second } < pii{ query[b].first / 300, query[b].second };
	});

	for (int i = 0; i < q; i++) {
		pii prv;
		pii now = query[idx[i]];
		if (i == 0)
			prv = { 0, -1 };
		else
			prv = query[idx[i - 1]];

		doQuery(prv, now);
		while (cnt2[ret] == 0)
			ret--;
		ans[idx[i]] = ret;
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << endl;

	return 0;
}