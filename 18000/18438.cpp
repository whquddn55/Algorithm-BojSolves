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

#define MAX_N 7005

string a, b;
int dpPrev[MAX_N];
int dp[MAX_N];
int fromPrev[MAX_N];
int from[MAX_N];
vector<char> result;

void getLcs(pii f, pii t) { 
    if (f.second == t.second) {
        for (int i = f.first; i <= t.first; ++i) {
            if (b[i - 1] == a[f.second - 1]) {
                result.push_back(a[f.second - 1]);
                a[f.second - 1] = 0;
                b[i - 1] = 1;
                break;
            }
        }
        return;

    }
    if (f.first == t.first) {
        for (int i = f.second; i <= t.second; ++i) {
            if (a[i - 1] == b[f.first - 1]) {
                result.push_back(a[i - 1]);
                a[i - 1] = 0;
                b[f.first - 1] = 1;
                break;
            }
        }
        return;
    } 
    if (t.second - f.second == 1) {
        int fIndex = INF;
        int sIndex = -1;
        for (int i = f.first; i <= t.first; ++i) {
            if (b[i - 1] == a[f.second - 1]) 
                fIndex = min(fIndex, i - 1);
            if (b[i - 1] == a[f.second]) 
                sIndex = max(sIndex, i - 1);
        }
        if (fIndex < sIndex) {
            result.push_back(a[f.second - 1]);
            result.push_back(a[f.second]);
            a[f.second - 1] = 0;
            b[fIndex] = 1;
            a[f.second] = 0;
            b[sIndex] = 1;
        }
        else if (fIndex != INF) {
            result.push_back(a[f.second - 1]);
            a[f.second - 1] = 0;
            b[fIndex] = 1;
        }
        else if (sIndex != -1) {
            result.push_back(a[f.second]);
            a[f.second] = 0;
            b[sIndex] = 1;
        }
        return;
    }
     if (t.first - f.first == 1) {
        int fIndex = INF;
        int sIndex = -1;
        for (int i = f.second; i <= t.second; ++i) {
            if (a[i - 1] == b[f.first - 1]) 
                fIndex = min(fIndex, i - 1);
            if (a[i - 1] == b[f.first]) 
                sIndex = max(sIndex, i - 1);
        }
        if (fIndex < sIndex) {
            result.push_back(a[fIndex]);
            result.push_back(a[sIndex]);
            a[fIndex] = 0;
            b[f.first - 1] = 1;
            a[sIndex] = 0;
            b[f.first] = 1;
        }
        else if (fIndex != INF) {
            result.push_back(a[fIndex]);
            a[fIndex] = 0;
            b[f.first - 1] = 1;
        }
        else if (sIndex != -1) {
            result.push_back(a[sIndex]);
            a[sIndex] = 0;
            b[f.first] = 1;
        }
        return;
    }

    int mid = (t.second + f.second) / 2;

    for (int i = f.first; i <= t.first; ++i)
        fromPrev[i] = i;
    memset(dp, 0 , sizeof(dp));
    memset(dpPrev, 0, sizeof(dpPrev));

    for (int i = f.second; i <= t.second; ++i) {
        for (int j = f.first; j <= t.first; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[j] = dpPrev[j - 1] + 1;
                if (i > mid) {
                    from[j] = fromPrev[j - 1];

                }
            }
            else if (j != f.first && dp[j - 1] >= dpPrev[j]) {
                dp[j] = dp[j - 1];
                if (i > mid)
                    from[j] = from[j - 1];
            }
            else {
                dp[j] = dpPrev[j];
                if (i > mid)
                    from[j] = fromPrev[j];
            }
        }

        for (int j = 1; j <= b.size(); ++j) {
            dpPrev[j] = dp[j];
            if (i > mid)
                fromPrev[j] = from[j];
        }

    }
    pii midRange = {from[t.first], mid};
    getLcs(f, midRange);
    getLcs(midRange, t);
}
 
int main() {
    ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    cin >> a >> b;
    
    getLcs({1, 1}, {b.size(), a.size()});

    cout << result.size() << endl;
    for (char c : result)   
        cout << c;

    return 0;
}