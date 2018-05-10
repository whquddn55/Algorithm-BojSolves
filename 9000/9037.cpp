#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 11

int n;
int arr[MAX_N];
int temp[MAX_N];

bool check() {
	bool ret = true;
	int value = arr[0];
	for (int i = 0; i < n; i++)
		if (value != arr[i])
			ret = false;

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] % 2)
				arr[i]++;
		}

		int ans = 0;
		while(true) {
			if (check())
				break;

			for (int i = 0; i < n; i++) {
				arr[i] /= 2;
				temp[i] = arr[i];
			}

			arr[0] += arr[n - 1];
			for (int i = 1; i < n; i++)
				arr[i] += temp[i - 1];
			for (int i = 0; i < n; i++)
				if (arr[i] % 2)
					arr[i]++;
			ans++;
		}
		
		cout << ans << endl;
	}
	

	return 0;
}
