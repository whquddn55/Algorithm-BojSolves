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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 1000005
#define MOD 1'000'000'007

int dp[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    ll sum = 1;
    
    int i = 2;
    int remain = 0;
    int j = 1;
    while(sum < n) {
        if (remain == 0) {
            j += 1;
            //cout << j << endl;
            remain = dp[j];
        } else {
            //cout << pii(i, j) << endl;
            remain--;
            dp[i] = j;
            sum += i * j;
            ++i;
        }
    }

    int ans = 0;
    sum = 0;
    for (int i = 1; i <= 1000000; ++i) {
        if (dp[i] == 0)
            break;
        while(dp[i]--) {
            ans++;
            sum += i;

            if (sum >= n)
                break;
        }
        if (sum >= n)
            break;
    }
    cout << ans << endl;
    
    
    return 0;
}
