#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	unsigned long long income[6];
	unsigned long long result = 0;

	for (int i = 0; i <= 5; i++) {
		cout << "Enter the income for " << (i + 1) << " month: ";
		cin >> income[i];
		result += income[i];
	}

	cout << "Result: " << result << endl;

	_getch();
	return 0;
}