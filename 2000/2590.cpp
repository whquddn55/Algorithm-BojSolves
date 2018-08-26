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

#define MAX_N 6

int arr[MAX_N];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 0; i < MAX_N; ++i)
		cin >> arr[i];

	ans += arr[5];

	ans += arr[4];
	arr[0] -= arr[4] * 11;

	int remain;
	if (arr[3] > 0) {
		ans += arr[3];
		remain = arr[3] * 20 - min(arr[1], arr[3] * 5) * 4;
		arr[1] -= arr[3] * 5;
		if (remain > 0)
			arr[0] -= remain;
	}

	if (arr[2] > 0) {
		ans += (arr[2] + 3) / 4;
		if (arr[2] % 4) {
			remain = 36 - (arr[2] % 4) * 9;
			if (arr[1] > 0) {
				int temp[] = { 0, 5, 3, 1 };
				remain -= temp[arr[2] % 4] * 4;
				arr[1] -= temp[arr[2] % 4];
			}
			if (remain > 0)
				arr[0] -= remain;
		}
	}

	if (arr[1] > 0) {
		ans += (arr[1] + 8) / 9;
		if (arr[1] % 9) {
			remain = 36 - (arr[1] % 9) * 4;
			if (remain > 0)
				arr[0] -= remain;
		}
	}
	if (arr[0] > 0)
		ans += (arr[0] + 35) / 36;

	cout << ans << endl;

	return 0;
}