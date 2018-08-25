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

#define MAX_N 512

int n;
pii arr[MAX_N];
double dp[MAX_N][MAX_N];

double dist(int a, int b) {
	return sqrt((arr[a].first - arr[b].first) * (arr[a].first - arr[b].first) + (arr[a].second - arr[b].second) * (arr[a].second - arr[b].second));
}

double getDp(int idx1, int idx2) {
	if (idx1 == n - 1 || idx2 == n - 1)
		return dist(idx1, idx2);

	double& ret = dp[idx1][idx2];
	if (ret != -2)
		return ret;
	ret = INF;
	int next = max(idx1, idx2) + 1;
	return ret = min(getDp(idx1, next) + dist(idx2, next), getDp(next, idx2) + dist(idx1, next));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(arr, 0 , sizeof(arr));
		for (int i = 0; i < MAX_N; i++)
			fill_n(dp[i], MAX_N, -2);

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << getDp(0, 0) << endl;
	}

	return 0;
}