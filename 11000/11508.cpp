#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (LLONG_MAX)
#define endl '\n'

#define MAX_N 100001

int n;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, greater<int>());
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (i % 3 != 2)
			ans += arr[i];

	cout << ans << endl;

	return 0;
}
