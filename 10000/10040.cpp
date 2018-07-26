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

#define MAX_N 1000

int n, m;
int arr[MAX_N];
int cnt[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		for (int j = 0; j < n; j++) {
			if (arr[j] <= t) {
				cnt[j]++;
				break;
			}
		}
	}
	int maxValue = 0;
	int maxIndex = 0;
	for (int i = 0; i < n; i++)
		if (cnt[i] > maxValue) {
			maxValue = cnt[i];
			maxIndex = i + 1;
		}
	cout << maxIndex << endl;

	return 0;
}
