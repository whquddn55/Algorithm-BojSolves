#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)

#define MAX_N 1000000

int n;
int arr[MAX_N];
vector<int> lis;
vector<int> ret;
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	lis.push_back(arr[0]);
	ret.push_back(0);
	for (int i = 1; i < n; i++) {
		auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (it == lis.end()) {
			lis.push_back(arr[i]); 
			ret.push_back(lis.size() - 1);
		}
		else {
			lis[it - lis.begin()] = arr[i];
			ret.push_back(it - lis.begin());
		}
	}

	int toPrint = lis.size() - 1;
	for (int i = n - 1; i >= 0; i--)
		if (ret[i] == toPrint) {
			st.push(arr[i]);
			toPrint--;
		}

	cout << lis.size() << endl;
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}

	
	return 0;
}