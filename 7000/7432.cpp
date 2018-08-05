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
#define MAX_N 500

int n;
string arr[MAX_N];

void get(int start, int end, int sIndex, int depth) {
	while (start < end && arr[start].size() <= sIndex)
		start++;
	if (start == end)
		return;
	/*cout << pii(start, end) << ' ' << sIndex << endl;*/

	int last = start;
	int nextsIndex = find(arr[last].begin() + sIndex, arr[last].end(), ' ') - arr[last].begin(); // ' '의 위치
	string s = arr[last].substr(sIndex, nextsIndex - sIndex);
	
	for (int i = start; i < end; i++) {
		string temp;
		if (arr[i].size() < sIndex)
			temp = "";
		else
			temp = arr[i].substr(sIndex, find(arr[i].begin() + sIndex, arr[i].end(), ' ') - arr[i].begin() - sIndex);
		if (temp != s) {
			int t = depth;
			while (t--)
				cout << ' ';
			cout << s << endl;
			get(last, i, nextsIndex + 1, depth + 1);

			last = i;
			nextsIndex = find(arr[last].begin() + sIndex, arr[last].end(), ' ') - arr[last].begin();
			s = arr[last].substr(sIndex, nextsIndex - sIndex);
		}
	}
	int t = depth;
	while (t--)
		cout << ' ';
	cout << s << endl;
	get(last, end, nextsIndex + 1, depth + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (auto& e : arr[i])
			if (e == '\\')
				e = ' ';
	}
	sort(arr, arr + n);
	/*for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
	cout << endl;*/

	get(0, n, 0, 0);

	return 0;
}
