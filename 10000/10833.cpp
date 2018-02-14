#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> arr;
int result = 0;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		result += arr[i].second % arr[i].first;
	}
	printf("%d\n", result);

	return 0;
}