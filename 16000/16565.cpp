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
#define MAX_N 53
#define MOD 10007

int n;
int nCr[49][49];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    for (int i = 0; i < 49; ++i)
        nCr[i][0] = 1;
    for (int i = 1; i < 49; ++i)
        for (int j = 1; j <= i; ++j) 
            nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
    
    cin >> n;
    int a = n / 4;
    int result = 0;
    for (int i = 1; i <= a; ++i) {
        result = (result + ((i % 2 ? 1 : -1) * (nCr[13][i] * nCr[52 - 4 * i][n - 4 * i])) % MOD + MOD) % MOD;
    }

    cout << result << endl;

	return 0;
}
