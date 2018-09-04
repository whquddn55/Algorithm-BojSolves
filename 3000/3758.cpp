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

#define MAX_N 100

int n, k, t, m;
int score[MAX_N][MAX_N];
pair<pii, pii> arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(score, 0, sizeof(score));
		memset(arr, 0, sizeof(arr));

		cin >> n >> k >> t >> m;
		t--;
		for (int i = 0; i < n; i++)
			arr[i].second.second = i;
		for (int i = 0; i < m; i++) {
			int id, num, s;
			cin >> id >> num >> s;
			id--;
			num--;
			arr[id].first.second++;
			arr[id].second.first = i;
			score[id][num] = max(score[id][num], s);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < k; j++)
				arr[i].first.first += score[i][j];

		sort(arr, arr + n, [](pair<pii, pii>& a, pair<pii, pii>& b) {
			return a.first.first != b.first.first ? a.first.first > b.first.first : a < b;
		});
		for (int i = 0; i < n; i++)
			if (arr[i].second.second == t) {
				cout << i + 1 << endl;
				break;
			}
	}
	
	return 0;
}