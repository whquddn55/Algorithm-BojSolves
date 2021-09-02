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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 500005
#define MOD 1000003

int n;
vector<int> arr;
vector<int> op;
int maxDp[20][20];
int minDp[20][20];

int calc(int i, int j, int k, int l[20][20], int r[20][20]) {
	int value;
	switch(op[j]) {
		case '*':
			value = l[i][j] * r[j + 1][k];
			break;
		case '+':
			value = l[i][j] + r[j + 1][k];
			break;
		case '-':
			value = l[i][j] - r[j + 1][k];
			break;
		default:
			assert(false);
	}
	return value;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	while(n--) {
		char c;
		cin >> c;
		if (isdigit(c)) {
			c -= '0';
			arr.push_back(c);
		}
		else 
			op.push_back(c);
	}
	for (int i = 0; i < arr.size(); ++i)
		for (int j = 0; j < arr.size(); ++j) {
			maxDp[i][j] = INT_MIN;
			minDp[i][j] = INT_MAX;
		}
	for (int i = 0; i < arr.size(); ++i)
		maxDp[i][i] = minDp[i][i] = arr[i];

		
	for (int len = 1; len < arr.size(); ++len) {
		for (int start = 0; start + len < arr.size(); ++start) {
			for (int mid = 0; mid < len; ++mid) {
				maxDp[start][start + len] = max({maxDp[start][start + len], calc(start, start + mid, start + len, maxDp, maxDp), calc(start, start + mid, start + len, minDp, maxDp), calc(start, start + mid, start + len, maxDp, minDp), calc(start, start + mid, start + len, minDp, minDp)});
				minDp[start][start + len] = min({minDp[start][start + len], calc(start, start + mid, start + len, maxDp, maxDp), calc(start, start + mid, start + len, minDp, maxDp), calc(start, start + mid, start + len, maxDp, minDp), calc(start, start + mid, start + len, minDp, minDp)});

			}
		}
	}

	cout << maxDp[0][arr.size() - 1] << endl;
	
	return 0;
}
