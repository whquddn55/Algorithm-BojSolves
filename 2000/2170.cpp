#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n;
vector<pii> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		if (arr[i].first > arr[i].second)
			swap(arr[i].first, arr[i].second);
	}
	sort(arr.begin(), arr.end());

	int ans = 0;
	int left = INT_MIN, right = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (right < arr[i].first) {
			ans += right - left;
			left = arr[i].first;
			right = arr[i].second;
		}
		else
			right = max(right, arr[i].second);
	}
	
	cout << ans + (right - left) << endl;

	return 0;
}
