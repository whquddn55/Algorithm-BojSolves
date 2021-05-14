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
#define MAX_N 1005

int n, m;
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq, pq2;

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
    int result = 0;
    for (int i = 0; i <= n; ++i)
        parent[i] = i;
    while(pq.size()) {
        int c = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        if (find(a) == find(b))
            continue;
        merge(a, b);
        result += c;
    }
    int result2 = 0;
    for (int i = 0; i <= n; ++i)
        parent[i] = i;
    while(pq2.size()) {
        int c = pq2.top().first;
        int a = pq2.top().second.first;
        int b = pq2.top().second.second;
        pq2.pop();

        if (find(a) == find(b))
            continue;
        merge(a, b);
        result2 += !c;
    }
    return result2 * result2 - result * result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    ++m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.emplace(!c, pii(a, b));
        pq2.emplace(c, pii(a, b));
    }

    cout << kruskal() << endl;

	return 0;
}
