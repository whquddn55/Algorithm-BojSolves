#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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


#define MAX_N 16

int n;
int arr[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

int getDp(int idx1, int idx2) {
	if ((idx1 + 1) & (1 << n))
		return arr[idx2][0] ? arr[idx2][0] : INF;
	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int i = 0; i < n; i++) {
		if (arr[idx2][i] && (idx1 & (1 << i)) == 0)
			ret = min(ret, getDp(idx1 | (1 << i), i) + arr[idx2][i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	memset(dp, -1, sizeof(dp));
	cout << getDp(1 << 0, 0) << endl;

	return 0;
}
