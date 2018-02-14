#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int temp;
		scanf("%d", &temp);
		sum += temp;
	}
	printf("%d\n", sum);

	return 0;
}