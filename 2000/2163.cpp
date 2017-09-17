#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d\n", (n - 1) + (m - 1) * n);

    return 0;
}
