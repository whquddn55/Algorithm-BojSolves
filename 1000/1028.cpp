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
#define MAX_N 755
#define MOD 1000000007

int n, m;
char arr[MAX_N][MAX_N];
int dp1[MAX_N][MAX_N];
int dp2[MAX_N][MAX_N];

int getDp1(int idx1, int idx2) {
	if (idx1 < 0 || idx1 >= n || idx2 < 0 || idx2 >= m)
		return 0;
	int& ret = dp1[idx1][idx2];
	if (ret != -1)
		return ret;
	if (arr[idx1][idx2] == '0')
		return ret = 0;

	return ret = getDp1(idx1 + 1, idx2 - 1) + 1;
}

int getDp2(int idx1, int idx2) {
	if (idx1 < 0 || idx1 >= n || idx2 < 0 || idx2 >= m)
		return 0;
	int& ret = dp2[idx1][idx2];
	if (ret != -1)
		return ret;
	if (arr[idx1][idx2] == '0')
		return ret = 0;

	return ret = getDp2(idx1 + 1, idx2 + 1) + 1;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			int maxLen = min(getDp1(i, j),getDp2(i, j));
			for (int k = maxLen - 1; k >= ans; --k) {
				if (getDp2(i + k, j - k) >= k + 1 && getDp1(i + k, j + k) >= k + 1) {
					ans = k + 1;
					break;
				}
			}
		}
	cout << ans << endl;

	
    return 0;
}