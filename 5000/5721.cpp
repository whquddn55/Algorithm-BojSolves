#include <bits/stdc++.h>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'
#define MAXSIZE 100001

int n, m;
int dp1[MAXSIZE];
int dp2[MAXSIZE];
vector<int> arr;

int getDp1(int idx1, int hereRow) {
	if ((idx1 / m) > hereRow)
		return 0;

	int& ret = dp1[idx1];
	if (ret != -1)
		return ret;

	return ret = max(getDp1(idx1 + 2, hereRow) + arr[idx1], getDp1(idx1 + 1, hereRow));
}

int getDp2(int idx1) {
	if ((idx1 / m) >= n)
		return 0;

	int& ret = dp2[idx1 / m];
	if (ret != -1)
		return ret;

	return ret = max(getDp2(idx1 + 2 * m) + getDp1(idx1, idx1 / m), getDp2(idx1 + 1 * m));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));
		arr.resize(n * m);
		for (int i = 0; i < n * m; ++i)
			cin >> arr[i];

		cout << getDp2(0) << endl;
	}

	return 0;
}
