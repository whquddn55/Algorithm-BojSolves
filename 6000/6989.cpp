#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 150

int n, k;
int arr[MAX_N];

int sum[MAX_N];
int maxScore[MAX_N];
unsigned int dp[MAX_N][40000];

void setBit(int row, int a) {
	int th = a / 32;
	int r = a % 32;
	dp[row][th] |= (1 << r);
}

bool getBit(int row, int a) {
	int th = a / 32;
	int r = a % 32;
	return (dp[row][th] & (1 << r));
}

void copyRange(int prvRow, int prvEnd, int curRow, int curStart) {
	int curStartTh = curStart / 32;
	int curStartR = curStart % 32;
	int prvEndTh = prvEnd / 32;

	if (curStartR == 0)
		for (int i = 0; i <= prvEndTh; i++)
			dp[curRow][i + curStartTh] |= dp[prvRow][i];
	else
		for (int i = 0; i <= prvEndTh; i++) {
			dp[curRow][i + curStartTh] |= (dp[prvRow][i] << curStartR);
			dp[curRow][i + curStartTh + 1] |= (dp[prvRow][i] >> (32 - curStartR));
		}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> k;

	sum[0] = maxScore[0] = arr[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + arr[i];
		maxScore[i] = sum[i] + maxScore[i - 1];
	}

	if (k > maxScore[n - 1]) {
		cout << k << endl;
		return 0;
	}

	setBit(0, 0);
	setBit(0, arr[0]);
	for (int i = 1; i < n; i++) {
		int sum = 0;
		for (int j = i; j >= 1; --j) {
			copyRange(j - 1, maxScore[j - 1], i, sum);
			sum += arr[j] * (i - j + 1);
		}
		setBit(i, sum);
		setBit(i, maxScore[i]);
	}

	for (int i = k; i <= maxScore[n - 1] + 1; i++)
		if (!getBit(n - 1, i)) {
			cout << i << endl;
			return 0;
		}

	return 0;
}
