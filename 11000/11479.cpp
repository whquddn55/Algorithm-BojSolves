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
#define MAX_N 1000005
#define MOD 1'000'000'007

string str;
int sA[MAX_N]; // suffix array
int g[MAX_N]; // 현재 비교할 group
int sAReverse[MAX_N]; // suffix array의 inverse
int lcp[MAX_N]; // lcp

void getSA() {
    int t = 1;
    for (int i = 0; i < str.size(); i++) {
        sA[i] = i;
        g[i] = str[i] - 'a';
    }

    int tg[MAX_N]; // 다음에 비교할 group
    while (t <= str.size()) {
        g[str.size()] = -1;
        sort(sA, sA + str.size(), [&](int x, int y) {
            return g[x] == g[y] ? (g[x + t] < g[y + t]) : (g[x] < g[y]);
        });

        tg[sA[0]] = 0;
        for (int i = 1; i < str.size(); i++) {
            if (g[sA[i - 1]] == g[sA[i]] ? 
                (g[sA[i - 1] + t] < g[sA[i] + t]) : (g[sA[i - 1]] < g[sA[i]]))
                tg[sA[i]] = tg[sA[i - 1]] + 1;
            else
                tg[sA[i]] = tg[sA[i - 1]];
        }

        for (int i = 0; i < str.size(); i++)
            g[i] = tg[i];
        t *= 2;
    }
}

void getLcp() {
    for (int i = 0; i < str.size(); i++)
        sAReverse[sA[i]] = i;
    int len = 0;
    for (int i = 0; i < str.size(); i++) {
        int k = sAReverse[i];
        if (k) {
            int j = sA[k - 1];
            while (str[j + len] == str[i + len])
                len++;
            lcp[k] = len;
            if (len)
                len--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> str;
    getSA();
    getLcp();

    ll ans = str.size();
    ans *= str.size() + 1;
    ans /= 2;
    for (int i = 0; i < str.size(); ++i)
        ans -= lcp[i];
    cout << ans << endl;

    return 0;
}
