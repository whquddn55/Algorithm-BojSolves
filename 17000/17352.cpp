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
#define MAX_N 300'005
#define MOD 1'000'000'007

int n;
vector<int> adj[MAX_N];

queue<int> q;
bool visited[MAX_N];
void bfs() {
    q.emplace(0);
    visited[0] = true;

    while(q.size()) {
        int here = q.front();
        q.pop();

        for (int nxt : adj[here]) {
            if (visited[nxt])
                continue;
            q.emplace(nxt);
            visited[nxt] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 2; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    bfs();

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << pii(1, i + 1) << endl;
            break;
        }
    }

    return 0;
}
