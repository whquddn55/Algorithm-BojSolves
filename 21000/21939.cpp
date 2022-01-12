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
#define MAX_N 100'005
#define MOD 1'000'000'007

int n, m;
set<pii> arr;
int difficulty[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        arr.emplace(b, a);
        difficulty[a] = b;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (s == "recommend") {
            int a;
            cin >> a;
            if (a == 1)
                cout << arr.rbegin()->second << endl;
            else
                cout << arr.begin()->second << endl;
        }
        else if (s == "add") {
            int a, b;
            cin >> a >> b;
            arr.emplace(b, a);
            difficulty[a] = b;
        }
        else {
            int a;
            cin >> a;
            arr.erase(pii(difficulty[a], a));
        }
    }

    return 0;
}
