#include <iostream>
using namespace std;

int main()
{
	unsigned int n, k;
	unsigned int result;
	while (cin >> n >> k)
	{
		result = n;
		while (n >= k)
		{
			result += n / k;
			n = n / k + n % k;
		}
		cout << result << endl;
	}

	return 0;
}