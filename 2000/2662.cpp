#include<cstdio>
int w, n, dp[301][21], fr[301][21], a[301][21];
void f(int x, int y) {
    if (!y) return;
    f(fr[x][y], y - 1);
    printf("%d ", x - fr[x][y]);
}
int main() {
    scanf("%d%d", &w, &n);
    for (int i = 1; i <= w; i++) {
        scanf("%*d");
        for (int j = 1; j <= n; j++) scanf("%d", a[i] + j);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = w; j; j--) {
            for (int k = 0; k <= j; k++) if (dp[j][i] < dp[j - k][i - 1] + a[k][i]) {
                dp[j][i] = dp[j - k][i - 1] + a[k][i];
                fr[j][i] = j - k;
            }
        }
    }
    printf("%d\n", dp[w][n]);
    f(w, n);
    return 0;
}