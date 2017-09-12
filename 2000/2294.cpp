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
    dp.resize(k + 1, INF);

    for(int i = 0 ; i < n; i++){
        scanf("%d", &coin[i]);
        if(coin[i] > k){
            continue;
        }
        dp[coin[i]] = 1;
    }

    sort(coin.begin(), coin.end());

    for(int i = coin[0]; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i - coin[j] >= 0){
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    printf("%d\n", dp[k] == INF ? -1 : dp[k]);

    return 0;
}
