#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	string a, b;
	cin >> a >> b;

	while (a[a.size() - 1] == '0')
		a.pop_back();
	while (b[b.size() - 1] == '0')
		b.pop_back();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int aNum = atoi(a.c_str());
	int bNum = atoi(b.c_str());

	char resultChar[10];
	sprintf(resultChar, "%d", aNum + bNum);

	string result(resultChar);
	while (result[result.size() - 1] == '0')
		result.pop_back();
	reverse(result.begin(), result.end());
	cout << result << endl;
	return 0;
}