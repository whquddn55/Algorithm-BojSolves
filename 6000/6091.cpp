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
#define MAX_N 1025
#define MOD 1'000'000'007

int n;
int dist[MAX_N][MAX_N];
vector<int> adj[MAX_N];

void prim() {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    bool visited[MAX_N] = { false, }; 
    pq.emplace(0, pii(-1, 0));

    while (pq.size()) {
        int hereCcost = pq.top().first;
        int prv = pq.top().second.first;
        int here = pq.top().second.second;
        pq.pop();

        if (visited[here]) continue;

        visited[here] = true;
        if (prv != -1) {
            adj[prv].emplace_back(here);
            adj[here].emplace_back(prv);
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            pq.emplace(dist[here][i], pii(here, i));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            dist[i][j] = dist[j][i];
        }
        dist[i][i] = INF;
        for (int j = i + 1; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    prim();

    for (int i = 0; i < n; ++i) {
        cout << adj[i].size() << ' ';
        sort(all(adj[i]));
        for (auto e : adj[i])
            cout << e + 1<< ' ';
        cout << endl;
    }

    return 0;
}
