#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 501

int n, m;
int arr1[MAX_N];
int arr2[MAX_N];

int dp[MAX_N][MAX_N];
pii nxt[MAX_N][MAX_N];
int ans = 0;

int getDp(int idx1, int idx2) {
	if (idx1 == n || idx2 == m)
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;
	ret = 1;

	nxt[idx1][idx2] = { n, m };
	for (int i = idx1 + 1; i < n; i++) {
		if (arr1[idx1] < arr1[i]) {
			for (int j = idx2 + 1; j < m; j++)
				if (arr1[i] == arr2[j]) {
					int t = getDp(i, j);
					if (ret < t + 1) {
						ret = t + 1;
						nxt[idx1][idx2] = { i, j };
					}
					break;
				}
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> arr2[i];

	memset(dp, -1, sizeof(dp));

	pii here(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr1[i] == arr2[j]) {
				int t = getDp(i, j);
				if (ans < t) {
					ans = t;
					here = { i, j };
				}
				break;
			}

	cout << ans << endl;

	pii ord(n, m);
	while (here != ord) {
		cout << arr1[here.first] << ' ';
		here = nxt[here.first][here.second];
	}

	return 0;
}
