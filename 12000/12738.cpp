#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 1000001

int n, m;
int arr1[MAX_N];

vector<int> lis;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];

	lis.push_back(arr1[0]);
	for (int i = 1; i < n; i++) {
		auto it = lower_bound(lis.begin(), lis.end(), arr1[i]);
		if (it == lis.end()) 
			lis.push_back(arr1[i]);
		
		else
			lis[it - lis.begin()] = arr1[i];
	}

	cout << lis.size() << endl;

	return 0;
}