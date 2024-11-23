#include <iostream>
#include <conio.h>
#include <random>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

int _max(unsigned long long* list)
{
    unsigned long long max = list[0];

    for (int i = 0; i <= 9; i++)
    {
        if (list[i] >= max)
        {
            max = list[i];
        }
    }

    return max;
}

int _min(unsigned long long* list)
{
    unsigned long long min = list[0];

    for (int i = 0; i <= 9; i++)
    {
        if (list[i] <= min)
        {
            min = list[i];
        }
    }

    return min;
}

int main()
{
	const int size = 10;
	unsigned long long list[size];

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 100);

    cout << "Array: ";

	for (int i = 0; i <= 9; i++)
	{
        list[i] = dist(rd);
        cout << list[i] << " ";
	}

    cout << endl << endl << "Min: " << _min(list) << endl;
    cout << "Max: " << _max(list) << endl;

	_getch();
	return 0;
}