#include <iostream>
#include <string>
using namespace std;

enum MONTH{JAN = 1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC };

int main() {
	int m, d;
	cin >> m >> d;

	int days = d - 1;
	while (m != 1) {
        m -= 1;
		switch (m) {
		case JAN:
		case MAR:
		case MAY:
		case JUL:
		case AUG:
		case OCT:
		case DEC:
			days += 31;
			break;
		case APR:
		case JUN:
		case SEP:
		case NOV:
			days += 30;
			break;
		case FEB:
			days += 28;
			break;
		}
	}

	string result;
	switch (days % 7) {
	case 0:
		result = "MON";
		break;
	case 1:
		result = "TUE";
		break;
	case 2:
		result = "WED";
		break;
	case 3:
		result = "THU";
		break;
	case 4:
		result = "FRI";
		break;
	case 5:
		result = "SAT";
		break;
	case 6:
		result = "SUN";
		break;
	}
	cout << result << '\n';
	return 0;
}