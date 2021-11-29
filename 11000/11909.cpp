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

#define all(x) (x.begin(), x.end())
#define INF (INT_MAX / 2)
#define MAX_N 2224
#define MOD 1'000'000'007

int n;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) 
            cin >> arr[i][j];
        
    for (int i = 1; i < n; ++i)
        dp[i][0] = dp[i - 1][0] + (arr[i - 1][0] <= arr[i][0] ? arr[i][0] - arr[i - 1][0] + 1 : 0);

    for (int i = 1; i < n; ++i)
        dp[0][i] = dp[0][i - 1] + (arr[0][i - 1] <= arr[0][i] ? arr[0][i] - arr[0][i - 1] + 1 : 0);

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j) {
            dp[i][j] = min(
                dp[i - 1][j] + (arr[i - 1][j] <= arr[i][j] ? arr[i][j] - arr[i - 1][j] + 1 : 0),
                dp[i][j - 1] + (arr[i][j - 1] <= arr[i][j] ? arr[i][j] - arr[i][j - 1] + 1 : 0)
            );
        }
    
    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
