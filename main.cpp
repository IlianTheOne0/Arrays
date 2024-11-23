#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	const unsigned int size = 10;
	unsigned long long list[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Inverted array: " << endl;

	for (int i = 9; i >= 0; i--)
	{
		cout << list[i] << endl;
	}

	_getch();
	return 0;
}