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

int v, e;
vector<pii> adj[MAX_N];
vector<pair<int, pii>> edges;
bool isIn[MAX_N * 4];

int parent[MAX_N];
int level[MAX_N];
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
    
    if (level[u] < level[v])
        swap(u, v);

    parent[u] = v;

    if (level[u] == level[v])
        level[v]++;
}

int height[MAX_N];
int ances[MAX_N][20];
pii maxValue[MAX_N][20];
void getTree(int here, int parent, int cost) {
    height[here] = height[parent] + 1;
    ances[here][0] = parent;
    maxValue[here][0].first = cost;
    maxValue[here][0].second = -INF;

    for (int i = 1; i < 20; ++i) {
        ances[here][i] = ances[ances[here][i - 1]][i - 1];
        maxValue[here][i].first = max(maxValue[here][i - 1].first, maxValue[ances[here][i - 1]][i - 1].first);
        maxValue[here][i].second = max({
            maxValue[here][i - 1].first == maxValue[here][i].first ? -INF : maxValue[here][i - 1].first, 
            maxValue[ances[here][i - 1]][i - 1].first == maxValue[here][i].first ? -INF : maxValue[ances[here][i - 1]][i - 1].first,
            maxValue[here][i - 1].second == maxValue[here][i].first ? -INF : maxValue[here][i - 1].second, 
            maxValue[ances[here][i - 1]][i - 1].second == maxValue[here][i].first ? -INF : maxValue[ances[here][i - 1]][i - 1].second
        });
    }

    for (auto& next : adj[here])
        if (next.first != parent)
            getTree(next.first, here, next.second);
}

int getMax(int u, int v, int except) {
    int ret = -INF;
    if (height[u] != height[v]) {
        if (height[u] < height[v])
            swap(u, v);

        for (int i = 19; i >= 0; --i) 
            if (ances[u][i] && height[ances[u][i]] >= height[v]) {
                if (maxValue[u][i].first != except)
                    ret = max(ret, maxValue[u][i].first);
                else
                    ret = max(ret, maxValue[u][i].second);
                u = ances[u][i];
            }
    }
    if (u == v)
        return ret;
    for (int i = 19; i >= 0; --i)
        if(ances[u][i] != ances[v][i]) {
            if (maxValue[u][i].first != except)
                ret = max(ret, maxValue[u][i].first);
            else
                ret = max(ret, maxValue[u][i].second);
            if (maxValue[v][i].first != except)
                ret = max(ret, maxValue[v][i].first);
            else
                ret = max(ret, maxValue[v][i].second);
            u = ances[u][i];
            v = ances[v][i];
        }
    if (maxValue[u][0].first != except)
        ret = max(ret, maxValue[u][0].first);
    else
        ret = max(ret, maxValue[u][0].second);
    if (maxValue[v][0].first != except)
        ret = max(ret, maxValue[v][0].first);
    else
        ret = max(ret, maxValue[v][0].second);
    
    return ret;
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
 
    cin >> v >> e;
    edges.reserve(e);
    for (int i = 0; i <= v; ++i)
        parent[i] = i;
    while(e--) {
        int f, t, cost;
        cin >> f >> t >> cost;
        edges.emplace_back(cost, pii{f, t});
    }

    sort(edges.begin(), edges.end());

    ll result = 0;
    int index = 0;
    int edgeCnt = 0;
    for (auto& e : edges) {
        if (find(e.second.first) == find(e.second.second)) {
            ++index;
            continue;
        }
        merge(e.second.first, e.second.second);
        adj[e.second.first].emplace_back(e.second.second, e.first);
        adj[e.second.second].emplace_back(e.second.first, e.first);
        result += e.first;

        isIn[index++] = true;
        ++edgeCnt;
    }

    if (edgeCnt < v - 1 || e == v - 1) {
        cout << -1 << endl;
        return 0;
    }
    /* 
        SpanningTree 완성,
        각 edge를 돌면서 이 edge를 추가하고, lca까지의 edge들 중 가장 큰 edge를 삭제 했을 때 변하는 diff가 최소인 간선이 second mst
     */

    getTree(1, 0, 0);

    index = 0;
    int minDiff = INF;
    for (auto& e : edges) {
        if (isIn[index++])
            continue;
        
        //cout << pii(e.first, getMax(e.second.first, e.second.second, e.first)) << endl;
        int diff = e.first - getMax(e.second.first, e.second.second, e.first);
        if (diff)
            minDiff = min(minDiff, diff);
    }

    if (minDiff == INF) 
        cout << -1 << endl;
    else
        cout << result + minDiff << endl;
 
	return 0;
}