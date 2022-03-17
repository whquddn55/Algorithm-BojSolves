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
#define MAX_N 505
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int t, n;
int arr[MAX_N];
int psum[MAX_N];
int dp[MAX_N][MAX_N * 10];
int ans[MAX_N];

int getDp(int i1, int i2) {
    if (i1 == n + 1) {
        return 1;
    }
    int& ret = dp[i1][i2];
    if (ret != -1) return ret;
    ret = 0;

    /* 1번 가방 */
    if (i2 - arr[i1] >= 0) {
        ans[i1]= t - i2;
        ret = getDp(i1 + 1, i2 - arr[i1]);
    }

    /* 2번 가방 */
    int secondStorage = t - (psum[i1] - (t - i2));
    if (ret == 0 && secondStorage >= 0) {
        ans[i1] = t - (secondStorage + arr[i1]);
        ret = getDp(i1 + 1, i2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t >> n;
    for (int i = 1; i <= n; ++i){
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }

    memset(dp, -1, sizeof(dp));
    getDp(1, t);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << endl;
    
    
    return 0;
}
