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
#define MAX_N 35
#define MOD 1000000007

string s;
int n;
int dp[MAX_N][MAX_N];

int getDp(int f, int t) {
    if (f == t)
        return 0;
    if (f == t - 1)
        return s[f] == s[t];
    int& ret = dp[f][t];
    if (ret != -1)
        return ret;

    ret = 0;
    if (s[f] == s[t])
        ret += getDp(f + 1, t - 1) + (t - f);

    return ret += getDp(f + 1, t) + getDp(f, t - 1) - getDp(f + 1, t - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    cout << getDp(0, n - 1) + n << endl;
    
    return 0;
}