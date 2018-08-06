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
#define MAX_N 10000

struct Data {
	int x, y, z;
};

int n;
Data arr[MAX_N];
pair<pii, pii> minDist[MAX_N];

int ans = INF;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		minDist[i].first.first = minDist[i].first.second = INF;
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			if (i != j) {
				int dist = abs(arr[i].x - arr[j].x) + abs(arr[i].y - arr[j].y) + abs(arr[i].z - arr[j].z);
				if (minDist[i].first.first > dist) {
					minDist[i].second = minDist[i].first;
					minDist[i].first = { dist, j };
				}
			}

	for (int i = 0 ; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j) {
				int dist = abs(arr[i].x - arr[j].x) + abs(arr[i].y - arr[j].y) + abs(arr[i].z - arr[j].z);
				ans = min(ans, dist + (i == minDist[j].first.second ? minDist[j].second.first : minDist[j].first.first));
			}
	cout << ans << endl;

	return 0;
}
