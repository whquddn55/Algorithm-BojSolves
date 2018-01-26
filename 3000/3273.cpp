#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

vector<int> arr;
int n, x;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &x);

	sort(arr.begin(), arr.end());

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(arr.begin(), arr.end(), x - arr[i]) - arr.begin();
		if (arr[i] + arr[idx] == x)
			cnt++;
	}
	printf("%d\n", cnt / 2);

	return 0;
}