#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator<<(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 1001

int n;
int dp[2][MAX_N]; // i의 턴일때 j개의 돌이 남았을때 그 사람의 승패 여부 0 : 0이 이김 1 : 1이 이김

int getDp(int idx1, int idx2) {
	if (idx2 == 0)
		return !idx1;
	if (idx2 == 1)
		return idx1;
	if (idx2 == 2)
		return !idx1;
	if (idx2 == 3)
		return idx1;
	if (idx2 == 4)
		return idx1;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	// 내 차례 일 때 -> 1개라도 내가 이기면 내가 이긴다.
	if (idx1 == 0) {
		if (getDp(!idx1, idx2 - 1) == 0 | getDp(!idx1, idx2 - 3) == 0 | getDp(!idx1, idx2 - 4) == 0)
			ret = 0;
		else
			ret = 1;
	}
	// 쟤 차례 일 때 -> 1개라도 쟤가 이기면 쟤가 이긴다.
	else {
		if (getDp(!idx1, idx2 - 1) | getDp(!idx1, idx2 - 3) | getDp(!idx1, idx2 - 4))
			ret = 1;
		else
			ret = 0;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> n;

	cout << (getDp(0, n) == 0 ? "SK" : "CY") << endl;

	return 0;
}