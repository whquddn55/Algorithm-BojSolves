#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

int n;
set<long long> decrease;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
		decrease.insert(i);

	int cnt = 0;
	set<long long>::iterator it;
	for (it = decrease.begin(); it != decrease.end(); ++it) {
		if (cnt == n)
			break;
		cnt++;
		long long temp = *it;
		long long num = 1;
		while (true) {
			if (temp / 10 == 0)
				break;
			temp /= 10;
			num *= 10;
		}
		temp++;
		num *= 10;
		for (int j = temp; j < 10; j++) 
			decrease.insert(*it + num * j);
	}
	printf("%lld\n", it != decrease.end() ? *it : -1);


	return 0;
}