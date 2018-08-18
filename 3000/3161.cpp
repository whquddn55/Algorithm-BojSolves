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

#define INF (LLONG_MAX / 2)

#define MAX_N 50

int n, m;
int arr[MAX_N][MAX_N];
int score[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			arr[i][t - 1] = j;
		}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;

			int cnt = 0;
			for (int k = 0; k < m; k++) {
				if (arr[k][i] < arr[k][j])
					cnt++;
				else 
					cnt--;
			}

			if (cnt > 0)
				score[i]++;
		}
	}

	int maxValue = *max_element(score, score + n);
	for (int i = 0; i < n; i++)
		if (score[i] == maxValue)
			cout << i + 1 << ' ';
	cout << endl;

	return 0;
}