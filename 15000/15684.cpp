#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

#define MAX_N 15
#define MAX_M 35

int n, m, h;
bool vertical[MAX_M][MAX_N];

int get(vector<int>& pos, int height, int cnt) {
	if (height == m) {
		bool isEnd = true;
		for (int i = 0; i < n; i++)
			if (pos[i] != i)
				isEnd = false;

		if (isEnd)
			return cnt;
		return INF;
	}

	for (int i = 0; i < n - 1; i++)
		if (vertical[height][i])
			swap(pos[i], pos[i + 1]);

	int ret = get(pos, height + 1, cnt);
	if (cnt == 0) {
		for (int i = 0; i < n - 1; i++)
			if ((!i || !vertical[height][i - 1]) && !vertical[height][i] && !vertical[height][i + 1]) {
				swap(pos[i], pos[i + 1]);
				vertical[height][i] = true;
				ret = min(ret, get(pos, height + 1, cnt + 1));
				for (int j = 0; j < n - 1; j++)
					if ((!j || !vertical[height][j - 1]) && !vertical[height][j] && !vertical[height][j + 1]) {
						swap(pos[j], pos[j + 1]);
						vertical[height][j] = true;
						ret = min(ret, get(pos, height + 1, cnt + 2));
						for (int k = 0; k < n - 1; k++)
							if ((!k || !vertical[height][k - 1]) && !vertical[height][k] && !vertical[height][k + 1]) {
								swap(pos[k], pos[k + 1]);
								vertical[height][k] = true;
								ret = min(ret, get(pos, height + 1, cnt + 3));
								swap(pos[k], pos[k + 1]);
								vertical[height][k] = false;
							}
						swap(pos[j], pos[j + 1]);
						vertical[height][j] = false;
					}
				swap(pos[i], pos[i + 1]);
				vertical[height][i] = false;
			}
	}
	else if (cnt == 1) {
		for (int i = 0; i < n - 1; i++)
			if ((!i || !vertical[height][i - 1]) && !vertical[height][i] && !vertical[height][i + 1]) {
				swap(pos[i], pos[i + 1]);
				vertical[height][i] = true;
				ret = min(ret, get(pos, height + 1, cnt + 1));
				for (int j = 0; j < n - 1; j++)
					if ((!j || !vertical[height][j - 1]) && !vertical[height][j] && !vertical[height][j + 1]) {
						swap(pos[j], pos[j + 1]);
						vertical[height][j] = true;
						ret = min(ret, get(pos, height + 1, cnt + 2));
						swap(pos[j], pos[j + 1]);
						vertical[height][j] = false;
					}
				swap(pos[i], pos[i + 1]);
				vertical[height][i] = false;
			}
	}
	else if (cnt == 2) {
		for (int i = 0; i < n - 1; i++)
			if (( !i || !vertical[height][i - 1]) && !vertical[height][i] && !vertical[height][i + 1]) {
				swap(pos[i], pos[i + 1]);
				ret = min(ret, get(pos, height + 1, cnt + 1));
				swap(pos[i], pos[i + 1]);
			}
	}

	for (int i = 0; i < n - 1; i++)
		if (vertical[height][i])
			swap(pos[i], pos[i + 1]);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	
	cin >> n >> h >> m;
	for (int i = 0; i < h; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		vertical[a][b] = true;
	}

	vector<int> pos;
	for (int i = 0; i < n; i++)
		pos.push_back(i);

	int ret = get(pos, 0, 0);
	cout << (ret == INF ? -1 : ret) << endl;

	return 0;
}