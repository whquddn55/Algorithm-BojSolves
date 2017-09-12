#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;
vector<int> coin;
vector<int> dp;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    coin.resize(n);
    dp.resize(k + 1, 0);

    for(int i = 0 ; i < n; i++){
        scanf("%d", &coin[i]);
    }

    sort(coin.begin(), coin.end());

    dp[0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = coin[i]; j <= k; j++){
            dp[j] += dp[j - coin[i]];
        }
    }
    printf("%d\n", dp[k]);

    return 0;
}
