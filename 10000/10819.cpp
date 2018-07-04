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

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 8

int n;
int arr[MAX_N];
int idx[MAX_N];

int ans = -INF;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		idx[i] = i;
	}

	int cnt = 40400;
	while (cnt--) {
		int temp = 0;
		for (int i = 0; i < n - 1; i++)
			temp += max(-(arr[idx[i]] - arr[idx[i + 1]]), arr[idx[i]] - arr[idx[i + 1]]);
		ans = max(ans, temp);
		next_permutation(idx, idx + n);
	}
	cout << ans << endl;

	return 0;
}
