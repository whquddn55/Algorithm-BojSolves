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
#define MAX_N 4005
#define MOD 1000000007

int n, m;
vector<pii> adj[MAX_N];
ll distOfFox[MAX_N];
ll distOfWolf[MAX_N][2];

bool inQ[MAX_N];
queue<ll> q;
void spfaFox() {
    fill(distOfFox, distOfFox + MAX_N, (ll)INF * INF);
    distOfFox[1] = 0;
    q.emplace(1);
    inQ[1] = true;

    while(q.size()) {
        int here = q.front();
        q.pop();
        inQ[here] = false;

        for (auto& e : adj[here]) {
            int next = e.first;
            int nextCost = e.second;

            if (distOfFox[here] + nextCost < distOfFox[next]) {
                distOfFox[next] = distOfFox[here] + nextCost;
                if (!inQ[next]) {
                    q.emplace(next);
                    inQ[next] = true;
                }
            }
        }
    }
} 

bool inQ2[MAX_N][2];
queue<pll> q2;
void spfaWolf() {
    for (int i = 0; i < MAX_N; ++i)
        distOfWolf[i][0] = distOfWolf[i][1] = (ll)INF * INF;
    distOfWolf[1][1] = 0;
    q2.emplace(1, 1);
    inQ2[1][1] = true;

    while(q2.size()) {
        int here = q2.front().first;
        int hereStatus = q2.front().second;
        q2.pop();
        inQ2[here][hereStatus] = false;

        for (auto& e : adj[here]) {
            int next = e.first;
            int nextCost = e.second;

            if (distOfWolf[here][hereStatus] + nextCost * (hereStatus ? 0.5 : 2) < distOfWolf[next][!hereStatus]) {
                distOfWolf[next][!hereStatus] = distOfWolf[here][hereStatus] +  + nextCost * (hereStatus ? 0.5 : 2);
                if (!inQ2[next][!hereStatus]) {
                    q2.emplace(next, !hereStatus);
                    inQ2[next][!hereStatus] = true;
                }
            }
        }
    }
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    while(m--) {
        int f, t, c;
        cin >> f >> t >> c;
        adj[f].emplace_back(t, c * 2);
        adj[t].emplace_back(f, c * 2);
    }

    spfaFox();
    spfaWolf();
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (distOfFox[i] < min(distOfWolf[i][0], distOfWolf[i][1]))
            ++cnt;
    cout << cnt << endl;

    return 0;
}