#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_N 100

int n;
int arr[MAX_N];
vector<int> arr2;

set<int> ans;

int euclid(int a, int b) {
	if (b == 0)
		return a;
	return euclid(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) 
			arr2.push_back(abs(arr[i] - arr[j]));
	
	int gcd = arr2[0];
	for (auto e : arr2)
		gcd = euclid(gcd, e);

	for (int i = 1; i <= sqrt(gcd); i++) 
		if (gcd % i == 0) {
			ans.insert(i);
			ans.insert(gcd / i);
		}
	for (auto e : ans)
		if (e != 1)
			cout << e << ' ';
	cout << endl;
	
	return 0;
}