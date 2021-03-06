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

#define MAX_N 30005
#define MOD 1000000007

int n, m;
list<int> a;
list<int> b;
list<int> fa;
list<int> fb;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int t1, t2;
		cin >> t1 >> t2;
		a.emplace_back(t1);
		b.emplace_back(t2);
	}

	while (true) {
		fa.push_front(a.back());
		a.pop_back();
		if (!a.size())
			break;
		
		if (fa.size() && fb.size()) {
			if (fa.front() + fb.front() == 5) {
				b.splice(b.begin(), fa);
				b.splice(b.begin(), fb);
			}
		}
		if ((fa.size() && fa.front() == 5) || (fb.size() && fb.front() == 5)) {
			a.splice(a.begin(), fb);
			a.splice(a.begin(), fa);
		}

		m--;
		if (!m)
			break;

		fb.push_front(b.back());
		b.pop_back();
		if (!b.size()) 
			break;
		if (fa.size() && fb.size()) {
			if (fa.front() + fb.front() == 5) {
				b.splice(b.begin(), fa);
				b.splice(b.begin(), fb);
			}
		}
		if ((fa.size() && fa.front() == 5) || (fb.size() && fb.front() == 5)) {
			a.splice(a.begin(), fb);
			a.splice(a.begin(), fa);
		}

		m--;
		if (!m)
			break;
	}
	if (a.size() > b.size())
		cout << "do" << endl;
	else if (a.size() < b.size())
		cout << "su" << endl;
	else
		cout << "dosu" << endl;
	
	return 0;
}