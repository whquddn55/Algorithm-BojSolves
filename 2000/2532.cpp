#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> arr;
vector<int> lis;

bool comp(const pii& a, const pii& b) {
	return (a.first == b.first) ? (a.second > b.second) : (a.first < b.first);
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d %d %d", &temp, &arr[i].first, &arr[i].second);
	}
	sort(arr.begin(), arr.end(), comp);

	lis.push_back(arr[0].second);
	for (int i = 1; i < n; i++) {
		if (arr[i].first == arr[i - 1].first && arr[i].second == arr[i - 1].second)
			continue;
		if (lis[lis.size() - 1] >= arr[i].second)
			lis.push_back(arr[i].second);
		else
			lis[(upper_bound(lis.begin(), lis.end(), arr[i].second, greater<int>()) - lis.begin())] = arr[i].second;
	}

	printf("%d\n", lis.size());
	
	

	return 0;
}