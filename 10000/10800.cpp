#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pair<pii, int> > arr;
vector<ll> sumOfColor;
vector<int> pos;
vector<ll> result;

bool comp(const pair<pii, int>& a, const pair<pii, int>& b) {
	return a.first.first > b.first.first;
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	sumOfColor.resize(n + 1, 0);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first.second, &arr[i].first.first);
		arr[i].second = i;
		sumOfColor[arr[i].first.second] += arr[i].first.first;
		sum += arr[i].first.first;
	}
	sort(arr.begin(), arr.end(), greater<pair<pii, int> >() );

	pos.resize(n);
	for (int i = 0; i < n; i++) 
		pos[arr[i].second] = i;
	
	result.resize(n, 0);
	for (int i = 0; i < n; i++) {
		int idx = upper_bound(arr.begin(), arr.end(), pair<pii, int>(pii(arr[i].first.first, n + 2), n), comp) - arr.begin(); // pair<pii,int>(pii(arr[i].first.first,0),0)
		int temp = 0;
		for (int j = i + 1; j < idx; j++) {
			if (arr[j].first.second == arr[i].first.second)
				continue;
			temp += arr[j].first.first;
		}
		result[i] = sum - sumOfColor[arr[i].first.second] - temp;
		sumOfColor[arr[i].first.second] -= arr[i].first.first;
		sum -= arr[i].first.first;
	}

	for (int i = 0; i < n; i++) {
		printf("%lld\n", result[pos[i]]);
	}

	return 0;
}