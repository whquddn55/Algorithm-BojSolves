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

#define all(x) (x).begin(), (x).end()
#define INF (INT_MAX / 2)
#define MAX_N 100005
#define MOD 1000000

int n, m;
vector<int> adj[MAX_N];

bool visited[MAX_N];
int bfs() {
    queue<pii> q;
    q.emplace(1, 0);
    int ans = 1;
    visited[1] = true;

    while(q.size()) {
        int here = q.front().first;
        int cost = q.front().second;
        q.pop();

        for (int nxt : adj[here]) {
            if (visited[nxt])
                continue;
            visited[nxt] = true;
            q.emplace(nxt, cost + 1);
            ans = cost + 1;
        }
    }

    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            return -1;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    int ans = bfs();
    if (ans == -1)
        cout << ans << endl;
    else 
        cout << ceil(log2(ans)) + 1 << endl;
    
    return 0;
}
