#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;
using std::pair;

pair<unsigned long long, int> _max(unsigned long long* list)
{
    unsigned long long max = list[0];
    int month = 0;

    for (int i = 1; i <= 11; i++)
    {
        if (list[i] >= max)
        {
            max = list[i];
            month = i;
        }
    }

    return { max, month };
}

pair<unsigned long long, int> _min(unsigned long long* list)
{
    unsigned long long min = list[0];
    int month = 0;

    for (int i = 1; i <= 11; i++)
    {
        if (list[i] <= min)
        {
            min = list[i];
            month = i;
        }
    }

    return { min, month };
}

int main()
{
    const unsigned int size = 12;
    unsigned long long income[size];

    for (int i = 0; i <= 11; i++) {
        cout << "Enter the income for " << (i + 1) << " month: ";
        cin >> income[i];
    }

    pair<unsigned long long, int> max_ = _max(income);
    pair<unsigned long long, int> min_ = _min(income);

    cout << "The highest income was in month " << (max_.second + 1) << ": " << max_.first << endl;
    cout << "The lowest income was in month " << (min_.second + 1) << ": " << min_.first << endl;

    _getch();
    return 0;
}
