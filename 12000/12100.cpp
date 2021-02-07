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

#define MAX_N 25
#define MOD 1000000007

int n;
int arr[MAX_N][MAX_N];

void moveLeft() {
	for (int i = 0; i < n; ++i) {
		int prevValue = -1;
		int prevIndex = -1;
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] != 0) {
				if (prevValue == -1) {
					prevValue = arr[i][j];
					prevIndex = j;
				}
				else {
					if (arr[i][j] == prevValue) {
						arr[i][prevIndex] = prevValue * 2;
						arr[i][j] = 0;
						prevValue = -1;
						prevIndex = -1;
					}
					else {
						prevValue = arr[i][j];
						prevIndex = j;
					}
				}
			}
		}
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] != 0) {
				int tj = j - 1;
				while (tj != -1 && !arr[i][tj])
					tj--;
				swap(arr[i][j], arr[i][tj + 1]);
			}
		}
	}
}

void moveRight() {
	for (int i = 0; i < n; ++i) {
		int prevValue = -1;
		int prevIndex = -1;
		for (int j = n - 1; j >= 0; --j) {
			if (arr[i][j] != 0) {
				if (prevValue == -1) {
					prevValue = arr[i][j];
					prevIndex = j;
				}
				else {
					if (arr[i][j] == prevValue) {
						arr[i][prevIndex] = prevValue * 2;
						arr[i][j] = 0;
						prevValue = -1;
						prevIndex = -1;
					}
					else {
						prevValue = arr[i][j];
						prevIndex = j;
					}
				}
			}
		}

		for (int j = n - 1; j >= 0; --j) {
			if (arr[i][j] != 0) {
				int tj = j + 1;
				while (tj != n && !arr[i][tj])
					tj++;
				swap(arr[i][j], arr[i][tj - 1]);
			}
		}
	}
}

void moveTop() {
	for (int i = 0; i < n; ++i) {
		int prevValue = -1;
		int prevIndex = -1;
		for (int j = 0; j < n; ++j) {
			if (arr[j][i] != 0) {
				if (prevValue == -1) {
					prevValue = arr[j][i];
					prevIndex = j;
				}
				else {
					if (arr[j][i] == prevValue) {
						arr[prevIndex][i] = prevValue * 2;
						arr[j][i] = 0;
						prevValue = -1;
						prevIndex = -1;
					}
					else {
						prevValue = arr[j][i];
						prevIndex = j;
					}
				}
			}
		}

		for (int j = 0; j < n; ++j) {
			if (arr[j][i] != 0) {
				int tj = j - 1;
				while (tj != -1 && !arr[tj][i])
					tj--;
				swap(arr[j][i], arr[tj + 1][i]);
			}
		}
	}
}
void moveDown() {
	for (int i = 0; i < n; ++i) {
		int prevValue = -1;
		int prevIndex = -1;
		for (int j = n - 1; j >= 0; --j) {
			if (arr[j][i] != 0) {
				if (prevValue == -1) {
					prevValue = arr[j][i];
					prevIndex = j;
				}
				else {
					if (arr[j][i] == prevValue) {
						arr[prevIndex][i] = prevValue * 2;
						arr[j][i] = 0;
						prevValue = -1;
						prevIndex = -1;
					}
					else {
						prevValue = arr[j][i];
						prevIndex = j;
					}
				}
			}
		}

		for (int j = n - 1; j >= 0; --j) {
			if (arr[j][i] != 0) {
				int tj = j + 1;
				while (tj != n && !arr[tj][i])
					tj++;
				swap(arr[j][i], arr[tj - 1][i]);
			}
		}
	}
}
int func(int cnt) {
	if (cnt == 5) {
		int ret = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ret = max(arr[i][j], ret);
		return ret;
	}
	int ret = 0;
	int temp[MAX_N][MAX_N];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			temp[i][j] = arr[i][j];

	moveLeft();
	ret = max(ret, func(cnt + 1));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr[i][j] = temp[i][j];
	moveRight();
	ret = max(ret, func(cnt + 1));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr[i][j] = temp[i][j];
	moveTop();
	ret = max(ret, func(cnt + 1));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr[i][j] = temp[i][j];
	moveDown();
	ret = max(ret, func(cnt + 1));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr[i][j] = temp[i][j];


	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	cout << func(0) << endl;

	return 0;
}