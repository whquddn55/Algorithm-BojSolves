#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		double result;
		cin >> result;

		char c[1000];
		memset(c, 32, sizeof(c));
		cin.getline(c, 1000);

		for (int i = 0; i < 1000 && c[i] != '\n'; i++) {
			if (c[i] == ' ')
				continue;

			if (c[i] == '@')
				result *= 3;
			if (c[i] == '%') 
				result += 5;
			if (c[i] == '#') 
				result -= 7;
		}
		cout.precision(2);
		cout << fixed;
		cout << result << endl;
	}
}