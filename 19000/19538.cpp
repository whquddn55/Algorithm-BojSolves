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
#define MAX_N 200'005
#define MOD 1'000'000'007

int n, m;
int arr[MAX_N];
int cnt[MAX_N];
vector<int> adj[MAX_N];

int dist[MAX_N];
void bfs() {
    queue<int> q;
    fill(dist, dist + MAX_N, INF);
    for (int i = 0; i < m; ++i) {
        dist[arr[i]] = 0;
        q.emplace(arr[i]);
    }

    while(q.size()) {
        int here = q.front();
        q.pop();

        for (auto nxt : adj[here]) {
            if (dist[nxt] != INF)
                continue;
            cnt[nxt]++;
            if (cnt[nxt] >= (adj[nxt].size() + 1) / 2) {
                dist[nxt] = dist[here] + 1;
                q.emplace(nxt);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        while(true) {
            cin >> t;
            if (!t)
                break;
            adj[i + 1].emplace_back(t);
        }
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> arr[i];

    bfs();
    for (int i = 1; i <= n; ++i) 
        cout << (dist[i] == INF ? -1 : dist[i]) << ' ';

    return 0;
}
