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

#define all(x) (x).begin(), (x).end()
#define INF (INT_MAX / 2)
#define MAX_N 1000005

int k, n;
bool isPrime[MAX_N];
vector<int> primes;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin >> k >> n;
    fill(isPrime, isPrime + MAX_N, true);
    for (int i = 2; i < sqrt(MAX_N); ++i)
        if (isPrime[i]) {
            for (int j = i * 2; j < MAX_N; j += i)
                isPrime[j] = false;
        }
    for (int i = 2000; i < MAX_N; ++i)
        if (isPrime[i])
            primes.push_back(i);
    
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << primes[i] * j << ' ';
        cout << endl;
    }

    
    return 0;
}
