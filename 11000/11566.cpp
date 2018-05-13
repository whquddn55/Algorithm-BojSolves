#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_M 1001

int n, m;
int arr1[MAX_M];
int arr2[MAX_M];

int ans1 = -1, ans2 = -1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> arr2[i];

	for (int i = 1; i <= m / (n - 1); i++) {
		bool check = false;
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if ((j + k * i) >= m)
					break;
				if (arr2[j + k * i] != arr1[k]) 
					break;
				if (k == n - 1)
					check = true;
			}
		}
		if (check) {
			if (ans1 == -1)
				ans1 = i;
			ans2 = i;
		}
	}

	if (ans1 == -1)
		cout << -1 << endl;
	else
		cout << ans1 - 1 << ' ' << ans2 - 1 << endl;
	
	
	return 0;
}