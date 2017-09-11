#include <cstdio>
#include <vector>

#define INF 987654321
#define MAXSIZE 100
using namespace std;


vector<int> dp;

int get(int toGet){
    if(dp[toGet] != INF){
        return dp[toGet];
    }

    int tmp;
    if(toGet % 3 == 0){
        tmp = get(toGet / 3);
        dp[toGet] = dp[toGet] > (tmp + 1) ? (tmp + 1) : dp[toGet];
    }
    if(toGet % 2 == 0){
        tmp = get(toGet / 2);
        dp[toGet] = dp[toGet] > (tmp + 1) ? (tmp + 1) : dp[toGet];
    }
    tmp = get(toGet - 1);
    dp[toGet] = dp[toGet] > (tmp + 1) ? (tmp + 1) : dp[toGet];
    return dp[toGet];
}

int main() {
    int n;
    scanf("%d", &n);
    dp.resize(n + 1, INF);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    get(n);
    printf("%d\n", dp[n]);

    return 0;
}
