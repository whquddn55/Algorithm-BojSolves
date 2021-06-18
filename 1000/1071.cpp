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
#define MAX_N 50
#define MOD 1000000007

int n;
int arr[MAX_N];
bool checked[MAX_N];
list<int> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	sort(arr, arr + n);

	int prv = -2;
	while(ans.size() < n) {
		bool flag = false;
		for (int i = 0; i < n; ++i)
			if (!checked[i] && arr[i] != prv + 1) {
				ans.push_back(arr[i]);
				prv = arr[i];
				checked[i] = true;
				flag = true;
				break;
			}
		if (!flag)
			break;
	}

	if (ans.size() < n) {
		auto it = ans.rbegin();
		while(it != ans.rend()) {
			if (*it == ans.back()) {
				++it;
				continue;
			}
			break;
		}
		while(ans.size() < n)
			ans.insert(it.base(), arr[n - 1]);
	}

	for (auto e : ans)
		cout << e << ' ';
	
	
	
    return 0;
}