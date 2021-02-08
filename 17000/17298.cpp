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

#define MAX_N 1000005

int n;
int arr[MAX_N];
stack<int> s;
stack<int> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = n - 1; i >= 0; --i) {
		while (s.size() && arr[i] >= s.top())
			s.pop();
		if (s.empty()) 
			ans.push(-1);
		else 
			ans.push(s.top());
		s.push(arr[i]);
	}

	while (ans.size()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	
	return 0;
}