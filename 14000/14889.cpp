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

#define MAX_N 20

int n;
int arr[MAX_N][MAX_N];
int sum;
int ans = INF;

vector<int> team1;
vector<int> team2;

void get(int toPick, int score1, int score2) {
	if (team1.size() == n / 2 && team2.size() == n / 2) {
		ans = min(ans, abs(score1 - score2));
		return;
	}
	if (toPick == n)
		return;
	team1.emplace_back(toPick);
	int value = 0;
	for (auto e : team1)
		value += arr[e][toPick] + arr[toPick][e];
	get(toPick + 1, score1 + value, score2);
	team1.pop_back();

	team2.emplace_back(toPick);
	value = 0;
	for (auto e : team2)
		value += arr[e][toPick] + arr[toPick][e];
	get(toPick + 1, score1, score2 + value);
	team2.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
		
	get(0, 0, 0);
	cout << ans << endl;
	
	return 0;
}