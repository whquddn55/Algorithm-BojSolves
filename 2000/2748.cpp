#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 91

long long dp[MAXSIZE];
int n;

long long fibo(int number) {
    // base case
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;

    long long& ret = dp[number];
    if (ret != -1) return ret;
    return ret = fibo(number - 1) + fibo(number - 2);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;

    memset(dp, -1, sizeof(dp));
    cout << fibo(n) << endl;

    return 0;
}
