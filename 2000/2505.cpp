#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<int> arr;
vector<int> copyarr;

bool complete() {
	for (int i = 1; i <= n; i++)
		if (arr[i] != i) 
			return false;
	return true;
}

int main() {
	scanf("%d", &n);
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	copyarr = arr;

	int cnt = 0;
	vector<pii> ret;
	int start, end;
	for (int i = 1; i <= n; i++) {
		if (arr[i] != i) {
			start = i;
			for (int j = i + 1; j <= n; j++)
				if (arr[j] == i) {
					end = j;
					reverse(arr.begin() + start, arr.begin() + end + 1);
					cnt++;
					ret.emplace_back(start, end);
					break;
				}
		}
		if (cnt > 2)
			break;
		if (complete()) {
			if (cnt == 0)
				printf("1 1\n1 1\n");
			else if (cnt == 1)
				printf("%d %d\n1 1\n", ret[0].first, ret[0].second);
			else if (cnt == 2)
				printf("%d %d\n%d %d\n", ret[0].first, ret[0].second, ret[1].first, ret[1].second);
			return 0;
		}
	}

	arr = copyarr;
	cnt = 0;
	ret.clear();
	for (int i = n; i >= 1; i--) {
		if (arr[i] != i) {
			end = i;
			for (int j = i - 1; j >= 1; j--)
				if (arr[j] == i) {
					start = j;
					reverse(arr.begin() + start, arr.begin() + end + 1);
					cnt++;
					ret.emplace_back(start, end);
					break;
				}
		}
		if (cnt > 2)
			break;
		if (complete()) {
			if (cnt == 0)
				printf("1 1\n1 1\n");
			else if (cnt == 1)
				printf("%d %d\n1 1\n", ret[0].first, ret[0].second);
			else if (cnt == 2)
				printf("%d %d\n%d %d\n", ret[0].first, ret[0].second, ret[1].first, ret[1].second);
			return 0;
		}
	}
	

	return 0;
}