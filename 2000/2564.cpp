#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int h, w;
int n;
int direction, diff;
vector<pii> arr;

int main() {
	scanf("%d %d", &w, &h);
	scanf("%d", &n);

	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);

	
	scanf("%d %d", &direction, &diff);

	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].first == 1 || arr[i].first == 2) {
			if (direction == 1 || direction == 2) {
				if (direction == arr[i].first)
					ret += abs(arr[i].second - diff);
				else
					ret += h + min(arr[i].second + diff, w * 2 - (arr[i].second + diff));
			}
			else {
				if (direction == 3)
					ret += arr[i].second;
				else
					ret += (w - arr[i].second);
				if (arr[i].first == 1)
					ret += diff;
				else
					ret += (h - diff);
			}
		}
		else {
			if (direction == 3 || direction == 4) {
				if (direction == arr[i].first)
					ret += abs(arr[i].second - diff);
				else
					ret += w + min(arr[i].second + diff, w * 2 - (arr[i].second + diff));
			}
			else {
				if (direction == 1)
					ret += arr[i].second;
				else
					ret += (h - arr[i].second);
				if (arr[i].first == 3)
					ret += diff;
				else
					ret += (w - diff);
			}
		}
	}
	printf("%d\n", ret);

	return 0;
}