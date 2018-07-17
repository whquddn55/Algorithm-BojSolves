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

#define MAX_N 100000

int n;
pii arr[MAX_N];
vector<pii> a;
vector<pii> b;

int aIndex = 0, bIndex = 0;
int ans = 1;

bool across(const pii& a, const pii& b) {
	return (a.first < b.first) != (a.second < b.second);
}

void makeAB() {
	int lastIndex = -1;
	for (int i = 0; i < n; i++)
		if (lastIndex == -1 || !across(arr[lastIndex], arr[i])) {
			a.emplace_back(arr[i]);
			lastIndex = i;
		}
		else
			b.emplace_back(arr[i]);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	
	makeAB();

	while ((aIndex < a.size()) && (bIndex < b.size())) {
		if (across(a[aIndex], b[bIndex])) {
			int taIndex = aIndex, tbIndex = bIndex;

			int value = 0;
			int cnt = 2;
			while (true) {
				if (value <= 0 && aIndex + 1 < a.size() && across(a[aIndex + 1], b[bIndex])) {
					aIndex++;
					cnt++;
					value = 1;
				}
				else if (value >= 0 && bIndex + 1 < b.size() && across(a[aIndex], b[bIndex + 1])) {
					bIndex++;
					cnt++;
					value = -1;
				}
				else if (aIndex + 1 < a.size() && across(a[aIndex + 1], b[bIndex]))
					aIndex++;
				else if (bIndex + 1 < b.size() && across(a[aIndex], b[bIndex + 1]))
					bIndex++;
				else
					break;
			}
			ans = max(ans, cnt);

			aIndex = taIndex;
			bIndex = tbIndex;
			value = 0;
			cnt = 2;

			while (true) {
				if (value >= 0 && bIndex + 1 < b.size() && across(a[aIndex], b[bIndex + 1])) {
					bIndex++;
					cnt++;
					value = -1;
				}
				else if (value <= 0 && aIndex + 1 < a.size() && across(a[aIndex + 1], b[bIndex])) {
					aIndex++;
					cnt++;
					value = 1;
				}
				else if (bIndex + 1 < b.size() && across(a[aIndex], b[bIndex + 1]))
					bIndex++;
				else if (aIndex + 1 < a.size() && across(a[aIndex + 1], b[bIndex]))
					aIndex++;
				else
					break;
			}
			ans = max(ans, cnt);
			aIndex++;
			bIndex++;
		}
		else {
			if (a[aIndex].first < b[bIndex].first)
				aIndex++;
			else
				bIndex++;
		}
	}
	cout << ans << endl;

	return 0;
}