#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pair<pii, int> > arr;
vector<int> result;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first.first, &arr[i].first.second);
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end());

	result.resize(n);
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = i + 1; j < n; j++) {
			if ((arr[i].first.second < arr[j].first.second) && (arr[i].first.first != arr[j].first.first))
				cnt++;
		}
		result[arr[i].second] = cnt;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");

	return 0;
}