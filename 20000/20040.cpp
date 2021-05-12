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

#define MAX_N 500005
#define MOD 1000000007

int n, m;

int parent[MAX_N];
int height[MAX_N];
int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    
    if (height[u] < height[v]) 
        swap(u, v);
    parent[v] = u;
    if (height[u] == height[v])
        ++height[u];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    bool printed = false;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << i << endl;
            printed = true;
            break;
        }
        merge(a, b);
    }
    if (!printed)
        cout << 0 << endl;
    
    
	return 0;
}
