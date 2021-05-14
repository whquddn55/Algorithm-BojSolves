#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 100005

int n, m, q;
pii edges[MAX_N];
int queries[MAX_N];
bool check[MAX_N];

int parent[MAX_N];
int depth[MAX_N];
int sz[MAX_N];
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
        sz[u] += sz[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i)
        cin >> edges[i];
    
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
        --queries[i];
        check[queries[i]] = true;
    }

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; ++i) 
        if (!check[i])
            merge(edges[i].first, edges[i].second);
    
    ll result = 0;
    for (int i = q - 1; i >= 0; --i) {
        int a = find(edges[queries[i]].first);
        int b = find(edges[queries[i]].second);

        if (a == b)
            continue;
        result += (ll)sz[a] * sz[b];
        merge(a, b);
    }

    cout << result << endl;

	return 0;
}
