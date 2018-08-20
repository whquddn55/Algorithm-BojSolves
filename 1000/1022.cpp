#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_N 50

int r1, c1, r2, c2;
int arr[MAX_N][MAX_N];

int maxValue = -INF;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> r1 >> c1 >> r2 >> c2;
	for (int i = r1; i <= r2; i++) {
		int r = i - r1;
		for (int j = c1; j <= c2; j++) {
			int c = j - c1;
			if (i == 0 && j == 0)
				arr[r][c] = 1;
			else if (j > 0 && (-j <= i && i <= j - 1))
				arr[r][c] = 4 * j * (j - 1) + 2 + (j - 1 - i);
			else if (j < 0 && (j <= i && i <= -j))
				arr[r][c] = 4 * (-j + 1) * (-j - 1) + 5 + (i - j);
			else if (i > 0 && (-i <= j && j <= i))
				arr[r][c] = 4 * i * (i - 1) + 6 * (i - 1) + 7 + (i + j);
			else
				arr[r][c] = 4 * -i * (-i - 1) + 2 * (-i - 1) + 3 + (-i - j);
			maxValue = max(maxValue, arr[r][c]);
		}
	}
	int t = 0;
	while (maxValue) {
		t++;
		maxValue /= 10;
	}
	for (int i = 0; i <= r2 - r1; i++, cout << endl)
		for (int j = 0; j <= c2 - c1; j++) {
			int temp = arr[i][j];
			int cnt = t;
			while (temp) {
				cnt--;
				temp /= 10;
			}
			while (cnt--)
				cout << ' ';
			cout << arr[i][j] << ' ';
		}
	
	return 0;
}