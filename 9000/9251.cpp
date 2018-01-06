#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000

int dp[MAXSIZE][MAXSIZE]; // i문자와 j문자에서 시작하는 최장 공통 부분 수열의 크기
string s1, s2;

int lcs(int start1, int start2) {
    // base case
    if ((start1 == s1.size()) || (start2 == s2.size()))
        return 0;

    int& ret = dp[start1][start2];
    if (ret != -1) return ret;

    if (s1[start1] != s2[start2])
        return ret = max(lcs(start1 + 1, start2), lcs(start1, start2 + 1));

    return ret = lcs(start1 + 1, start2 + 1) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> s1 >> s2;

    memset(dp, -1, sizeof(dp));

    cout << lcs(0, 0) << endl;

    return 0;
}
