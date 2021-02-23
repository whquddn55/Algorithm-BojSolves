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

#define MAX_N 21
#define MOD 1000000007

int n;
int arr[MAX_N][MAX_N];
int result = INF;



void func(int y, int x, int d1, int d2) {
	bool a[MAX_N][MAX_N] = { false, };
	int values[5] = { 0, };
	for (int i = 0; i <= d1; ++i) {
		a[y - i][x + i] = true;
		a[y + d2 - i][x + d2 + i] = true;
	}
	for (int i = 0; i <= d2; ++i) {
		a[y + i][x + i] = true;
		a[y - d1 + i][x + d1 + i] = true;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j]) {
				int nextJ;
				for (nextJ = n - 1; nextJ > j; nextJ--)
					if (a[i][nextJ])
						break;
				for (int k = j; k < nextJ + 1; ++k)
					values[0] += arr[i][k];
				j = nextJ;
			}
			else if (j <= x + d1 && i < y)
				values[1] += arr[i][j];
			else if (j > x + d1 && i <= y - d1 + d2)
				values[2] += arr[i][j];
			else if (j < x + d2 && i >= y)
				values[3] += arr[i][j];
			else
				values[4] += arr[i][j];
		}
	}

	
	
	sort(values, values + 5);
	result = min(result, values[4] - values[0]);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	for (int i = 0; i < n; ++i) // y
		for (int j = 0; j < n; ++j) // x
			for (int d1 = 1; d1 <= i; ++d1) 
				for (int d2 = 1; d2 < n - i; ++d2) {
					if (j + d1 + d2 >= n)
						break;
	
					func(i, j, d1, d2);
				}
	cout << result << endl;

	return 0;
}