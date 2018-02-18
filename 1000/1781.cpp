#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<pii> arr;
set<int> times;

bool comp(const pii& a, const pii& b) {
	return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first);
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].second, &arr[i].first);
		times.insert(-(i + 1));
	}

	sort(arr.begin(), arr.end(), comp);

	int result = 0;
	for (int i = 0; i < n; i++) {
		auto it = times.lower_bound(-arr[i].second);
		if (it != times.end()) {
			result += arr[i].first;
			times.erase(it);
		}
	}

	printf("%d\n", result);

	return 0;
}