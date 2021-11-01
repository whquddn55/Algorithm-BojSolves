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
#define MAX_N 30005

int n, m, k;
int arr[MAX_N];
int parent[MAX_N];
int level[MAX_N];
bool visited[MAX_N];
int dp[3005];

int find(int u){
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);

    if (u != v) {
        if (level[v] > level[u])
            swap(v, u);
        parent[u] = v;
        arr[v] += arr[u];
        level[v] += level[u];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        level[i] = 1;
    }
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        merge(a, b);
    }
    
    int p = find(0);
    if (level[p] < k) {
        dp[level[p]] = arr[p];
        visited[p] = true;
    }
    for (int i = 1; i < n; ++i) {
        int p = find(i);
        if (visited[p])
            continue;
        visited[p] = true;
        for (int j = k - 1; j >= 0; --j) {
            if (j - level[p] >= 0)
                dp[j] = max(dp[j], dp[j - level[p]] + arr[p]);
        }
    }
    cout << dp[k - 1] << endl;
    
    return 0;
}
