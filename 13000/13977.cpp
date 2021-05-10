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
#define MAX_N 4000005
#define MOD 1000000007

int m;
int fact[MAX_N];
int fact2[MAX_N];

int power(ll a, int b) {
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

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 4000000; ++i) {
        fact[i] = ((ll)fact[i - 1] * i) % MOD;
    }

    fact2[0] = 1;
    for (int i = 1; i <= 4000000; ++i)
        fact2[i] = power(fact[i], MOD - 2);
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int n, r;
        cin >> n >> r;
        cout << ((ll)fact[n] * (((ll)fact2[r] * fact2[n - r]) % MOD)) % MOD << endl;
    }
    
	return 0;
}
