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
#define MAX_N 200'005
#define MOD 1'000'000'007

int n, k;
int dist[MAX_N];
int prv[MAX_N];

int bfs() {
    fill_n(dist, MAX_N, INF);
    for (int i = 0; i < MAX_N; ++i)
        prv[i] = i;
    queue<int> q;
    q.emplace(n);
    dist[n] = 0;

    while (q.size()) {
        int here = q.front();
        q.pop();

        if (here == k)
            break;
        
        if (here == 0) {
            int nxt = here  + 1;
            if (dist[nxt] != INF) 
                continue;
            q.emplace(nxt);
            dist[nxt] = dist[here] + 1;
            prv[nxt] = here;
        }
        else if (here >= MAX_N / 2) {
            int d[] = {-1, 1};
            for (int i = 0; i < 2; ++i) {
                int nxt = min(MAX_N - 1, here + d[i]);
                if (dist[nxt] != INF) 
                    continue;
                q.emplace(nxt);
                dist[nxt] = dist[here] + 1;
                prv[nxt] = here;
            }
        } else {
            int d[] = {-1, 1, here};
            for (int i = 0; i < 3; ++i) {
                int nxt = here + d[i];
                if (dist[nxt] != INF) 
                    continue;
                q.emplace(nxt);
                dist[nxt] = dist[here] + 1;
                prv[nxt] = here;
            }
        }
    }
    return dist[k];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    cout << bfs() << endl;
    stack<int> ans;
    while(prv[k] != k) {
        ans.push(k);
        k = prv[k];
    }
    cout << n << ' ';
    while(ans.size()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}
