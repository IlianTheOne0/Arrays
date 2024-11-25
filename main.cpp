#include <iostream>
#include <conio.h>
#include <random>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

int _max(long long* list, int size)
{
	long long max = list[0];
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (list[i] >= max)
		{
			max = list[i];
			index = i;
		}
	}

	return index;
}

int _min(long long* list, int size)
{
	long long min = list[0];
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (list[i] <= min)
		{
			min = list[i];
			index = i;
		}
	}

	return index;
}


int main()
{
	const unsigned int size = 10;
	long long list[size];

	long long sum_of_negative_numbers = 0;
	long long product_min_btw_max = 1;
	long long product_even_indexes = 1;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(-10, 10);

	cout << "Array: ";

	for (int i = 0; i <= 9; i++)
	{
		list[i] = dist(rd);
		cout << list[i] << " ";

		if (list[i] < 0)
		{
			sum_of_negative_numbers += list[i];
		}
	}

	long long max_number_index = _max(list, size);
	long long min_number_index = _min(list, size);

	for (int i = min_number_index; i <= max_number_index; i++)
	{
		product_min_btw_max *= list[i];
	}

	for (int i = 0; i < size; i += 2)
	{
		product_even_indexes *= list[i];
	}

	cout << endl << endl;
	cout << "The sum of negative numbers: " << sum_of_negative_numbers << endl;
	cout << "Product of elements that are between min and max elements: " << product_min_btw_max << endl;
	cout << "Product of elements with even numbers: " << product_even_indexes << endl;

	_getch();
	return 0;
}