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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 4005
#define MOD 1000003

string a, b;
set<vector<int>> s;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> a >> b;
	if (a.size() > b.size())
		swap(a, b);

	int ans = 0;
	for (int sz = a.size(); sz >= 1; --sz) {
		if (ans)
			break;
		s.clear();
		vector<int> arr(26, 0);
		for (int i = 0; i < a.size(); ++i) {
			arr[a[i] - 'a']++;
			if (i >= sz) 
				arr[a[i - sz] - 'a']--;
			
			if (i >= sz - 1)
				s.insert(arr);
		}

		vector<int> brr(26, 0);
		for (int i = 0; i < b.size(); ++i) {
			brr[b[i] - 'a']++;
			if (i >= sz) 
				brr[b[i - sz] - 'a']--;
			
			if (i >= sz - 1)
				if (s.find(brr) != s.end()) {
					ans = sz;
					break;
				}
		}
	}

	cout << ans << endl;
	
	return 0;
}
