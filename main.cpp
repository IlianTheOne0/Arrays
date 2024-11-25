#include <iostream>
#include <conio.h>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::pair;
using std::string;

pair<unsigned long long, int> _max(unsigned long long* list, int start, int end)
{
    unsigned long long max = list[start];
    int month = start;

    for (int i = start; i <= end; i++)
    {
        if (list[i] >= max)
        {
            max = list[i];
            month = i;
        }
    }

    return { max, month };
}

pair<unsigned long long, int> _min(unsigned long long* list, int start, int end)
{
    unsigned long long min = list[start];
    int month = start;

    for (int i = start; i <= end; i++)
    {
        if (list[i] <= min)
        {
            min = list[i];
            month = i;
        }
    }

    return { min, month };
}

int range_input(string state)
{
    int number;

    do
    {
        cout << "Enter the "<< state <<" of the range: ";
        cin >> number;

        if (number >= 1 && number <= 12)
        {
            break;
        }
        else {
            cout << "Incorrect input" << endl;
        }

    } while (true);

    return number - 1;
}

int main()
{
    const unsigned int size = 12;
    unsigned long long income[size];

    for (int i = 0; i <= 11; i++) {
        cout << "Enter the income for " << (i + 1) << " month: ";
        cin >> income[i];
    }

    cout << endl;

    int min_range = range_input("start");
    int max_range = range_input("end");

    cout << endl;

    if (max_range < min_range)
    {
        int temp = max_range;
        max_range = min_range;
        min_range = temp;
    }

    pair<unsigned long long, int> max_ = _max(income, min_range, max_range);
    pair<unsigned long long, int> min_ = _min(income, min_range, max_range);

    cout << "The highest income in range was in month " << (max_.second + 1) << ": " << max_.first << endl;
    cout << "The lowest income in range was in month " << (min_.second + 1) << ": " << min_.first << endl;

    _getch();
    return 0;
}
