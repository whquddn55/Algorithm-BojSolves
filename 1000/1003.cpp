#include <bits/stdc++.h>
using namespace std;

pair<int, int> dp[41];

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;

    dp[0].first = 1;
    dp[0].second = 0;
    dp[1].first = 0;
    dp[1].second = 1;

    for (int i = 2; i < 41; i++) {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }

    while (tc--) {
        int n;
        cin >> n;

        cout << dp[n].first << ' ' << dp[n].second << endl;
    }


    return 0;
}
