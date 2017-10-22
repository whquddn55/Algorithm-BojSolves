#include <stdio.h>

int dp[1001], P[1001];
int sol(int n){
    int temp = 0;
    if(n==0) return 0;
    if(dp[n]>0) return dp[n];

    for(int i=1;i<=n;++i){
        temp = sol(n-i)+P[i];
        dp[n] = dp[n] < temp ? temp : dp[n];
    }

    return dp[n];
}
int main(void){
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;++i)
        scanf("%d", &P[i]);
    printf("%d", sol(N));

    return 0;
}
