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
#define MAX_N 500005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int idx[300];
int pi[MAX_N];

void getPi( const string& p) {
    pi[0] = 0;
    int start = 1, matched = 0;
    while(start + matched < p.size()) {
        if (matched < p.size() && p[start + matched] == p[matched]) {
            ++matched;
            pi[start + matched - 1] = matched;
        } else if (matched == 0) {
            ++start;
        } else {
            start += matched - pi[matched - 1];
            matched = pi[matched - 1];
        }
    }
}

int kmp(const string& t, const string& p) {
    getPi(p);
    int start = 0, matched = 0;

    int cnt = 0;
    while(start <= t.size() - p.size()) {
        if (matched < p.size() && t[start + matched] == p[matched]) {
            ++matched;
            if (matched == p.size()) {
                ++cnt;
            }
        } else if (matched == 0) {
            ++start;
        } else {
            start += matched - pi[matched - 1];
            matched = pi[matched - 1];
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
        memset(pi, 0, sizeof(pi));
        string a, w, s;
        cin >> a >> w >> s;

        for (int i = 0; i < a.size(); ++i) 
            idx[a[i]] = i;
        
        vector<int> ans;
        for (int i = 0; i < a.size(); ++i) {
            string t = s;
            for (int j = 0; j < t.size(); ++j) {
                t[j] = a[(idx[t[j]] - i + a.size()) % a.size()];
            }
            if (kmp(t, w) == 1)
                ans.emplace_back(i);
        }

        if (ans.size() == 0) {
            cout << "no solution" << endl;
        } else if (ans.size() == 1) {
            cout << "unique: " << ans[0] << endl;
        } else {
            cout << "ambiguous: ";
            for (auto e: ans)
                cout << e << ' ';
            cout << endl;
        }
    }
   

    return 0;
}
