#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 51

int n, m;
vector<pii> chicken;
vector<pii> house;

int ans = INF;
vector<int> picked;

void get(int toPick) {
	if (picked.size() == m) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int minValue = INF;
			for (int j = 0; j < m; j++) {
				pii chi = chicken[picked[j]];
				minValue = min(minValue, abs(house[i].first - chi.first) + abs(house[i].second - chi.second));
			}
			sum += minValue;
		}

		ans = min(ans, sum);
	}
	if (toPick == chicken.size())
		return;

	picked.push_back(toPick);
	get(toPick + 1);
	picked.pop_back();
	get(toPick + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			if (t == 1)
				house.emplace_back(i, j);
			else if (t == 2)
				chicken.emplace_back(i, j);
		}

	get(0);
	cout << ans << endl;

	return 0;
}
