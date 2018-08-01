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

#define MAX_N 9

int n, k;
int arr[MAX_N];
bool used[MAX_N];
string str;

string ans;
bool flag = false;

void place2(int index, int num) {
	if (index == 5) {
		if (num == 0) {
			ans = str;
			flag = (k == 0);
			k--;
		}
		return;
	}
	if (!flag) {
		str.push_back(0);
		place2(index + 1, num);
		str.pop_back();
	}
	for (int i = 0; i < n && !flag; i++) {
		if (used[i])
			continue;
		if (num - arr[i] * (index + 1) < 0)
			continue;
		str.push_back(arr[i]);
		used[i] = true;
		place2(index + 1, num - arr[i] * (index + 1));
		str.pop_back();
		used[i] = false;
	}
}

void place(int index, int num) {
	if (index == -1) {
		place2(0, num);
		return;
	}
	if (!flag) {
		str.push_back(0);
		place(index - 1, num);
		str.pop_back();
	}
	for (int i = 0; i < n && !flag; i++) {
		if (used[i])
			continue;
		str.push_back(arr[i]);
		used[i] = true;
		place(index - 1, num + arr[i] * (index + 1));
		str.pop_back();
		used[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> k;

	sort(arr, arr + n);

	place(4, 0);

	for (auto& e : ans)
		e += '0';
	cout << stoll(ans) << endl;


	return 0;
}