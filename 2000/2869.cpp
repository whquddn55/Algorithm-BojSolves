#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;

	int last = v - a;
	int days = last / (a - b) + 1;
	if (last % (b - a))
		days++;

	cout << days << endl;

	return 0;
}