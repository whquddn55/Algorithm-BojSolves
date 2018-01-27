#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

vector<pii> arr;

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		arr.clear();

		int n;
		scanf("%d", &n);
		arr.resize(n);

		for (int i = 0; i < n; i++)
			scanf("%d %d", &arr[i].first, &arr[i].second);
		sort(arr.begin(), arr.end());

		int minValue = arr[0].second;
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i].second < minValue) {
				minValue = arr[i].second;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}