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

#define all(x) (x.begin(), x.end())
#define INF (INT_MAX / 2)
#define MAX_N 105
#define MOD 1'000'000'007

#define MAX_V 505
struct MaximalFlow { // MaximalFlow.maxFlow(sink, source)
    struct Edge { // Edge 설정 (Edge 도착점, Edge의 용량, 맞Edge의 번호)
        int to, capacity, flow, reverse;
        Edge(int to, int capacity, int reverse)
            :to(to), capacity(capacity), flow(0), reverse(reverse) {}
    };

    vector<Edge> graph[MAX_V]; // vertex의 각 Edge를 보관하는 vector
    int level[MAX_V]; // vertex의 level 보관
    int iter[MAX_V]; // 각 vertex의 Edge 방문개수 보관

    void bfs(int s) {
        fill(level, level + MAX_V, -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (Edge& e : graph[v]) {
                if (e.capacity - e.flow > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }
    int dfs(int v, int t, int f) {
        if (v == t)
            return f;
        for (int& i = iter[v]; i < graph[v].size(); i++) {
            Edge& e = graph[v][i];
            if (e.capacity - e.flow > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.capacity - e.flow));
                if (d > 0) {
                    e.flow += d;
                    graph[e.to][e.reverse].flow -= d;
                    return d;
                }
            }
        }

        return 0;
    }
    int maxFlow(int s, int t) {
        int flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0)
                return flow;
            fill(iter, iter + MAX_V, 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0)
                flow += f;
        }
        return flow;
    }
    void addEdge(int from, int to, int capacity) {
        graph[from].emplace_back(to, capacity, graph[to].size());
        graph[to].emplace_back(from, 0, graph[from].size() - 1);
    }
};

vector<pair<string, string>> cat, dog;
MaximalFlow mf;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cat.clear();
        dog.clear();
        for (int i = 0; i < MAX_V; ++i) {
            mf.graph[i].clear();
        }
        
        int c, d, v;
        cin >> c >> d >> v;


        for (int i = 0; i < v; ++i) {
            string a, b;
            cin >> a >> b;
            
            if (a[0] == 'C')
                cat.emplace_back(a, b);
            else
                dog.emplace_back(a, b);
        }

        int source = 0;
        int leftStart = 1;
        int rightStart = leftStart + cat.size();
        int sink = rightStart + dog.size();

        for(int i = 0; i < cat.size(); ++i)
            mf.addEdge(source, leftStart + i, 1);
        for(int i = 0; i < dog.size(); ++i)
            mf.addEdge(rightStart + i, sink, 1);

        for(int i = 0; i < cat.size(); ++i)
            for (int j = 0; j < dog.size(); ++j) {
                if (cat[i].second == dog[j].first || cat[i].first == dog[j].second)
                    mf.addEdge(leftStart + i, rightStart + j, 1);
            }

        cout << v - mf.maxFlow(source, sink) << endl;
    }

    return 0;
}
