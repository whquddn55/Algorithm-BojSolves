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

int v, e;
vector<int> adj[MAX_N];
int dfsn[MAX_N];
int cnt = 0;
vector<pii> result;
int dfs(int here, int p) {
    dfsn[here] = ++cnt;
    int ret = dfsn[here];
    int childCnt = 0;
    for (int child: adj[here]) {
        if (child == p)
            continue;
        if (dfsn[child]) {
            ret = min(ret, dfsn[child]);
            continue;
        }
        int childValue = dfs(child, here);
        if (childValue > dfsn[here]) {
            if (here > child)
                result.emplace_back(child, here);
            else
                result.emplace_back(here, child);
        }
        ret = min(ret, childValue);
        ++childCnt;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> v >> e;
    while(e--) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    } 

    dfs(1, 0);

    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto e : result)
        cout << e << endl;

	return 0;
}
