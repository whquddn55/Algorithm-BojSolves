#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<long long> dp;

int main() {
    dp.resize(100);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i < 100; i++){
        dp[i] = dp[i - 3] + dp[i - 2];
    }

    int testcase;
    scanf("%d", &testcase);

    while(testcase--){
        int idx;
        scanf("%d", &idx);

        printf("%lld\n", dp[idx - 1]);
    }

    return 0;
}
