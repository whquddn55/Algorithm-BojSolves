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
#define MAX_N 10005
#define MOD 1000000007

int n, m;
int cost[MAX_N];
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> edges;

int parent[MAX_N];
int depth[MAX_N];
int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
        if (depth[u] < depth[v])
            swap(u, v);
        parent[v] = u;
        if (depth[u] == depth[v])
            ++depth[u];
    }
}

int kruskal() {
    for (int i = 0; i < MAX_N; ++i)
        parent[i] = i;
    
    int result = 0;
    while(edges.size()) {
        int c = edges.top().first;
        int f = edges.top().second.first;
        int t = edges.top().second.second;
        edges.pop();

        f = find(f);
        t = find(t);
        if (f == t)
            continue;
        merge(f, t);
        result += c;
    }
    int minValue = INF;
    for (int i = 0; i < n; ++i)
        minValue = min(minValue, cost[i]);
    return result + minValue;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> cost[i];
    while(m--) {
        int f, t, c;
        cin >> f >> t >> c;
        --f;
        --t;
        edges.emplace(c * 2 + cost[t] + cost[f], pii(f, t));
    }

    cout << kruskal() << endl;
    
    return 0;
}