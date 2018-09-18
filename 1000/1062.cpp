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

int n, k;
string arr[MAX_N];
vector<int> picked;

int ans = 0;

void pick(int toPick) {
	if (picked.size() == k) {
		int cnt = 0;
		vector<int> temp = picked;
		sort(temp.begin(), temp.end());
		for (int i = 0; i < n; i++) {
			bool canRead = true;
			for (auto& e : arr[i])
				if (!binary_search(temp.begin(), temp.end(), e)) {
					canRead = false;
					break;
				}
			if (canRead)
				++cnt;
		}
		ans = max(ans, cnt);

		return;
	}
	if (toPick == 26)
		return;
	if (toPick == 0 || toPick == 2 || toPick == 8 || toPick == 13 || toPick == 19)
		pick(toPick + 1);
	else {
		picked.emplace_back(toPick + 'a');
		pick(toPick + 1);
		picked.pop_back();
		pick(toPick + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		arr[i] = temp.substr(4, temp.size() - 8);
	}
	picked.emplace_back('a');
	picked.emplace_back('c');
	picked.emplace_back('i');
	picked.emplace_back('n');
	picked.emplace_back('t');

	if (k >= 5)
		pick(0);
	cout << ans << endl;

	return 0;
}