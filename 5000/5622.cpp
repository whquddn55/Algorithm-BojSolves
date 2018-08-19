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

#define MAX_N 5005

string str;
int arr[26];

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> str;
	for (int i = 0; i < 15; i++) 
		arr[i] = i / 3 + 3;
	for (int i = 15; i < 19; i++)
		arr[i] = 8;
	for (int i = 19; i < 22; i++)
		arr[i] = 9;
	for (int i = 22; i < 26; i++)
		arr[i] = 10;

	for (auto e : str)
		ans += arr[e - 'A'];
	cout << ans << endl;
	
	return 0;
}