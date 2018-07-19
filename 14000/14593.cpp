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

#define MAX_N 10001

int n;
pair<pii, pii> arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		arr[i].first.first = i + 1;
		cin >> arr[i].first.second >> arr[i].second;
	}
	sort(arr, arr + n, [](pair<pii, pii>& a, pair<pii, pii>& b)->bool {
		return a.first.second == b.first.second ? a.second < b.second : a.first.second > b.first.second;
	});

	cout <<  arr[0].first.first << endl; 


	return 0;
}