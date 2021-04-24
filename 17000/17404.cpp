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

#define MAX_N 1005

int n;
int cost[MAX_N][3];
int dp[MAX_N][3];
int result = INF;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> cost[i][j];

    for (int i = 0; i < 3; ++i) {
        dp[0][i] = cost[0][i];
        dp[0][(i + 1) % 3] = INF;
        dp[0][(i + 2) % 3] = INF;
        for (int j = 1; j < n; ++j) {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
            dp[j][2] = min(dp[j - 1][1], dp[j - 1][0]) + cost[j][2];
        }
        result = min({result, dp[n - 1][(i + 1) % 3], dp[n - 1][(i + 2) % 3]});
    }

    cout << result << endl;

	return 0;
}
