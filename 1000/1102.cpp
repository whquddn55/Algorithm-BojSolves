#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 17
#define MAX_BIT 1 << MAX_N
#define BIT_GET(A, N) (((A) >> (N)) & 1)

int n, p;
int start = 0, cnt = 0;
int table[MAX_N][MAX_N];
char arr[MAX_N];

int dp[MAX_BIT];

int getSum(int number) {
	int ret = 0;
	while (number) {
		ret += number & 1;
		number /= 2;
	}
	return ret;
}

int getDp(int idx1) {
	int& ret = dp[idx1];
	if (ret != -1)
		return ret;
	if (getSum(idx1) == p) 
		return ret = 0;
	

	ret = INF;
	for (int i = 0; i < n; i++) {
		if (BIT_GET(idx1, i) == 1) {
			for (int j = 0; j < n; j++)
				if (BIT_GET(idx1, j) == 0)
					ret = min(ret, getDp(idx1 + (1 << j)) + table[i][j]);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			cin >> table[i][j];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 'Y') 
			cnt++;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 'Y') 
			start++;
		start <<= 1;
	}
	start >>= 1;
	cin >> p;

	memset(dp, -1, sizeof(dp));
	if (cnt >= p)
		cout << 0 << endl;
	else if (cnt == 0)
		cout << -1 << endl;
	else 
		cout << getDp(start) << endl;
	
	return 0;
}

