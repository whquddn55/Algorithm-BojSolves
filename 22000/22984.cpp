#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<long double> v(N);
	long double sum = 0;
	for (auto& c : v) {
		cin >> c;
		sum += c;
	}

	for (size_t i = 1; i != N; ++i)
		sum += (1 - v[i - 1]) * v[i] + (1 - v[i]) * v[i - 1];
	
	cout << fixed;
	cout.precision(15);
	cout << sum;
}