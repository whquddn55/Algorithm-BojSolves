#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;
vector<int> gap;

int euclid(int a, int b) {
	if (b == 0)
		return a;

	return euclid(b, a % b);
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	gap.resize(n - 1);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n - 1; i++)
		gap[i] = arr[i + 1] - arr[i];

	int interval = gap[0];
	for (int i = 1; i < n - 1; i++)
		interval = euclid(interval, gap[i]);

	int result = 0;
	for (int i = 0; i < n - 1; i++)
		result += gap[i] / interval - 1;

	printf("%d\n", result);

	return 0;
}