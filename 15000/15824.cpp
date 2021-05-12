#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define INF (INT_MAX / 2)

#define MAX_N 300005
#define MOD 1000000007

int n;
int arr[MAX_N];

ll power(ll a, int b) {
    ll result = 1;
    while(b) {
        if (b % 2) {
            result *= a;
            result %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    
    ll prv = 0, sum = 0;
    for (int i = 1; i < n; ++i) {
        prv = (prv * 2 + ((arr[i] - arr[i - 1]) * (power(2, i) - 1)) % MOD) % MOD;
        sum = (sum + prv) % MOD;
    }
    cout << sum << endl; 
    
	return 0;
}
