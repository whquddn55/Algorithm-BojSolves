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

int n, m, k;
int a, b;
bool picked[MAX_N * 4];
vector<int> arr;
bool visited[MAX_N * 4];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        picked[a] = picked[b] = true;
    }
    cin >> a >> b;
    picked[a] = picked[b] = true;

    int score = abs(a % k - b % k);
    for (int i = 1; i <= 4 * n; ++i)
        if (!picked[i]) 
            arr.emplace_back(i);

    sort(all(arr), [](int a, int b) {
        return a % k < b % k;
    });

    int p = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        while((p < arr.size()) && (arr[p] % k <= arr[i] % k + score))
            ++p;
        if (p == arr.size())
            break;

        ++ans;
        ++p;
    }
    cout << min(ans, m - 1) << endl;

    return 0;
}
