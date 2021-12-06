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
#define MAX_N 20
#define MOD 1'000'000'007

int n;
int arr[MAX_N][MAX_N];

bool check(int y, int x) {
    if (y >= n || y < 0 || x >= n || x < 0)
        return false;
    if (arr[y][x] == 1)
        return false;
    return true;
}

int dfs(int y, int x, int st) {
    if (y == n - 1 && x == n - 1)
        return 1;
    int ans = 0;
    if (st == 0) {
        if (check(y, x + 1))
            ans += dfs(y, x + 1, 0);
        if (check(y + 1, x + 1) && check(y, x + 1) && check(y + 1, x))
            ans += dfs(y + 1, x + 1, 1);
    }
    else if (st == 1) {
        if (check(y, x + 1))
            ans += dfs(y, x + 1, 0);
        if (check(y + 1, x))
            ans += dfs(y + 1, x, 2);
        if (check(y + 1, x + 1) && check(y, x + 1) && check(y + 1, x))
            ans += dfs(y + 1, x + 1, 1);
    }
    else {
        if (check(y + 1, x))
            ans += dfs(y + 1, x, 2);
        if (check(y + 1, x + 1) && check(y, x + 1) && check(y + 1, x))
            ans += dfs(y + 1, x + 1, 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];

    if (arr[0][0] == 1 || arr[0][1] == 1)
        cout << 0 << endl;
    else {
        cout << dfs(0, 1, 0) << endl;
    }
    
    return 0;
}
