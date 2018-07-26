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

#define MAX_R 100000

ll r, l, b;
ll arr[MAX_R];
int ans = -INF;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> r >> l >> b;
	for (int i = 0; i < r; i++)
		cin >> arr[i];

	int left = 1, right = 0; // [left, right]를 갖는다.
	ll dist = 0;
	ll diff = 0; 
	for (int i = 0; i < r; i++) {
		if (i) {
			diff = arr[i] - arr[i - 1];
			int prvLeft = left;
			left = upper_bound(arr, arr + r, arr[left] + diff) - arr;
			dist -= diff * (right - i + 1);
			dist += diff * (i - left);
			for (int j = prvLeft; j < left; j++)
				dist -= (arr[i - 1] - arr[j]);

			//cout << dist << endl;
		}
		while (true) {
			if (dist > b)
				break;
			if (left > 0 && (right == r - 1 || (arr[i] - arr[left - 1]) <= (arr[right + 1] - arr[i])) && dist + arr[i] - arr[left - 1] <= b) {
				dist += arr[i] - arr[left - 1];
				left--;
			}
			else if (right < r - 1 && dist + arr[right + 1] - arr[i] <= b) {
				dist += arr[right + 1] - arr[i];
				right++;
			}
			else
				break;
		}
		//cout << pii(left, right) << ' ' << dist << ' ';
		ans = max(ans, right - left + 1);
	}
	cout << ans << endl;

	return 0;
}
