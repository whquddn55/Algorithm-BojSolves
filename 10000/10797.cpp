#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

int main() {
	int n;
	scanf("%d", &n);

	int result = 0;
	for (int i = 0; i < 5; i++) {
		int carNumber;
		scanf("%d", &carNumber);
		if (carNumber == n)
			result++;
	}
	printf("%d\n", result);

	return 0;
}