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

#define MAX_N 105
#define MOD 1000000007

int n, m, k;
pii arr[MAX_N];

int dp[MAX_N][MAX_N]; // 체력 i를 만드는데 j번째 까지 스킬을 썼을 때 드는 최소 비용?

int getDp(int hp, int index) {
	if (hp == m)
		return 0;
	if (hp > m || index < 0)
		return INF;
	

	int& ret = dp[hp][index];
	if (ret != -1)
		return ret;
	

	ret = INF;
	int sum = 0;
	for (int cnt = 0; cnt < MAX_N; ++cnt) {
		ret = min(ret, getDp(hp + arr[index].second * cnt, index - 1) + sum);
		sum += (arr[index].first + k * cnt);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	memset(dp, -1, sizeof(dp));
	cout << getDp(0, n - 1) << endl;

	return 0;
}