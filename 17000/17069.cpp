#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 35
#define MOD 1'000'000'007

int n;
bool arr[MAX_N][MAX_N];
ll dp[MAX_N][MAX_N][3];

bool check(int y, int x, int st) {
	vector<pii> candi;
	if (st == 0) {
		candi.emplace_back(y, x);
	}
	else if (st == 1) {
		candi.emplace_back(y, x);
		candi.emplace_back(y - 1, x);
		candi.emplace_back(y, x - 1);
	}
	else {
		candi.emplace_back(y, x);
	}
	for (pii& e : candi) {
		if (e.first >= n || e.second >= n || e.first < 0 || e.second < 0)
			return false;
		if (arr[e.first][e.second])
			return false;
	}
	return true;
}

ll getDp(int i1, int i2, int i3) {
	if (!check(i1, i2, i3))
		return 0;
	if (i1 == n - 1 && i2 == n - 1)
		return 1;

	ll& ret = dp[i1][i2][i3];
	if (ret != -1)
		return ret;

	ret = 0;
	if (i3 == 0) {
		ret = getDp(i1, i2 + 1, 0) + getDp(i1 + 1, i2 + 1, 1);
	}
	else if (i3 == 1) {
		ret = getDp(i1, i2 + 1, 0) + getDp(i1 + 1, i2 + 1, 1) + getDp(i1 + 1, i2, 2);
	}
	else {
		ret = getDp(i1 + 1, i2 + 1, 1) + getDp(i1 + 1, i2, 2);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) 
			cin >> arr[i][j];
		

	memset(dp, -1, sizeof(dp));
	cout << getDp(0, 1, 0) << endl;

	return 0;
}