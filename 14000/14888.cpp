#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 11

int n;
int arr[MAX_N];
int oper[4];
int minValue = INT_MAX, maxValue = -INT_MAX;

void get(int num, int idx, int a, int b, int c, int d) {
	if (idx == n) {
		minValue = min(minValue, num);
		maxValue = max(maxValue, num);
	}

	if (a)
		get(num + arr[idx], idx + 1, a - 1, b, c, d);
	if (b)
		get(num - arr[idx], idx + 1, a, b - 1, c, d);
	if (c)
		get(num * arr[idx], idx + 1, a, b, c - 1, d);
	if (d)
		get(num / arr[idx], idx + 1, a, b, c, d - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	get(arr[0], 1, oper[0], oper[1], oper[2], oper[3]);

	cout << maxValue << endl << minValue << endl;

	return 0;
}
