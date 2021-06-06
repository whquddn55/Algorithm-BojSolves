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
#define MAX_N 14
#define MOD 9901

int n, m;
int dp[MAX_N][MAX_N][1 << MAX_N];

int getDp(int i1, int i2, int i3) {
    if (i1 >= n)
        return 1;
    int& ret = dp[i1][i2][i3];
    if (ret != -1)
        return ret;

    ret = 0; 
    // case1 -> 1 x 2
    if (i2 != m - 1 && (i3 & 1) == 0) {
        int temp = i3 + 1;
        int next = 1;
        while(temp & 1) {
            ++next;
            temp>>=1;
        }

        int nextX = (i2 + next) % m;
        int nextY = i1 + (i2 + next) / m;
        ret += getDp(nextY, nextX, i3 >> next);
    }
    if (i1 != n - 1) {
        int temp = i3 | (1 << (m - 1));
        int next = 1;
        while(temp & 1) {
            ++next;
            temp>>=1;
        }

        int nextX = (i2 + next) % m;
        int nextY = i1 + (i2 + next) / m;
        ret += getDp(nextY, nextX, ((i3 | (1 << (m - 1))) >> next));
    }
    return ret % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));
    cout << getDp(0, 0, 0) << endl;

    return 0;
}