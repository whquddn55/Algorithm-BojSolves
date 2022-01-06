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
#define MAX_N 55
#define MOD 1'000'000'007

int n;
int dist[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < MAX_N; ++i)
        fill(dist[i], dist[i] + MAX_N, INF);
    for (int i = 0; i < MAX_N; ++i)
        dist[i][i] = 0;
    while(true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        dist[a][b] = dist[b][a] = 1;
    }

    for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = INF;
    vector<int> candi;
    for (int i = 1; i <= n; ++i) 
        ans = min(ans, *max_element(dist[i] + 1, dist[i] + 1 + n));
    for (int i = 1; i <= n; ++i)
        if (*max_element(dist[i] + 1, dist[i] + 1 + n) == ans)
            candi.emplace_back(i);
    cout << pii(ans, candi.size()) << endl;
    for (auto e : candi)
        cout << e << ' ';

    return 0;
}
