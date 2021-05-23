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
#define MAX_N 10005
#define MOD 1000000007

int n, m;
int arr[MAX_N];
int dp[502][2];
int prv[502][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    ++m;

    prv[1][1] = arr[0];
    for (int i = 1; i < n; ++i) {
        dp[0][0] = max({prv[0][0], prv[1][0], prv[1][1]});
        for (int j = 1; j < m; ++j) {
            dp[j][0] = max(prv[j + 1][0], prv[j + 1][1]);
            dp[j][1] = prv[j - 1][1] + arr[i];
            if (j == 1)
                dp[j][1] = max(dp[j][1], prv[j - 1][0] + arr[i]);
        }
        dp[m][1] = prv[m - 1][1] + arr[i];
        for (int j = 0; j <= m; ++j) {
            prv[j][0] = dp[j][0];
            prv[j][1] = dp[j][1];
        }
    }


    cout << dp[0][0]  << endl;
    
    return 0;
}