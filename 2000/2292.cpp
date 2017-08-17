#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int result = 1;
	int num = 1;
	while(true){
		num += 6 * (result - 1);
		if ( n <= num ){
			cout << result << endl;
			break;
		}
		result++;
	}

	return 0;
}
