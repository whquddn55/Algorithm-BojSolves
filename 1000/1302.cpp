#include <iostream>
#include <string>
using namespace std;

void getBookTitle(string* const book, const unsigned int strCount);
void sortBooks(string* const book, const unsigned int strCount);
int* countBook(const string* const book, const unsigned int strCount);
void printBestseller(const string* const book, const int* const counts,const unsigned int strCount);

int main()
{
	unsigned int strCount;
	cin >> strCount;

	string* const book = new string[strCount];

	getBookTitle(book,strCount);
	sortBooks(book, strCount);
	int* const counts = countBook(book, strCount);

	printBestseller(book, counts,strCount);

	return 0;
}

void getBookTitle(string* const book, const unsigned int strCount)
{
	for (unsigned int i = 0; i < strCount; i++)
		cin >> book[i];
}

void sortBooks(string* const book, const unsigned int strCount)
{
	string temp;
	for (int i = 0; i < strCount; i++)
		for (int j = i + 1; j < strCount; j++)
			if (book[i].compare(book[j]) > 0)
			{
				temp = book[i];
				book[i] = book[j];
				book[j] = temp;
			}
}

int* countBook(const string* const book, const unsigned int strCount)
{
	int* const counts = new int[strCount];

	for (int i = 0; i < strCount; i++)
		counts[i] = 1;

	for (int i = 0; i < strCount; i++)
	{
		if (counts[i] == -1)
			continue;
		for (int j = i + 1; j < strCount; j++)
		{
			if (counts[j] == -1)
				continue;
			
			if (!book[i].compare(book[j]))
			{
				counts[i]++;
				counts[j] = -1;
			}
		}
	}

	return counts;
}

void printBestseller(const string* const book, const int* const counts, const unsigned int strCount)
{
	int max = 1;
	int index = 0;
	for (unsigned int i = 0; i < strCount; i++)
		if (counts[i] > max) {
			max = counts[i];
			index = i;
		}
	cout << book[index] << endl;
}