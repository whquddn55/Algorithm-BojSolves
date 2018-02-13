#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> arr(3);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 3; i++) 
		scanf("%d %d", &arr[i].first, &arr[i].second);

	for (int i = 0; i <= arr[0].first; i++) {
		int x = i;
		int ax = arr[0].first - x;
		int y = n - arr[2].first - arr[2].second - x;
		int by = arr[1].first - y;
		int z = arr[0].second - y;
		int cz = arr[2].first - z;

		if ((x >= 0) && (y >= 0) && (z >= 0) &&
			(ax >= 0) && (by >= 0) && (cz >= 0)) {
			printf("1\n");
			printf("%d %d\n", x, ax);
			printf("%d %d\n", y, by);
			printf("%d %d\n", z, cz);
			return 0;
		}
	}
	printf("0\n");
	
	return 0;
}