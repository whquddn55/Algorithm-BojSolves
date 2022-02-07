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
#define MAX_N 50005
#define MOD 1'000'000'007

int n, m;
vector<pii> adj[MAX_N];

int spfa() {
    queue<int> q;
    bool inQ[MAX_N] = { false, };
    int dist[MAX_N];
    fill_n(dist, MAX_N, INF);

    dist[1] = 0;
    q.emplace(1);
    inQ[1] = true;

    while(q.size()) {
        int here = q.front();
        q.pop();
        inQ[here] = false;

        for (pii& e : adj[here]) {
            int nxt = e.first;
            int cost = e.second;

            if (dist[nxt] > dist[here] + cost) {
                dist[nxt] = dist[here] + cost;
                if (!inQ[nxt]) {
                    q.emplace(nxt);
                    inQ[nxt] = true;
                }
            }
        }
    }

    return dist[n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while(m--) {
        int f, t, c;
        cin >> f >> t >> c;
        adj[f].emplace_back(t,c);
        adj[t].emplace_back(f,c);
    }

    cout << spfa() << endl;

    return 0;
}
