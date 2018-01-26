#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

int n;
vector<int> arr;
vector<int> pos;
vector<int> dp;
vector<int> previous;

int get(int here) {
	if (here == n)
		return 0;

	int& ret = dp[here];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = here + 1; i < n; i++) {
		if (pos[arr[i]] > pos[arr[here]]) {
			int value = get(i) + 1;
			if (ret < value) {
				ret = value;
				previous[here] = i;
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	arr.resize(n + 1);
	pos.resize(n + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	pos.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		pos[temp] = i;
	}

	dp.resize(n, -1);
	previous.resize(n);
	for (int i = 0; i < n; i++)
		previous[i] = i;

	int num = 0;
	int start = 0;
	for (int i = 0; i < n; i++) {
		int value = get(i);
		if (num < value) {
			num = value;
			start = i;
		}
	}
	
	int here = start;
	vector<int> result;
	while (true) {
		result.push_back(arr[here]);
		if (previous[here] == here)
			break;
		here = previous[here];
	}

	sort(result.begin(), result.end());
	printf("%d\n", num);
	for (int i = 0; i < num; i++)
		printf("%d ", result[i]);
	printf("\n");

	return 0;
}