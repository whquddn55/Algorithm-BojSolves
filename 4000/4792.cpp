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
#define MAX_N 1005

int n, m, k;
vector<pair<int, pii>> edges;
int parent[MAX_N];
int find(int u){
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v)
        parent[u] = v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    while(true) {
        edges.clear();
        
        cin >> n >> m >> k;
        if (!n && !m && !k)
            break;

        while(m--) {
            char c;
            int f, t;
            cin >> c >> f >> t;
            --f;
            --t;

            if (c == 'B')
                edges.emplace_back(1, pii(f, t));
            else
                edges.emplace_back(0, pii(f, t));
        }

        for (int i = 0; i < MAX_N; ++i) 
            parent[i] = i;
        int minValue = 0;
        sort(all(edges));
        for (auto& e : edges) {
            if (find(e.second.first) != find(e.second.second)) {
                merge(e.second.first, e.second.second);
                minValue += e.first;
            }
        }

        for (int i = 0; i < MAX_N; ++i) 
            parent[i] = i;
        int maxValue = 0;
        sort(all(edges), greater<pair<int, pii>>());
        for (auto& e : edges) {
            if (find(e.second.first) != find(e.second.second)) {
                merge(e.second.first, e.second.second);
                maxValue += e.first;
            }
        }
        cout << ((minValue <= k) && (k <= maxValue)) << endl;
    }
    
    return 0;
}
