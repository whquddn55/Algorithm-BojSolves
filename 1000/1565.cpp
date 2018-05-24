#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 51

int n, m;
int arr1[MAX_N];
int arr2[MAX_N];
vector<int> a;

ll gc = 0;
int ans = 0;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	for (int i = 0; i < m; i++)
		cin >> arr2[i];

	gc = arr2[0];
	for (int i = 1; i < m; i++)
		gc = gcd(gc, arr2[i]);

	for (int i = 1; i <= sqrt(gc); i++) 
		if (gc % i == 0) {
			a.push_back(i);
			if (i != gc / i)
				a.push_back(gc / i);
		}
	
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		bool check = true;
		for (int j = 0; j < n; j++)
			if (a[i] % arr1[j])
				check = false;
		if (check)
			ans++;
	}
	cout << ans << endl;

	return 0;
}