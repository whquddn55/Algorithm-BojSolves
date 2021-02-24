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

int n, m, d;
int origin[15][15];

int func(int position[3]) {
	int arr[15][15];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			arr[i][j] = origin[i][j];

	int result = 0;
	for (int round = 0; round < n; ++round) {
		pii target[3];
		int targetDist[3] = { INF, INF, INF };
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] == 1) {
					for (int k = 0; k < 3; ++k) {
						int dist = abs(position[k] - j) + (n - i);
						if (dist <= d) {
							if (targetDist[k] > dist) {
								targetDist[k] = dist;
								target[k] = pii(i, j);
							}
							else if (targetDist[k] == dist) {
								if (target[k].second > j) {
									targetDist[k] = dist;
									target[k] = pii(i, j);
								}
							}
						}
					}
				}
			}
		for (int i = 0; i < 3; ++i)
			if (targetDist[i] != INF) {
				if (arr[target[i].first][target[i].second] == 1)
					result++;
				arr[target[i].first][target[i].second] = 0;
			}

		for (int i = n - 1; i > 0; --i)
			for (int j = 0; j < m; ++j)
				arr[i][j] = arr[i - 1][j];
		for (int i = 0; i < n; ++i)
			arr[0][i] = 0;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> origin[i][j];
	
	int result = 0;
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j)
			for (int k = j + 1; k < m; ++k) {
				int position[3] = { i, j, k };
				result = max(result, func(position));
			}
	cout << result << endl;
	

	return 0;
}