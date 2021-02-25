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

#define MAX_N 100000
#define MOD 1000000007

int n;
int arr[MAX_N];

int devide(int l, int r) {
	if (r - 1 == l) 
		return arr[l];
	if (r == l)
		return 0;

	int mid = (l + r) / 2;
	int left = mid - 1, right = mid;
	int height = min(arr[left], arr[right]);
	int maxValue = height * 2;
	while (true) {
		if ((left - 1 >= l) && ((right == r - 1) || (arr[left - 1] >= arr[right + 1])))
			left--;
		else if ((right + 1 < r) && ((left == l) || (arr[right + 1] > arr[left - 1])))
			right++;
		else
			break;
		height = min({ height, arr[left], arr[right] });
		maxValue = max(maxValue, height * (right - left + 1));
	}

	return max({maxValue, devide(l, mid), devide(mid, r) });
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << devide(0, n) << endl;
	

	return 0;
}