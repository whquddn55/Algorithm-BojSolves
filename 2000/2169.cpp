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

#define MAX_N 1000

int n, m;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][3]; // 0 : 양쪽 이동 가능한 상태, 1 : 오른쪽으로만 이동가능한 상태, 2 : 왼쪽으로만 이동가능한 상태

int getDp(int idx1, int idx2, int idx3) {
	if (idx1 == 0 && idx2 == 0)
		return arr[idx1][idx2];
	if (idx1 >= n || idx1 < 0 || idx2 >= m || idx2 < 0)
		return -INF;

	int& ret = dp[idx1][idx2][idx3];
	if (ret != -1)
		return ret;

	ret = arr[idx1][idx2];
	if (idx3 == 0)
		ret += max({ getDp(idx1 - 1, idx2, 0), getDp(idx1, idx2 - 1, 1), getDp(idx1, idx2 + 1, 2) });
	else if (idx3 == 1)
		ret += max(getDp(idx1 - 1, idx2, 0), getDp(idx1, idx2 - 1, 1));
	else if (idx3 == 2)
		ret += max(getDp(idx1 - 1, idx2, 0), getDp(idx1, idx2 + 1, 2));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	memset(dp, -1, sizeof(dp));
	cout << max({ getDp(n - 1, m - 1, 0), getDp(n - 1, m - 1, 1) }) << endl;
	
	return 0;
}