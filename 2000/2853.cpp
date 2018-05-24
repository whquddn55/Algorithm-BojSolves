#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 5001

int n;
int arr[MAX_N];
int ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 1; i < n; i++)
		arr[i] = arr[i] - arr[0];
	
	ans = n - 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] != -1)
			for (int j = i + 1; j < n; j++)
				if (arr[j] != -1 && arr[j] % arr[i] == 0) {
					arr[j] = -1;
					ans--;
				}
	}

	cout << ans << endl;

	return 0;
}