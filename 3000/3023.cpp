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

#define MAX_N 200

int r, c;
char arr[MAX_N][MAX_N];
pii errorPos;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	cin >> errorPos;
	errorPos.first--;
	errorPos.second--;

	for (int i = 0; i < r; i++)
		for (int j = c; j < c * 2; j++)
			arr[i][j] = arr[i][c * 2 - j - 1];
	for (int i = r; i < 2 * r; i++)
		for (int j = 0; j < c * 2; j++)
			arr[i][j] = arr[2 * r - i - 1][j];

	if (arr[errorPos.first][errorPos.second] == '.')
		arr[errorPos.first][errorPos.second] = '#';
	else
		arr[errorPos.first][errorPos.second] = '.';

	for (int i = 0; i < 2 * r; i++) {
		for (int j = 0; j < 2 * c; j++)
			cout << arr[i][j];
		cout << endl;
	}

	return 0;
}
