#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 30

int C[MAXSIZE][MAXSIZE];

int get(const int n, const int r){
	if(r == 1)
		return n;
	if(n == r)
		return 1;
	if(C[n][r])
		return C[n][r];

	return C[n][r] = get(n - 1, r) + get(n - 1, r - 1);
}

int main() {
	int t;
	cin >> t;

	while(t--){
		int r, n;
		cin >> r >> n;

		cout << get(n, r) << endl;
	}


	return 0;
}
