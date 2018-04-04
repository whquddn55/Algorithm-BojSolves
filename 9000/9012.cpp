#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		bool stackempty = true;
		string a;
		cin >> a;
		stack <char> stack;
		int size = a.size();
		for (int i = 0; i < size; i++)
		{
			if (a[i] == '(')
				stack.push('(');
			else if (a[i] == ')')
			{
				if (stack.empty())
				{
					stackempty = false;
					break;
				}
				else
					stack.pop();
			}
		}
		if (!stackempty)
		{
			cout << "NO\n";
		}
		else {
			if (stack.empty())
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}