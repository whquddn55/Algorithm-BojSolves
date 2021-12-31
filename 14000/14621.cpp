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
char arr[MAX_N];
vector<pair<int, pii>> edges;

int parent[MAX_N];
int find(int u) {
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;
    parent[u] = v;
}

int kruskal() {
    for (int i = 0; i < n; ++i)
        parent[i] = i;
    
    int ans = 0;
    for (auto& e : edges) {
        int u = find(e.second.first);
        int v = find(e.second.second);
        if (u == v)
            continue;
        merge(u, v);
        ans += e.first;
    }
    for (int i = 1; i < n; ++i)
        if (find(0) != find(i))
            ans = -1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        if (arr[a] == arr[b]) 
            continue;
        edges.emplace_back(c, pii(a, b));
    }
    sort(all(edges));
    cout << kruskal() << endl;

    return 0;
}
