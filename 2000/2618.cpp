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

#define MAX_N 1002

int n, w;
pii arr[MAX_N];
int dp[MAX_N][MAX_N];
int prv[MAX_N][MAX_N];

int getDp(int idx1, int idx2) {
	if (idx1 == w - 1 || idx2 == w - 1)
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	int nextIdx = max(idx1, idx2) + 1;
	int r1 = getDp(nextIdx, idx2) + abs(arr[idx1].first - arr[nextIdx].first) + abs(arr[idx1].second - arr[nextIdx].second);
	int r2 = getDp(idx1, nextIdx) + abs(arr[idx2].first - arr[nextIdx].first) + abs(arr[idx2].second - arr[nextIdx].second);
	if (r1 < r2) {
		ret = r1;
		prv[idx1][idx2] = 1;
	}
	else {
		ret = r2;
		prv[idx1][idx2] = 2;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> w;
	arr[0] = { 1, 1 };
	arr[1] = { n, n };
	w += 2;
	for (int i = 2; i < w; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	cout << getDp(0, 1) << endl;
	int idx1 = 0, idx2 = 1;
	while (true) {
		if (idx1 == w - 1 || idx2 == w - 1)
			break;
		cout << prv[idx1][idx2] << endl;
		if (prv[idx1][idx2] == 1)
			idx1 = max(idx1, idx2) + 1;
		else
			idx2 = max(idx1, idx2) + 1;
	}

	return 0;
}