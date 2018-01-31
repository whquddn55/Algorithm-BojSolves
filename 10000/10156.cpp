#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, k, m;

int main() {
	scanf("%d %d %d", &n, &k, &m);

	printf("%d\n", ((n * k) > m) ? (n * k - m) : 0);
	return 0;
}