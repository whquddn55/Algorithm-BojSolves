#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 500

int dp[MAXSIZE][MAXSIZE]; // (j,i)에서 길이의 최대
vector<vector<int> > triangle;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    triangle.resize(n);

    for (int i = 0; i < n; i++) {
        triangle[i].resize(n, 0);
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];

    }

    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++)
        dp[i][0] = triangle[i][0] + dp[i - 1][0];

    for (int i = 1; i < n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];

    int result = 0;
    for (int i = 0; i < n; i++)
        result = max(result, dp[n - 1][i]);

    cout << result << endl;

    return 0;
}
