#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 11

int dp[MAXSIZE]; // 숫자 i를 1,2,3의 조합으로 나타내는 방법의
int n;

int get(int number) {
    // base case
    if (number == 1)
        return 1;
    if (number == 2)
        return 2;
    if (number == 3)
        return 4;

    int& ret = dp[number];
    if (ret != -1) return ret;
    return ret = get(number - 1) + get(number - 2) + get(number - 3);
}

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;

    memset(dp, -1, sizeof(dp));
    while (tc--) {
        cin >> n;

        cout << get(n) << endl;
    }

    return 0;
}
