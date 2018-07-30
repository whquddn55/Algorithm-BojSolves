#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 200005

int n, m;

void get(vector<int>& picked, int remain) {
	if (remain == 0) {
		for (auto e : picked)
			cout << e << ' ';
		cout << endl;
		return;
	}

	for (int i = picked.empty() ? 1 : picked.back(); i <= n; i++) {
		picked.push_back(i);
		get(picked, remain - 1);
		picked.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;

	vector<int> picked;
	get(picked, m);

	return 0;
}