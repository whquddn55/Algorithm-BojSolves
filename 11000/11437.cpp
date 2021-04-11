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
 
#define MAX_N 50005

int n, m;
vector<int> adj[MAX_N];

int depth[MAX_N];
int ancestor[MAX_N][20];
void getTree(int here, int parent) {
    depth[here] = depth[parent] + 1;
    ancestor[here][0] = parent;
    for (int i = 1; i < 20; ++i) 
        ancestor[here][i] = ancestor[ancestor[here][i - 1]][i - 1];
    
    for (int next : adj[here])
        if (next != parent)
            getTree(next, here);
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
 
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int f, t;
        cin >> f >> t;

        adj[f].emplace_back(t);
        adj[t].emplace_back(f);
    }

    getTree(1, 0);

    cin >> m;
    while(m--) {
        int a, b;
        cin >> a>> b;
        a;
        b;

        if (depth[a] < depth[b])
            swap(a, b);

        for (int i = 19; i >= 0; --i)
            if (ancestor[a][i] && depth[ancestor[a][i]] >= depth[b]) {
                a = ancestor[a][i];
            }

        if (a == b) {
            cout << a << endl;
        }
        else {
            for (int i = 19; i >= 0; --i)
                if (ancestor[a][i] != ancestor[b][i]) {
                    a = ancestor[a][i];
                    b = ancestor[b][i];
                }

             cout << ancestor[a][0] << endl;
        }
    }
 
	return 0;
}