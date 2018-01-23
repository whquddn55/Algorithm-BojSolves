#include <bits/stdc++.h>
using namespace std;

int n, k, s;
vector<pair<int, int> > arr;

int main() {
	scanf("%d %d %d", &n, &k, &s);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr.begin(), arr.end());

	int result = 0;
	int cnt = 0;
	int firstVisited = arr[0].first;
	for (int i = 0; i < n && arr[i].first < s; i++) {
		if (cnt + arr[i].second > k) {
			arr[i].second -= (k - cnt);
			result += (s - firstVisited) * 2;
			cnt = 0;
			firstVisited = arr[i].first;
			i--;
		}
		else {
			cnt += arr[i].second;
			arr[i].second = 0;
		}
		if (i + 1 >= n || arr[i + 1].first >= s)
			result += abs(s - firstVisited) * 2;
	}

	firstVisited = arr[n - 1].first;
	cnt = 0;
	for (int i = n - 1; i >= 0 && arr[i].first > s; i--) {
		if (cnt + arr[i].second > k) {
			arr[i].second -= (k - cnt);
			result += (firstVisited - s) * 2;
			cnt = 0;
			firstVisited = arr[i].first;
			i++;
		}
		else {
			cnt += arr[i].second;
			arr[i].second = 0;
		}
		if (i - 1 < 0 || arr[i - 1].first <= s)
			result += abs(s - firstVisited) * 2;
	}

	printf("%d\n", result);

	return 0;
}