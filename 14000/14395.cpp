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
#define MAX_N 1505
#define MOD 1'000'000'007

int s, t;
map<ll, pii> visited;
queue<ll> q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> t;
    q.emplace(s);
    visited[s] = pll(s, s);

    if (s == t) {
        cout << 0 << endl;
        return 0;
    }

    bool flag = false;
    while(q.size()) {
        ll here = q.front();
        q.pop();

        if (here == t){
            flag = true;
            break;
        }

        if (visited.find(here * here) == visited.end()){
            q.emplace(here * here);
            visited[here * here] = pll(here, '*');
        }
        if (visited.find(here + here) == visited.end()){
            q.emplace(here + here);
            visited[here + here] = pll(here, '+');
        }
        if (visited.find(here - here) == visited.end()){
            q.emplace(here - here);
            visited[here - here] = pll(here, '-');
        }
        if (here != 0 && visited.find(here / here) == visited.end()){
            q.emplace(here / here);
            visited[here / here] = pll(here, '/');
        }
    }
    if (flag) {
        stack<char> st;
        while(t != s) {
            st.emplace(visited[t].second);
            t = visited[t].first;
        }
        while(st.size()) {
            cout << st.top();
            st.pop();
        }
    }
    else {
        cout << -1<< endl;
    }
    return 0;
}
