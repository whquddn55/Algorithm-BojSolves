#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> str;

void pick(int n, vector<int>&picked, int toPick)
{
	if (toPick == 0)
	{
		int vowC = 0;
		int consC = 0;
		for (int i = 0; i < picked.size(); i++)
		{
			if (str[picked[i]] == "a") vowC++;
			else if (str[picked[i]] == "e") vowC++;
			else if (str[picked[i]] == "o") vowC++;
			else if (str[picked[i]] == "u") vowC++;
			else if (str[picked[i]] == "i") vowC++;
			else consC++;
		}
		if (vowC > 0 && consC > 1)
		{
			for (int i = 0; i < picked.size(); i++)
			{
				cout << str[picked[i]];
			}
			cout << endl;
		}
		return;
	}
	int small = picked.empty() ? 0 : picked.back() + 1;
	for (int next = small; next < n; next++)
	{
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}

}

int main()
{
	int  L, C;

	string temp;
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> temp;
		str.push_back(temp);
	}
	sort(str.begin(), str.end());

	vector<int>picked;
	pick(C, picked, L);
	getchar();
	getchar();
	getchar();
	return 0;
}