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
#define MAX_N 10005
#define MOD 1000000

int n, m;
int cnt;
int dfsn[MAX_N];
bool finished[MAX_N];
stack<int> st;
int sn[MAX_N];
vector<int> adj[MAX_N];
vector<vector<int>> scc;

int findScc(int here) {
    dfsn[here] = ++cnt;
    st.push(here);

    int result = dfsn[here];
    for (int i = 0; i < adj[here].size(); ++i) {
        int next = adj[here][i];

        if (dfsn[next] == 0)
            result = min(result, findScc(next));
        else if (!finished[next])
            result = min(result, dfsn[next]);
    }

    if (result == dfsn[here]) {
        vector<int> curScc;
        while (true) {
            int top = st.top();
            st.pop();
            curScc.push_back(top);
            finished[top] = true;
            sn[top] = scc.size();
            if (top == here)
                break;
        }
        scc.push_back(curScc);
    }

    return result;
}

int notOp(int value) {
    if (value > n)
        return value - n;
    else
        return value + n;
}

void findResult() {
    int result[MAX_N];
    memset(result, -1, sizeof(result));

    pii p[MAX_N];
    for (int i = 1; i <= n * 2; ++i)
        p[i] = pii(sn[i], i);
    sort(p + 1, p + n * 2 + 1);

    for (int i = n * 2; i >= 1;--i) {
        int var = p[i].second;
        if (result[var] == -1) {
            result[var] = 0;
            result[notOp(var)] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << (result[i] ? 'R' : 'B');
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    while(m--) {
        int v[3];
        char c[3];
        for (int i = 0; i < 3; ++i) {
            cin >> v[i] >> c[i];
            if (c[i] == 'B')
                v[i] = notOp(v[i]);
        }

        for (int i = 0; i < 3; ++i) {
            adj[notOp(v[i])].emplace_back(v[(i + 1) % 3]);
            adj[notOp(v[(i + 1) % 3])].emplace_back(v[i]);
        }
    }

    for (int i = 1; i <= n * 2; ++i) 
        if (dfsn[i] == 0)
            findScc(i);

    bool possible = true;
    for (int i = 1; i <= n; ++i) {
        if (sn[i] == sn[i + n])
            possible = false;
    }

    if (possible)
        findResult();
    else
        cout << -1;
    
    return 0;
}
