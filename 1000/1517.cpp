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

#define MAX_N 500005

int n;
int arr[MAX_N];

ll get(int l, int r) {
	if (l == r - 1) {
		int result = arr[l] > arr[r];
		if (arr[l] > arr[r])
			swap(arr[l], arr[r]);
		return result;
	}
	if (l == r)
		return 0;
	
	int mid = (l + r) / 2;
	ll leftValue = get(l, mid);
	ll rightValue = get(mid + 1, r);

	vector<int> temp;
	temp.reserve(r - l + 1);
	int lIndex = l;
	int rIndex = mid + 1;
	ll midValue = 0;
	while (lIndex != (mid + 1) && rIndex != (r + 1)) {
		if (arr[lIndex] > arr[rIndex]) {
			midValue += mid - lIndex + 1;
			temp.emplace_back(arr[rIndex]);
			++rIndex;
		}
		else {
			temp.emplace_back(arr[lIndex]);
			++lIndex;
		}
	}
	while (lIndex != (mid + 1)) {
		temp.emplace_back(arr[lIndex]);
		++lIndex;
	}
	while (rIndex != (r + 1)) {
		temp.emplace_back(arr[rIndex]);
		++rIndex;
	}
	for (int i = l; i <= r; ++i) 
		arr[i] = temp[i - l];

	return leftValue + rightValue + midValue;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << get(0, n - 1) << endl;
	

	return 0;
}