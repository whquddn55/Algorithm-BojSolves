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

int n, m;
vector<int> adj[MAX_N];

int dfsn[MAX_N];
bool isCut[MAX_N];
int cnt;
int dfs(int here, int root) {
    dfsn[here] = ++cnt; 
    int ret = dfsn[here];
    int childCnt = 0;
    for (int child : adj[here]) {
        if (dfsn[child]) {
            ret = min(ret, dfsn[child]);
            continue;
        }
        int childResult = dfs(child, root);
        if (here != root && childResult >= dfsn[here])
            isCut[here] = true;
        ret = min(ret, childResult);
        ++childCnt;
    }
    if (here == root && childCnt >= 2)
        isCut[here] = true;
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

    for (int i = 1; i <= n; ++i)
        if (!dfsn[i])
            dfs(i, i);

    vector<int> ret;
    for (int i = 1; i <= n; ++i)
        if (isCut[i])
            ret.push_back(i);
    cout << ret.size() << endl;
    for (int e : ret)
        cout << e << ' ';

	return 0;
}
