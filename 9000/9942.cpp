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
#define MAX_N 1005
#define MOD 1000000

int n;
ll dp[MAX_N][MAX_N];

ll getDp(int i1, int i2) {
    if (i1 == 1)
        return 1;
    if (i2 == 3)
        return pow(2, i1) -1;
    ll& ret = dp[i1][i2];
    if (ret != -1)
        return ret;
    ll k = i1 - floor(sqrt(2*i1 + 1) + 0.5) + 1;
    return ret = getDp(k, i2) * 2 + getDp(i1 - k, i2 - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int tc = 1;
    while(cin >> n) {
        memset(dp, -1, sizeof(dp));
        cout << "Case "<< tc++ << ": " << getDp(n, 4) << endl;
    }
    
    return 0;
}
