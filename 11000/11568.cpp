#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 1001

int n;
int arr[MAX_SIZE];
vector<int> lis;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	lis.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (arr[i] > lis.back())
			lis.push_back(arr[i]);
		else
			lis[lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin()] = arr[i];
	}

	cout << lis.size() << endl;


	return 0;
}
