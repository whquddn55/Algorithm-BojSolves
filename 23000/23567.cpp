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
#define MAX_N 10'005
#define MOD 1'000'000'007

int n, k;
int arr[MAX_N];
int outer[MAX_N];
int cntOfOuter = 0;
int inner[MAX_N] = {0, };
int cntOfInner = 0;
int ans = INF;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        --arr[i];
        outer[arr[i]]++;
        if (outer[arr[i]] == 1)
            cntOfOuter++;
    }

    int s = 0;

    for (int e = 0; e < n; ++e) {
        inner[arr[e]]++;
        if (inner[arr[e]] == 1)
            ++cntOfInner;
        outer[arr[e]]--;
        if (outer[arr[e]] == 0)
            --cntOfOuter;
        while(s <= e) {
            if (cntOfInner == k) {
                if (cntOfOuter == k)
                    ans = min(ans, e - s + 1);
                inner[arr[s]]--;
                if (inner[arr[s]] == 0)
                    --cntOfInner;
                outer[arr[s]]++;
                if (outer[arr[s]] == 1)
                    ++cntOfOuter;
                ++s;
            }
            else
                break;
        }
    }
    
    cout << (ans == INF ? 0 : ans) << endl;
    
    return 0;
}
