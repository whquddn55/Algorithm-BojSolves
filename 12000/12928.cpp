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
#define MAX_N 55

int n, s;
int dp[MAX_N][MAX_N * 2][1005];

int getDp(int i1, int i2, int i3) {
    if (i3 > 1000)
        return false;
    if (i2 == 0) {
        if (i1 == n)
            return i3 == s;
        return false;
    }
    if (i1 == n)
        return false;
    int& ret= dp[i1][i2][i3];
    if (ret != -1)
        return ret;

    ret = false;
    for (int i = 1; i <= i2; ++i)
        ret |= getDp(i1 + 1, i2 - i, i3 + (i * (i - 1)) / 2);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    memset(dp, -1, sizeof(dp));
    cin >> n >> s;
    if (n <= 2)
        cout << 0 << endl;
    else
        cout << getDp(0, n * 2 - 2, 0) << endl;
    
    return 0;
}
