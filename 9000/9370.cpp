#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 2005
#define MOD 1'000'000'007

int n, m, t;
int s, g, h;
vector<pii> adj[MAX_N];

int dist[MAX_N];
bool inQ[MAX_N];
void spfa(int start) {
    fill_n(dist, MAX_N, INF);
    queue<int> q;
    q.emplace(start);
    inQ[start] = true;
    dist[start] = 0;

    while(q.size()) {
        int here = q.front();
        q.pop();
        inQ[here] = false;

        for (pii edge : adj[here]) {
            int nxt = edge.first;
            int cost = edge.second;
            if (dist[nxt] > dist[here] + cost) {
                dist[nxt] = dist[here] + cost;
                if (!inQ[nxt]) {
                    q.emplace(nxt);
                    inQ[nxt] = true;
                }
            }
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
        for (int i = 0; i < MAX_N; ++i)
            adj[i].clear();

        cin >> n >> m >> t;
        cin >> s >> g >> h;
        int gdDist = 0;
        while (m--) {
            int f, t, c;
            cin >> f >> t >> c;
            adj[f].emplace_back(t, c); 
            adj[t].emplace_back(f, c); 
            if ((f == g && t == h) || (f == h && t == g))
                gdDist = c;
        }

        spfa(s);
        int sDist[MAX_N];
        for (int i = 0; i < MAX_N; ++i)
            sDist[i] = dist[i];
        
        spfa(g);
        int gDist[MAX_N];
        for (int i = 0; i < MAX_N; ++i)
            gDist[i] = dist[i];

        spfa(h);
        int hDist[MAX_N];
        for (int i = 0; i < MAX_N; ++i)
            hDist[i] = dist[i];

        vector<int> ans;
        for (int i = 0; i < t; ++i) {
            int to;
            cin >> to;
            if ((sDist[to] == sDist[g] + gdDist + hDist[to]) || (sDist[to] == sDist[h] + gdDist + gDist[to]))
                ans.emplace_back(to);
        }
        sort(all(ans));
        for (auto e : ans)
            cout << e <<  ' ';
        cout << endl;
             
    }
    
    return 0;
}
