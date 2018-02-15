#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i - 1; j++)
			printf(" ");
		for (int j = 0; j < (n - i) * 2 + 1; j++)
			printf("*");
		printf("\n");
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < (n - i) - 1; j++)
			printf(" ");
		for (int j = 0; j < i * 2 + 1; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}