#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 101

int n, k;
int arr[] = { 0, 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000 };
ll sum = 0;
string str;
char temp[100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;

	if (k <= 9) {
		if (n < k)
			cout << -1 << endl;
		else
			cout << k;
		return 0;
	}
	int s = 0;
	for (int i = 1; i <= 9; i++) {
		if (k > arr[i] * (long long)i) {
			k -= arr[i] * i;
			s += arr[i];
		}
		else {
			int t = 1;
			while (t < n)
				t *= 10;
			t /= 10;
			sum += (n - t + 1) * i;
			if (sum < k)
				cout << -1 << endl;
			else {
				int num = s + (k - 1) / i + 1;
				int d = i - (k + i - 1) % i;
				for (int i = 1; i < d; i++)
					num /= 10;
				cout << num % 10;
			}
			break;
		}
		}
	

	return 0;
}