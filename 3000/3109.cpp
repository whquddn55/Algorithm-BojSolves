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

#define MAX_N 10005
#define MOD 1000000007

int r, c;
bool arr[MAX_N][505]; // 0 : empty, 1 : wall(visited)

bool dfs(int hereY, int hereX) {
	if (hereX == c - 1) 
		return true;
	int nextYs[3] = { hereY - 1, hereY, hereY + 1 };
	int nextX = hereX + 1;

	bool ret = false;
	for (int i = 0; i < 3; ++i) {
		if (nextYs[i] < 0 || nextYs[i] >= r || arr[nextYs[i]][nextX] || ret)
			continue;
		arr[nextYs[i]][nextX] = 1;
		ret = dfs(nextYs[i], nextX);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			char temp;
			cin >> temp;
			if (temp == '.')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}

	
	int result = 0;
	for (int i = 0; i < r; ++i) {
		arr[i][0] = true;
		result += dfs(i, 0);
	}
	
	cout << result << endl;
	

	return 0;
}