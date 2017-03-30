#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;

	int row = 1, column = 1;
	int value,prevColumnHead = 1,prevRowHead = 1;
	while(true)
	{
		row = 1;
		value = prevColumnHead + ((column % 2 == 0) ? 1 : (column / 2) * 4);
		prevColumnHead = value;
		while (true)
		{
			if (value == x) {
				cout << row << '/' << column << endl;
				return 0;
			}
			else if (value > x)
				break;
			row++;
			prevRowHead = value;
			value = prevRowHead + ((row % 2 == 0) ? (column % 2 == 0 ?  2 * column - 1 : (((row - 1) / 2) * 4 + 2) ) : (column % 2 == 0 ? ((row / 2) * 4) : 2 * column - 1));
		}
		column++;
	}
	return 0;
}