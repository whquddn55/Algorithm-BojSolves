#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MOD 1000000007

#define MAX_N 105

ll mat[8][8] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 1, 0},
	{0, 0, 0, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0}
};

ll ret[8][8] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 1, 0},
	{0, 0, 0, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0}
};

void get(int d) {
	if (d == 1)
		return;

	get(d / 2);

	//ret = ret * ret;
	ll temp[8][8];
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			temp[i][j] = 0;
			for (int k = 0; k < 8; ++k)
				temp[i][j] = (temp[i][j] + ret[i][k] * ret[k][j]) % MOD;
		}
	}
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			ret[i][j] = temp[i][j];

	if (d % 2) {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				temp[i][j] = 0;
				for (int k = 0; k < 8; ++k)
					temp[i][j] = (temp[i][j] + ret[i][k] * mat[k][j]) % MOD;
			}
		}

		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				ret[i][j] = temp[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int d;
	cin >> d;

	get(d);
	cout << ret[0][0] << endl;

	return 0;
}