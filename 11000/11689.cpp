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
#define MAX_N 300005
#define MOD 9901

ll n;
bool isPrime[1000005];
vector<int> primes;
vector<pll> arr;

ll power(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if (b % 2)
            ret *= a;
        a *= a;
        b /= 2;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;

    fill(isPrime, isPrime + 1000005, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 1000000; ++i) {
        if (isPrime[i]) {
            primes.emplace_back(i);
            for (int j = i * 2; j <= 1000000; j += i)
                isPrime[j] = false;
        }
    }

    for (int prime : primes) {
        if (n < prime)
            break;
        if (n % prime == 0) {
            int cnt = 0;
            while(n % prime == 0) {
                n /= prime;
                ++cnt;
            }
            arr.emplace_back(prime, cnt);
        }
    }

    if (n != 1)
        arr.emplace_back(n, 1);

    ll ans = 1;
    for (auto e : arr) 
        ans *= (power(e.first, e.second) - power(e.first, e.second - 1));
    cout << ans << endl;
    
    return 0;
}