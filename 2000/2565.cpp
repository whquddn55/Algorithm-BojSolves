#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> arr;
vector<int> lis;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr.begin(), arr.end());

	lis.push_back(arr[0].second);
	for (int i = 1; i < n; i++) {
		if (lis[lis.size() - 1] < arr[i].second) 
			lis.push_back(arr[i].second);
		else {
			lis[lower_bound(lis.begin(), lis.end(), arr[i].second) - lis.begin()] = arr[i].second;
		}
	}

	printf("%d\n", n - lis.size());
	
	return 0;
}