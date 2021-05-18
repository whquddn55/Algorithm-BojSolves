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
#define MAX_N 1000001
#define MOD 1000000007

int n, r;
ll fact[MAX_N];

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

    fact[0] = 1;
    for (int i = 1; i < MAX_N; ++i)
        fact[i] = (fact[i - 1] * i) % MOD;
    
    cin >> n >> r;

    cout << (fact[n] * power(((fact[r] * fact[n - r]) % MOD), MOD - 2)) % MOD << endl;

	return 0;
}
