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
#define MAX_N 11
#define MOD 10007

int n;
int arr[3];
ll dp[101][101][101];
ll prv[101][101][101];
int fact[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    fact[0] = 1;
    for (int i = 1; i < MAX_N; ++i)
        fact[i] = fact[i - 1] * i;
    
    cin >> n;
    for (int i = 0; i < 3; ++i)
        cin >> arr[i];

    prv[arr[0]][arr[1]][arr[2]] = 1;

    ll result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int r = 0; r <= arr[0]; ++r) {
            for (int g = 0; g <= arr[1]; ++g) {
                for (int b = 0; b <= arr[2]; ++b) {
                    if (r + i <= arr[0])
                        dp[r][g][b] += prv[r + i][g][b];
                    if (g + i <= arr[1])
                        dp[r][g][b] += prv[r][g + i][b];
                    if (b + i <= arr[2])
                        dp[r][g][b] += prv[r][g][b + i];

                    if (i % 2 == 0) {
                        if (r + i / 2 <= arr[0] && g + i / 2 <= arr[1])
                            dp[r][g][b] += prv[r + i / 2][g + i / 2][b] * (fact[i] / fact[i / 2] / fact[i / 2]);
                        if (r + i / 2 <= arr[0] && b + i / 2 <= arr[2])
                            dp[r][g][b] += prv[r + i / 2][g][b + i / 2] * (fact[i] / fact[i / 2] / fact[i / 2]);
                        if (g + i / 2 <= arr[1] && b + i / 2 <= arr[2])
                            dp[r][g][b] += prv[r][g + i / 2][b + i / 2] * (fact[i] / fact[i / 2] / fact[i / 2]);
                    }
                    if (i % 3 == 0) {
                        if (r + i / 3 <= arr[0] && g + i / 3 <= arr[1] && b + i / 3 <= arr[2])
                            dp[r][g][b] += prv[r + i / 3][g + i / 3][b + i / 3] * (fact[i] / fact[i / 3] / fact[i / 3] / fact[i / 3]);
                    }

                    if (i == n)
                        result += dp[r][g][b];
                }
            }
        }
        for (int r = 0; r <= arr[0]; ++r) 
            for (int g = 0; g <= arr[1]; ++g) 
                for (int b = 0; b <= arr[2]; ++b) {
                    prv[r][g][b] = dp[r][g][b];
                    dp[r][g][b] = 0;
                }
    }

    cout << result << endl;

	return 0;
}