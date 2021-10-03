#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t T;
	cin >> T;

	while (T--) {
		size_t N, K;
		cin >> N >> K;

		K = min(N, K);
		cout << 2 * (2 * N - K) * (K + 1) << "\n";
	}
}