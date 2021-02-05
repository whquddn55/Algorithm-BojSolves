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

#define MAX_N 100005
#define MOD  1000000007LL

set<string> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string t1, t2, t3;
	cin >> t1 >> t2 >> t3;

	int s, e, e2;
	s = ((t1.at(0) - '0') * 10 + (t1.at(1) - '0')) * 60 + (t1.at(3) - '0') * 10 + t1.at(4) - '0';
	e = ((t2.at(0) - '0') * 10 + (t2.at(1) - '0')) * 60 + (t2.at(3) - '0') * 10 + t2.at(4) - '0';
	e2 = ((t3.at(0) - '0') * 10 + (t3.at(1) - '0')) * 60 + (t3.at(3) - '0') * 10 + t3.at(4) - '0';
	string t, name;

	int result = 0;
	while (cin >> t >> name) {
		int time = ((t.at(0) - '0') * 10 + (t.at(1) - '0')) * 60 + (t.at(3) - '0') * 10 + t.at(4) - '0';
		if (time <= s)
			arr.emplace(name);
		else if (time >= e && time <= e2) {
			if (arr.find(name) != arr.end()) {
				result++;
				arr.erase(name);
			}
		}
		else if (time > e2)
			break;

	}
	cout << result << endl;

	return 0;
}