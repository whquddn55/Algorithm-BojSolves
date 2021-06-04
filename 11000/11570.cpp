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
#define MAX_N 2005
#define MOD 1000000007

int n;
int arr[MAX_N];
int dp[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    for (int i = n - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j) {
            if (i && j && i == j)
                continue;
            int nextIdx = max(i, j) + 1;
            dp[i][j] = min(dp[nextIdx][j] + (i ? abs(arr[nextIdx] - arr[i]) : 0), dp[i][nextIdx] + (j ? abs(arr[nextIdx] - arr[j]) : 0));
        }
    cout << dp[0][0] << endl;

    
    return 0;
}