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

#define MAX_N 1025

int n, m;
int arr[MAX_N][MAX_N];
int psum[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + arr[i][j];

	while (m--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << (psum[c][d] - psum[c][b - 1] - psum[a - 1][d] + psum[a - 1][b - 1]) << endl;
	}

	return 0;
}