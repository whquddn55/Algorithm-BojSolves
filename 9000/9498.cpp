#include <iostream>
using namespace std;

int main() {
	int score;
	cin >> score;

	char result;
	if (score >= 90 && score <= 100)
		result = 'A';
	else if (score >= 80 && score < 90)
		result = 'B';
	else if (score >= 70 && score < 80)
		result = 'C';
	else if (score >= 60 && score < 70)
		result = 'D';
	else
		result = 'F';
	
	cout << result << '\n';

	return 0;
}