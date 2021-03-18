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

#define MAX_N 1005

char arr[9][9];
set<int> row[9];
set<int> column[9];
set<int> square[9];
vector<pii> toFill;

bool get(int here) {
	if (here == toFill.size()) {
		for (int i = 0; i < 9; ++i, cout<<endl)
			for (int j = 0; j < 9; ++j)
				cout << (int)arr[i][j];
		return true;
	}

	int y = toFill[here].first;
	int x = toFill[here].second;
	bool ret = false;
	for (int i = 1; i <= 9; ++i) {
		if (row[y].find(i) != row[y].end() || 
			column[x].find(i) != column[x].end() || 
			square[(y / 3) * 3 + x / 3].find(i) != square[(y / 3) * 3 + x / 3].end())
			continue;

		arr[y][x] = i;
		row[y].insert(i);
		column[x].insert(i);
		square[(y / 3) * 3 + x / 3].insert(i);

		ret = get(here + 1);

		row[y].erase(i);
		column[x].erase(i);
		square[(y / 3) * 3 + x / 3].erase(i);
		if (ret)
			break;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			cin >> arr[i][j];
			arr[i][j] -= '0';
			if (arr[i][j] != 0) {
				row[i].insert(arr[i][j]);
				column[j].insert(arr[i][j]);
				square[(i / 3) * 3 + j / 3].insert(arr[i][j]);
			}
			else {
				toFill.emplace_back(i, j);
			}
		}

	get(0);
	
	return 0;
}