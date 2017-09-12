#include <cstdio>
#include <vector>

#define INF 987654321
using namespace std;


vector<int> dp;

int main() {
    int n;
    scanf("%d", &n);

    dp.resize(n, 0);
    dp[0] = 1;
    dp[1] = 3;

    for(int i = 2; i < n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }

    printf("%d\n", dp[n - 1]);

    return 0;
}
