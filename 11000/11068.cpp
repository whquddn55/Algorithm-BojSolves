#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

string getString(int number, int mod) {
	string result;
	while (number) {
		result.push_back(number % mod);
		number /= mod;
	}
	return result;
}

bool isSame(int number) {
	bool result = false;
	for (int i = 2; i <= 64; i++) {
		string s = getString(number, i);

		bool check = true;
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - i - 1]) {
				check = false;
				break;
			}
		}
		if (result = check)
			break;
	}
	return result;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int number;
		scanf("%d", &number);
		printf("%d\n", isSame(number));
	}


	return 0;
}