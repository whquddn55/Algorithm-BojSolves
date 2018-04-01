#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define	MAX_SIZE 101

int n;
bool prizon[MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(prizon, 0, sizeof(prizon));
		cin >> n;

		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j += i)
				prizon[j] = !prizon[j];

		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += prizon[i];
		cout << ans << endl;
	}

	return 0;
}
