#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

ll n, l, w, h;

bool decide(double mid) {
	return ((ll)(l / mid) * (ll)(w / mid) * (ll)(h / mid)) >= n;
}

double binarySearch(double minValue, double maxValue) {
	double left = minValue, right = maxValue;
	for (int i = 0; i < 100; i++) {
		double mid = (left + right) / 2;
		if (decide(mid))
			left = mid;
		else
			right = mid;
	}
	return right;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> l >> w >> h;
	cout << fixed;
	cout.precision(10);
	cout << binarySearch(0.0, min({ l, w, h }));
	
	return 0;
}
