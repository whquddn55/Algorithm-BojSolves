#include <iostream>
using namespace std;

int getNumbers(char* num);
unsigned long long calcResult(char* n, char* m, const int nLen, const int mLen);

int main()
{
	char n[10000];
	char m[10000];
	
	const int nLen = getNumbers(n);
	const int mLen = getNumbers(m);

	cout << calcResult(n,m,nLen,mLen) << endl;

	return 0;
}

int getNumbers(char* num)
{
	unsigned int cnt = 0;
	while (true)
	{
		num[cnt] = cin.get();
		if (num[cnt] == ' ' || num[cnt] == '\n')
			break;
		cnt++;
	}

	return cnt;
}

unsigned long long calcResult(char* n, char* m, const int nLen, const int mLen)
{
	unsigned long long result = 0;
	for (unsigned int i = 0; i < nLen; i++)
		for (unsigned int j = 0; j < mLen; j++)
			result += (n[i] - '0') * (m[j] - '0');

	return result;
}