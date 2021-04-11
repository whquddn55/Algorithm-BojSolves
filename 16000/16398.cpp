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
 
#define MAX_N 1005

int n;
vector<pair<int, pii>> arr;
int parent[MAX_N];
int srank[MAX_N];

int find(int u) {
    if (parent[u] == u)
        return u;

    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (srank[u] > srank[v])
        swap(u, v);
    
    parent[u] = v;
    if (srank[u] == srank[v])
        srank[v]++;
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
 
    cin >> n;
    arr.reserve(n * n / 2);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            int cost;
            cin >> cost;
            if (i < j)
                arr.emplace_back(cost, pii{i, j});
        }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    ll result = 0;
    for (auto& e : arr) {
        if (find(e.second.first) == find(e.second.second))
            continue;
        merge(e.second.first, e.second.second);
        result += e.first;
    }

    cout << result << endl;

 
	return 0;
}