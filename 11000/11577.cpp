#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 100001

int n, k;
bool arr[MAX_N];
bool b[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	b[0] = arr[0];
	for (int i = 1; i < n; i++)
		b[i] = arr[i] ^ arr[i - 1];

	int cnt = 0;
	for (int i = 0; i <= n - k; i++)
		if (b[i]) {
			b[i] = !b[i];
			if (i + k != n)
				b[i + k] = !b[i + k];
			cnt++;
		}

	bool ans = true;
	for (int i = n - k + 1; i < n; i++)
		if (b[i])
			ans = false;

	if (ans)
		cout << cnt << endl;
	else
		cout << "Insomnia" << endl;

	return 0;
}