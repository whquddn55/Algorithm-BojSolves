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
#define MAX_N 55
#define MOD 1'000'000'007

int n, m;
queue<int> q;
bool visited[MAX_N];
vector<int> party[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    int t;
    cin >> t;
    while (t--) {
        int temp;
        cin >> temp;
        q.emplace(temp);
        visited[temp] = true;
    }

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        while(t--) {
            int temp;
            cin >>temp;
            party[i].emplace_back(temp);
        }
    }

    while(q.size()) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < m; ++i) {
            bool flag = false;
            for (auto e : party[i]) {
                if (e == here) {
                    flag = true;
                }
            }
            if (flag) {
                for (auto e : party[i]) {
                    if (!visited[e]) {
                        q.emplace(e);
                        visited[e] = true;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        bool flag = true;
        for (auto e : party[i]) {
            if (visited[e])
                flag = false;
        }
        ans += flag;
    }
    cout << ans << endl;

    return 0;
}
