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
#define MAX_N 105
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int n;
int arr[MAX_N];
int chk[200005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int arrIndex = 0;
    int to = arr[n - 1] + (n == 1 ? 0 : arr[n - 2]);
    for (int i = 1; i < to; ++i) {
        if (i == arr[arrIndex]) {
            chk[i] = 1;
            ++arrIndex;
        } else {
            int minValue = INF;
            for (int j = 0; j < arrIndex; ++j) {
                if (minValue > chk[i - arr[j]]) {
                    minValue = chk[i - arr[j]];
                    if (i - arr[j] < arr[arrIndex - 1]) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
            chk[i] = minValue + 1;
        }
    }

    

    cout << "Yes" << endl;
    
    return 0;
}