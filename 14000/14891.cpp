#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 11

int k;
char arr[4][8];

void rot(int idx1, bool d) {
	if (!d) {
		char temp = arr[idx1][0];
		for (int i = 1; i < 8; i++)
			arr[idx1][i - 1] = arr[idx1][i];
		arr[idx1][7] = temp;
	}
	else {
		char temp = arr[idx1][7];
		for (int i = 7; i > 0; i--)
			arr[idx1][i] = arr[idx1][i - 1];
		arr[idx1][0] = temp;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
			arr[i][j] -= '0';
		}
	cin >> k;
	while (k--) {
		int n, t;
		bool d;
		cin >> n >> t;
		if (t == -1)
			t = 0;
		d = t;
		n--;

		int l = 0, r = 3;
		for (int i = n; i < 3; i++) {
			if (arr[i][2] == arr[i + 1][6]) {
				r = i;
				break;
			}
		}
		
		for (int i = n; i > 0; i--) {
			if (arr[i][6] == arr[i - 1][2]) {
				l = i;
				break;
			}
		}

		if ((l - n) % 2 == 0)
			d = !d;
		for (int i = l; i <= r; i++) 
			rot(i, d = !d);
	}

	int ans = 0;
	for (int i = 0; i < 4; i++)
		if (arr[i][0])
			ans += (1 << i);
	cout << ans << endl;

	return 0;
}
