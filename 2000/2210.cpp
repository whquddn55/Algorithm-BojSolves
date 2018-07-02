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

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 5

int arr[MAX_N][MAX_N];
set<string> s;

int ans = 0;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

void get(int hereY, int hereX, int cnt, string& str) {
	if (cnt == 0) {
		str.push_back(arr[hereY][hereX] + '0');
		if (!s.count(str)) {
			s.insert(str);
			ans++;
		}
		str.pop_back();
		return;
	}
	str.push_back(arr[hereY][hereX] + '0');

	for (int i = 0; i < 4; i++) {
		int nextY = hereY + dy[i];
		int nextX = hereX + dx[i];

		if (nextY >= MAX_N || nextY < 0 || nextX >= MAX_N || nextX < 0)
			continue;
		get(nextY, nextX, cnt - 1, str);
	}
	str.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
			cin >> arr[i][j];

	string s;
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
			get(i, j, 5, s);
	cout << ans << endl;

	return 0;
}
