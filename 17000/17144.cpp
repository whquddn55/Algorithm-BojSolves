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

int n, m, t;
int arr[MAX_N][MAX_N];
int air;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void a() {
    int temp[MAX_N][MAX_N] = {0, };
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny >= n || ny < 0 || nx >= m || nx < 0)
                    continue;
                if (arr[ny][nx] == -1)
                    continue;
                temp[ny][nx] += arr[i][j] / 5;
                temp[i][j] -= arr[i][j] / 5;
            }
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            arr[i][j] += temp[i][j];
}

void b() {
    // upper;
    int pos = air - 1;
    // first column
    for (int i = pos - 1; i >= 1; --i)
        arr[i][0] = arr[i - 1][0];
    // first row
    for (int i = 0; i < m - 1; ++i)
        arr[0][i] = arr[0][i + 1];
    // last column
    for (int i = 0; i < air - 1; ++i)
        arr[i][m - 1] = arr[i + 1][m - 1];
    // same row
    for (int i = m - 1; i >= 2; --i)
        arr[pos][i] = arr[pos][i - 1];
    arr[pos][1] = 0;

    pos = air;
    for (int i = pos + 1; i < n - 1; ++i)
        arr[i][0] = arr[i + 1][0];
    for (int i = 0; i < m - 1; ++i)
        arr[n - 1][i] = arr[n - 1][i + 1];
    for (int i = n - 1; i >= pos + 1; --i)
        arr[i][m - 1] = arr[i - 1][m - 1];
    for (int i = m - 1; i >= 2; --i)
        arr[pos][i] = arr[pos][i - 1];
    arr[pos][1] = 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == -1)
                air = i;
        }

    while(t--) {
        a();
        b();
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans += arr[i][j];
    cout << ans + 2 << endl;
    
    return 0;
}
