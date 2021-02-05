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

vector<ll> s;

ll recur(int start, int end) {
	if (end - start == 1)
		return s[start];
	if (end - start == 3) {
		ll v1 = s[start], v2 = s[start + 2];
		int oper1 = (s[start + 1] == '+' ? 0 : (s[start + 1] == '-' ? 1 : (s[start + 1] == '*' ? 2 : 3)));
		ll result = 0;
		switch (oper1) {
		case 0:
			result = v1 + v2;
			break;
		case 1:
			result = v1 - v2;
			break;
		case 2:
			result = v1 * v2;
			break;
		case 3:
			result = v1 / v2;
			break;
		}
		return result;
	}
	ll v1 = s[start], v2 = s[start + 2];
	int oper1 = (s[start + 1] == '+' ? 0 : (s[start + 1] == '-' ? 1 : (s[start + 1] == '*' ? 2 : 3)));
	ll result1 = 0;
	switch (oper1) {
	case 0:
		result1 = v1 + v2;
		break;
	case 1:
		result1 = v1 - v2;
		break;
	case 2:
		result1 = v1 * v2;
		break;
	case 3:
		result1 = v1 / v2;
		break;
	}

	ll v3 = s[end - 3], v4 = s[end - 1];
	char oper2 = (s[end - 2] == '+' ? 0 : (s[end - 2] == '-' ? 1 : (s[end - 2] == '*' ? 2 : 3)));
	ll result2 = 0;
	switch (oper2) {
	case 0:
		result2 = v3 + v4;
		break;
	case 1:
		result2 = v3 - v4;
		break;
	case 2:
		result2 = v3 * v4;
		break;
	case 3:
		result2 = v3 / v4;
		break;
	}
	if (oper1 / 2 > oper2 / 2) {
		s[start + 2] = result1;
		return recur(start + 2, end);
	}
	else if (oper1 / 2 < oper2 / 2) {
		s[end - 3] = result2;
		return recur(start, end - 2);
	}
	else {
		if (result1 >= result2) {
			s[start + 2] = result1;
			return recur(start + 2, end);
		}
		else {
			s[end - 3] = result2;
			return recur(start, end - 2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string t;
	cin >> t;
	ll temp = 0;
	bool isd = false;
	for (int i = (t[0] == '-' ? 1 : 0); i < t.size(); ++i) {
		if (isdigit(t[i])) {
			temp = temp * 10 + t[i] - '0';
			isd = true;
		}
		else {
			if (isd) {
				s.emplace_back(temp);
				temp = 0;
				isd = false;
			}
			s.emplace_back(t[i]);

		}
	}
	if (isd)
		s.emplace_back(temp);
	if (t[0] == '-')
		s[0] = -s[0];

	cout << recur(0, s.size()) << endl;

	return 0;
}