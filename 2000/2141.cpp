#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<pii> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) 
		cin >> arr[i].first >> arr[i].second;
	
	sort(arr.begin(), arr.end());

	ll left = 0;
	ll right = 0;
	for (int i = 0; i < n; i++)
		right += arr[i].second;

	for (int i = 0; i < n; i++) {
		left += arr[i].second;
		right -= arr[i].second;

		if (left >= right) {
			cout << arr[i].first << '\n';
			break;
		}
	}

	return 0;
}
