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
#define MAX_N 100005
#define MOD 1'000'000'007

int getnth(ll here, int n) {
    return (here >> (n * 4)) & 0xf;
}

void setnth(ll& here, int n, ll v) {
    here &= ~(0xfLL << (n * 4));
    here |= (v << (n * 4));
}

ll rotate(ll here, int target, int cnt) {
    if (target < 4) {
        if (cnt == 1) {
            int temp = getnth(here, 12 + target);
            setnth(here, 12 + target, getnth(here, 8 + target));
            setnth(here, 8 + target, getnth(here, 4 + target));
            setnth(here, 4 + target, getnth(here, 0 + target));
            setnth(here, 0 + target, temp);
        }
        else if (cnt == 2) {
            int temp1 = getnth(here, 8 + target);
            int temp2 = getnth(here, 12 + target);
            setnth(here, 12 + target, getnth(here, 4 + target));
            setnth(here, 8 + target, getnth(here, 0 + target));
            setnth(here, 4 + target, temp2);
            setnth(here, 0 + target, temp1);
        }
        else if (cnt == 3) {
            int temp = getnth(here, 0 + target);
            setnth(here, 0 + target, getnth(here, 4 + target));
            setnth(here, 4 + target, getnth(here, 8 + target));
            setnth(here, 8 + target, getnth(here, 12 + target));
            setnth(here, 12 + target, temp);
        }
    }
    else {
        int offset = (target - 4) * 4;
        if (cnt == 1) {
            int temp = getnth(here, 3 + offset);
            setnth(here, 3 + offset, getnth(here, 2 + offset));
            setnth(here, 2 + offset, getnth(here, 1 + offset));
            setnth(here, 1 + offset, getnth(here, 0 + offset));
            setnth(here, 0 + offset, temp);
        }
        else if (cnt == 2) {
            int temp1 = getnth(here, 2 + offset);
            int temp2 = getnth(here, 3 + offset);
            setnth(here, 3 + offset, getnth(here, 1 + offset));
            setnth(here, 2 + offset, getnth(here, 0 + offset));
            setnth(here, 1 + offset, temp2);
            setnth(here, 0 + offset, temp1);
        }
        else if (cnt == 3) {
            int temp = getnth(here, 0 + offset);
            setnth(here, 0 + offset, getnth(here, 1 + offset));
            setnth(here, 1 + offset, getnth(here, 2 + offset));
            setnth(here, 2 + offset, getnth(here, 3 + offset));
            setnth(here, 3 + offset, temp);
        }
    }
    return here;
}

void print(ll here) {
    for (int i = 0; i < 4; ++i, cout << endl)
        for (int j = 0; j < 4; ++j) {
            int cnt = i * 4 + j;
            cout << getnth(here, cnt) + 1 << ' ';
        }
}

queue<pll> q;
unordered_map<ll, int> visited;
unordered_map<ll, pll> prv;
ll meet1;
ll meet2;
int mm;
void bfs(ll start) {
    q.emplace(start, 0);
    q.emplace(0xfedcba9876543210, 0);
    visited[start] = 0;
    visited[0xfedcba9876543210] = 1;
    prv[start] = {0, 0};
    prv[0xfedcba9876543210] = {0, 0};

    while(q.size()) {
        ll here = q.front().first;
        int cnt = q.front().second;
        int type = visited[here];
        q.pop();

        for (int i = 0; i < 8; ++i){
            for (int j = 1; j <= 3; ++j) {
                ll nxt = rotate(here, i, j);
                if (visited.find(nxt) != visited.end()) {
                    if (visited[nxt] != type) {
                        meet1 = here;
                        meet2 = nxt;
                        if (type == 0)
                            mm = (i << 2) | j;
                        else if (type == 1)
                            mm = (i << 2) | (4 - j);
                        return;
                    }
                    continue;
                }

                q.emplace(nxt, cnt + 1);
                visited.emplace(nxt, type);
                if (type == 0)
                    prv.emplace(nxt, pll(here, (i << 2) | j));
                else if (type == 1)
                    prv.emplace(nxt, pll(here, (i << 2) | (4 - j)));
            }
        }

    }
}

void backtrack() {
    ll here = visited[meet1] == 0 ? meet1 : meet2;
    pll t;
    deque<pair<int, pll>> st;
    while((t = prv[here]) != pll(0, 0)) {
        st.emplace_front(2 - (t.second >> 2) / 4, pll((t.second >> 2) % 4 + 1, (t.second & 0b11)));
        here = t.first;
    }

    st.emplace_back(2 - (mm >> 2) / 4, pll((mm >> 2) % 4 + 1, (mm & 0b11)));

    here = visited[meet1] == 0 ? meet2 : meet1;
    while((t = prv[here]) != pll(0, 0)) {
        st.emplace_back(2 - (t.second >> 2) / 4, pll((t.second >> 2) % 4 + 1, (t.second & 0b11)));
        here = t.first;
    }

    cout << st.size() << endl;
    for (auto e : st)
        cout << e << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll start = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            int n = i * 4 + j;
            int t;
            cin >> t;
            --t;
            setnth(start, n, t);
        }
    bfs(start);

    backtrack();

    return 0;
}
