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

#define INF (LLONG_MAX / 2)

#define MAX_N 303

int n, m;
pii arr[MAX_N];
ll dp[MAX_N]; // i번째 점 위에 있을 때 갖고 있는 최대 사탕수

ll getDp(int idx1) {
	ll& ret = dp[idx1];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = idx1 + 1; i < n; i++)
		if (arr[i].second >= arr[idx1].second)
			ret = max(ret, getDp(i) + m - arr[i].first - arr[i].second);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	n += 1;
	sort(arr, arr + n);

	memset(dp, -1, sizeof(dp));
	cout << getDp(0) << endl;

	return 0;
}