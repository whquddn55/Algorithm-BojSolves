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

#define MAX_K 10001

int l, k, c;
int arr[MAX_K];
pii ans;

bool d(int mid) {
	int lastCutPos = l;
	int remain = c;

	for (int i = k - 1; i >= 0; i--) {
		if (lastCutPos - arr[i] > mid) {
			lastCutPos = arr[i + 1];
			remain--;
		}
	}

	ans.second = lastCutPos;
	if (remain > 0)
		ans.second = arr[1];
	return remain >= 0;
}

void parametricSearch(int minValue) {
	int l = minValue, r = 1000000001;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (d(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	ans.first = l;
	d(l);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);


	while (cin >> l >> k >> c) {
		k++;
		arr[0] = 0;
		for (int i = 1; i < k; i++)
			cin >> arr[i];
		sort(arr, arr + k);

		int minValue = l - arr[k - 1];
		for (int i = 1; i < k; i++)
			minValue = max(minValue, arr[i] - arr[i - 1]);

		parametricSearch(minValue);
		cout << ans << endl;
	}
	return 0;
}
