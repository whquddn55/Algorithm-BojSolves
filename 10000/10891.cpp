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
#define MAX_N 100005
#define MOD 9901

int n, m;
vector<int> adj[MAX_N];

int dfsn[MAX_N];
int dfscnt = 0;
bool inPath[MAX_N];
bool ans = true;
int dfs(int here, int parent) {
    inPath[here] = true;
    dfsn[here] = ++dfscnt;
    int ret = dfsn[here];
    bool checker = false;
    for (int child : adj[here]) {
        if (child == parent)
            continue;
        if (dfsn[child] != 0) {
            ret = min(ret, dfsn[child]);
            if (inPath[child]) {
                if (checker == true)
                    ans = false;
                checker = true;
            }
        }
        else {
            int childResult = dfs(child, here);
            if (childResult <= dfsn[here]) {
                if (checker == true)
                    ans = false;
                checker = true;
            }
            ret = min(ret, childResult);
        }
    }

    inPath[here] = false;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    while(m--) {
        int f, t;
        cin >> f >> t;
        adj[f].emplace_back(t);
        adj[t].emplace_back(f);
    }

    dfs(1, 0);
    if (ans)
        cout << "Cactus" << endl;
    else
        cout << "Not cactus" << endl;

    return 0;
}