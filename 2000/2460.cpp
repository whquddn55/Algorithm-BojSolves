#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> arr(10);

int main() {
	for (int i = 0; i < 10; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);

	int result = arr[0].second;
	int num = result;
	for (int i = 1; i < 10; i++) {
		num -= arr[i].first;
		num += arr[i].second;
		result = max(result, num);
	}

	printf("%d\n", result);

	return 0;
}