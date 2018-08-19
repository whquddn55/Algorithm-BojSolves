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

#define MAX_N 500000

int n;
int sum;
int middleValue, maxValue = -INF,  minValue = INF;
pii cnt[8001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		maxValue = max(maxValue, t);
		minValue = min(minValue, t);
		sum += t;
		cnt[t + 4000].first++;
		cnt[t + 4000].second = t;
	}
	int temp = 0;
	for (int i = 0; i < 8001; i++) {
		temp += cnt[i].first;
		if (temp >= (n + 1) / 2) {
			middleValue = cnt[i].second;
			break;
		}
	}
	sort(cnt, cnt + 8001, [](pii& a, pii& b) {
		return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first);
	});
	cout << sum / n + (sum % n < 0 ? -1 : 1) * (abs(sum % n) >= (n + 1) / 2) << endl;
	cout << middleValue << endl;
	cout << (cnt[0].first == cnt[1].first ? cnt[1].second : cnt[0].second) << endl;
	cout << maxValue - minValue << endl;
	
	return 0;
}