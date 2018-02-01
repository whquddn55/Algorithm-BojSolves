#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;

int main() {
	scanf("%d", &n);
	int a = (n + 6) % 10;
	char b = 'A' + (n + 8) % 12;

	printf("%c%d\n", b, a);

	return 0;
}