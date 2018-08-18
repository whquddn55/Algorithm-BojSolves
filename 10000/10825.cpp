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

#define MAX_N 100000

int n;
pair<string, pair<pair<int, int>, int>> arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, [](pair<string, pair<pair<int, int>, int>>& a, pair<string, pair<pair<int, int>, int>>& b) {
		return a.second.first.first == b.second.first.first ? (a.second.first.second == b.second.first.second ? (a.second.second == b.second.second ? (a.first < b.first) : a.second.second > b.second.second) : a.second.first.second < b.second.first.second) : a.second.first.first > b.second.first.first;
	});
	for (int i = 0; i < n; i++)
		cout << arr[i].first << endl;
	
	return 0;
}