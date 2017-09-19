#include<stdio.h>
const int MAX_N = 1e5;
int t, n, ind[MAX_N + 1], nxt[MAX_N + 1], ck[MAX_N + 1];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int h, r = 0;
        for (int i = 1; i <= n; i++) ind[i] = ck[i] = 0;
        for (int i = 1; i <= n; i++) scanf("%d", nxt + i), ind[nxt[i]]++;
        for (int i = 1; i <= n; i++) {
            h = i;
            while (!ind[h] && !ck[h]) {
                ck[h] = 1;
                ind[nxt[h]]--;
                h = nxt[h];
                r++;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}