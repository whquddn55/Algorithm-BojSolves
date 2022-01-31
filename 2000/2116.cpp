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
#define MAX_N 10005
#define MOD 1'000'000'007

int n;
int arr[MAX_N][6];

int p[6] = {5, 3, 4, 1, 2, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < 6; ++i) {
        int skip = arr[0][i];
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            int skipIndex = -1;
            for (int k = 0; k < 6; ++k) {
                if (arr[j][k] == skip) {
                    skipIndex = k;
                    break;
                }
            }
            int maxV = 0;
            for (int k = 0; k < 6; ++k) {
                if (k == skipIndex || k == p[skipIndex])
                    continue;
                maxV = max(maxV, arr[j][k]);
            }
            skip = arr[j][p[skipIndex]];
            sum += maxV;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    
    return 0;
}
