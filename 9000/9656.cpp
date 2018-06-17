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
int dp[2][MAX_N]; // i의 턴일때 j개의 돌이 남았을때 그 사람의 승패 여부

int getDp(int idx1, int idx2) {
	if (idx2 == 0)
		return !idx1;
	if (idx2 < 0)
		return idx1;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	int v1 = getDp(!idx1, idx2 - 1);
	int v2 = getDp(!idx1, idx2 - 3);
	if (v1 == idx1)
		return ret = idx1;
	if (v2 == idx1)
		return ret = idx1;
	return ret = !idx1;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> n;
	
	cout << (getDp(0, n) == 0 ? "CY" : "SK") << endl;

	return 0;
}