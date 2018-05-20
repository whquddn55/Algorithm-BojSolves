#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 1001

int n, m, here;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int i;
	for (i = 0; i < m; i++) {
		int num;
		cin >> num;

		here += num;
		if (here >= n - 1)
			break;
		here += arr[here];
		if (here >= n - 1)
			break;
	}
	cout << i + 1 << endl;
	
	
	return 0;
}