#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	const int size = 5;
	unsigned long long length[size];
	unsigned long long result = 0;

	for (int i = 1; i <= 5; i++)
	{
		cout << "Enter the length of " << i << " side: ";
		cin >> length[i];

		result += length[i];
	}

	cout << "The perimeter of the pentagon: " << result << endl;

	_getch();
	return 0;
}