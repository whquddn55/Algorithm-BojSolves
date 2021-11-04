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

#define all(x) (x).begin(), (x).end()
#define INF (INT_MAX / 2)
#define MAX_N 100005
#define MOD 1000000

int n, k;
int arr[MAX_N];
ll sum[MAX_N];
int prv[MAX_N];

ll dp[MAX_N];
ll getDp(int i1) {
    if (i1 < 0)
        return 0;
    ll& ret = dp[i1];
    if (ret != -1)
        return ret;

    return ret = max(getDp(i1 - 1), getDp(prv[i1] - 1) + sum[i1] - k);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    ll psum = 0;
    int from = 0;
    for (int i = 0; i < n; ++i) {
        psum += arr[i];
        sum[i] = psum;
        prv[i] = from;

        while(psum >= k) {
            psum -= arr[from];
            ++from;
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << getDp(n - 1) << endl;
    
    return 0;
}
