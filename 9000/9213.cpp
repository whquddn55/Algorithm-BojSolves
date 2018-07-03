#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 1000001

int start, stop, badness;
bool isPrime[MAX_N];
ll diff[MAX_N];
vector<int> primes[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	fill(isPrime, isPrime + MAX_N, 1);
	for (int i = 2; i <= MAX_N; ++i)
		if (isPrime[i]) {
			primes[i].push_back(i);
			for (int j = i * 2; j <= MAX_N; j += i) {
				isPrime[j] = false;
				primes[j].push_back(i);
			}
		}

	for (int i = 2; i <= MAX_N; i++) {
		diff[i] = i + i;
		ll value = 1;
		for (int e : primes[i]) {
			int t = i;
			int cnt = 0;
			while (t % e == 0 && t) {
				t /= e;
				cnt++;
			}
			ll bottom = e - 1;
			ll top = 1;
			for (int j = 0; j < cnt + 1; j++)
				top *= e;
			top--;
			value *= top / bottom;
		}
		diff[i] -= value;
		diff[i] = diff[i] < 0 ? -diff[i] : diff[i];
	}



	int tc = 1;
	while (true) {
		cin >> start >> stop >> badness;
		if (start == 0 && stop == 0 && badness == 0)
			break;
		cout << "Test " << tc++ << ": ";

		int ans = 0;
		for (int i = start; i <= stop; i++) {
			if (diff[i] <= badness)
				ans++;
		}
		cout << ans << endl;
	}

	return 0;
}
