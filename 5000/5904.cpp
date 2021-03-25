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

#define MAX_N 105

int n;

char get(ll sLen, ll sIndex) {
	if (sIndex == 0) 
		return "moo"[n - 1];
	

	ll left = (sLen - (sIndex + 3)) / 2;
	ll right = left + (sIndex + 3);
	// case 1
	if (n <= left)
		return get(left, sIndex - 1);
	else if (n > right) {
		n -= right;
		return get(left, sIndex - 1);
	}
	else {
		n -= left;
		string temp =  "moo";
		while (sIndex--)
			temp.push_back('o');
		return temp[n - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;

	int index = 0;
	ll s = 3;
	while (n > s) {
		index++;
		s = s * 2 + (index + 3);
	}

	cout << get(s, index) << endl;
	
	return 0;
}