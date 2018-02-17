#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

ull n;

bool decide(ull mid) {
	return (mid * mid) >= n;
}

ull binarySearch(ull minValue, ull maxValue) {
	ull left = minValue;
	ull right = maxValue;

	while (left <= right) {
		ull mid = (left + right) / 2;
		if (decide(mid)) 
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

int main() {
	scanf("%lld", &n);

	if (n == 0)
		printf("0\n");
	else
		printf("%lld\n", binarySearch(0, (ull)sqrt(n)));

	return 0;
}