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
#define MAX_K 10

int k;
int arr[1 << MAX_K];
vector<int> ans[MAX_K];

void get(int start, int end, int depth) {
	if (start == end)
		return;
	get(start, (start + end) / 2, depth + 1);
	ans[depth].push_back(arr[(end + start) / 2]);
	get((start + end) / 2 + 1, end, depth + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> k;
	for (int i = 0; i < (1 << k) - 1; i++)
		cin >> arr[i];

	get(0, (1 << k)- 1, 0);
	for (int i = 0; i < k; i++) {
		for (auto e : ans[i])
			cout << e << ' ';
		cout << endl;
	}

	return 0;
}
