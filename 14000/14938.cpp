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
#define MAX_N 105
#define MOD 1'000'000'007

int n, m, r;
int arr[MAX_N];
int dist[MAX_N][MAX_N];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> r;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = INF;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    while(r--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        dist[a][b] = dist[b][a] = c;
    }

    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= m)
                sum += arr[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    
    return 0;
}
