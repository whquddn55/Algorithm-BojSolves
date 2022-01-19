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
#define MAX_N 1005
#define MOD 1'000'000'007

int n, m;
vector<int> adj[MAX_N];
int ind[MAX_N];
int ans[MAX_N];

void bfs() {
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (ind[i] == 0) {
            q.emplace(i);
            ans[i] = 1;
        }
    
    while(q.size()) {
        int here = q.front(); 
        q.pop();

        for (int nxt : adj[here]) {
            ind[nxt]--;
            if (ind[nxt] == 0) {
                q.emplace(nxt);
                ans[nxt] = ans[here] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].emplace_back(b);
        ind[b]++;
    }

    bfs();
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';


    return 0;
}
