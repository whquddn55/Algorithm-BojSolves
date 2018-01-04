#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1001

int dp[MAXSIZE];

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 2]  + dp[i - 1]) % 10007;

    cout << dp[n] << endl;

    return 0;
}
