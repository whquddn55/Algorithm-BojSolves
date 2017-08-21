#include <iostream>
using namespace std;

#define MAXSIZE 1000000

int a[MAXSIZE];

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int b, c;
	cin >> b >> c;

	long long result = 0;
	for(int i = 0; i < n; i++){
		if (a[i] < b){
			result++;
			continue;
		}
		result += (((a[i] - b) % c == 0) ? ((a[i] - b) / c) : ((a[i] - b) / c + 1)) + 1;
	}

	cout << result << endl;

	return 0;
}

