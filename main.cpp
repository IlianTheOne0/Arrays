#include <iostream>
#include <conio.h>
#include <random>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::pair;

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

pair<unsigned long long, int> _negative_numbers_finder(long long* list, int size)
{
	unsigned long long number = list[0];
	int first_index = -1;
	int last_index = -1;

	for (int i = 0; i <= size; i++)
	{	
		if (list[i] < 0)
		{
			if (first_index < 0)
			{
				first_index = i;
				
				continue;
			}

			last_index = i;
		}
	}

	return { first_index, last_index };
}

int main()
{
	// init
	const unsigned int size = 10;
	long long list[size];
	long long value;

	long long sum_of_negative_numbers = 0;
	long long product_min_btw_max = 1;
	long long product_even_indexes = 1;
	long long sum_first_btw_last_negative = 0;

	// random
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(-10, 10);

	// array generation
	cout << "Array: ";

	for (int i = 0; i <= size; i++)
	{
		 value = dist(rd);

		 if (value == 0)
		 {
			 continue;
		 }

		 list[i] = value;

		cout << list[i] << " ";

		if (list[i] < 0)
		{
			sum_of_negative_numbers += list[i];
		}
	}

	// first, second and third task
	long long min_number_index = _min(list, size);
	long long max_number_index = _max(list, size);

	if (max_number_index < min_number_index)
	{
		int temp = max_number_index;
		max_number_index = min_number_index;
		min_number_index = temp;
	}
	

	for (int i = min_number_index + 1; i < max_number_index; i++)
	{
		product_min_btw_max *= list[i];
	}

	for (int i = 0; i <= size; i += 2)
	{
		product_even_indexes *= list[i];
	}

	// fourth task
	pair<unsigned long long, int> negative_numbers_indexes = _negative_numbers_finder(list, size);

	cout << endl << endl;
	
	for (int i = negative_numbers_indexes.first + 1; i < negative_numbers_indexes.second; i++)
	{
		sum_first_btw_last_negative += list[i];
	}

	// cout
	//cout << endl << min_number_index << " " << max_number_index << endl;
	//cout << negative_numbers_indexes.first << " " << negative_numbers_indexes.second << endl;

	cout << endl << endl;
	cout << "The sum of negative numbers: " << sum_of_negative_numbers << endl;
	cout << "Product of elements that are between min and max elements: " << product_min_btw_max << endl;
	cout << "Product of elements with even numbers: " << product_even_indexes << endl;
	cout << "Sum of the elements between the first and last negative elements: " << sum_first_btw_last_negative << endl;

	// default
	_getch();
	return 0;
}
