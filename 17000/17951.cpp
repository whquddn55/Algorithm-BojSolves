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

#define MAX_N 100005

int n, k;
int arr[MAX_N];

bool decide(int mid) {
    int sum = 0;
    int used = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum > mid) {
            sum = 0;
            ++used;
        }
    }
    if (used >= k)
        return true;
    return false;
}

int parametric(int l, int r) {
    while (l < r) {
        int mid = (l + r) / 2;
        bool value = decide(mid);
        if (value)
            l = mid + 1;
        else
            r = mid;
    }
    
    return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << parametric(0, 20 * 100000) << endl;
    
	return 0;
}
