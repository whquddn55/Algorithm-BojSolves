#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n, m;
vector<int> arr;
vector<int> iter;
set<int> s;
vector<int> ans;
vector<bool> isRain;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		arr.clear();
		iter.clear();
		s.clear();
		ans.clear();
		isRain.clear();

		cin >> n >> m;
		arr.resize(m);
		iter.resize(n + 1, 0);
		ans.resize(m, 0);
		isRain.resize(m, false);

		for (int i = 0; i < m; i++)
			cin >> arr[i];

		bool result = true;
		for (int i = 0; i < m; i++) {
			if (arr[i] == 0)
				s.insert(i);
			else {
				auto it = s.lower_bound(iter[arr[i]]);
 				if (it == s.end()) {
					result = false;
					break;
				}
				ans[*it] = arr[i];
				s.erase(it);

				iter[arr[i]] = i + 1;
				isRain[i] = true;
			}
		}

		if (!result) 
			cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for (int i = 0; i < m; i++)
				if (!isRain[i])
					cout << (int)ans[i] << ' ';
			cout << endl;
		}
		
	}

	return 0;
}
