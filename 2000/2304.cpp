#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> arr;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr.begin(), arr.end());

	int result = 0;
	int i = 0;
	while(true) {
		int hereX = arr[i].first;
		int hereY = arr[i].second;

		bool check1 = false;
		for (int j = i + 1; j < n; j++) 
			if (arr[j].second > hereY) {
				result += (arr[j].first - hereX) * hereY;
				i = j;
				check1 = true;
				break;
			}
		if (check1) 
			continue;

		int x = 1;
		for (int j = i + 1; j < n; j++) 
			if (arr[j].second == hereY) 
				x = arr[j].first - hereX + 1;

		int maxValue = 0;
		int idx;
		for (int j = n - 1; j >= i + 1; j--) 
			if (maxValue < arr[j].second) {
				maxValue = arr[j].second;
				idx = j;
			}
		
		if (maxValue != 0) {
			result += x * hereY + (arr[idx].first - (hereX + x)) * arr[idx].second;
			i = idx;
			continue;
		}

		result += x * hereY;
		break;
	}
	printf("%d\n", result);

	return 0;
}