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
#define MAX_N 16
#define MOD 1'000'000'007

int n;
pii arr[MAX_N];
double dist[MAX_N][MAX_N];
double dp[MAX_N][1 << MAX_N];

double getDp(int i1, int i2) {
    if (i2 == (1 << n) - 1) {
        return dist[i1][0];
    }
    
    double& ret = dp[i1][i2];
    if (ret != -1)
        return ret;

    ret = INF;
    for (int i = 0; i < n; ++i) {
        if (i2 & (1 << i))
            continue;
        ret = min(ret, getDp(i, i2 | (1 << i)) + dist[i1][i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = sqrt((arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < (1 << n); ++j) {
            dp[i][j] = -1;
        }

    cout.precision(10);
    cout << fixed;
    cout << getDp(0, 0) << endl;

    return 0;
}
