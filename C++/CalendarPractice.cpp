#include <iostream>
#include <string.h>

#ifdef MSDOS
#include <conio.h>
#endif
using namespace std;

void Calendar(int year, int month);
int GetUserInput(const char * name, int from = 0, int to = 0);

int main()
{
    int year, month;
    char control = 0;
    char menu[] = "< P > - Previous,  < N > - Next\n< D > - New date,  < E > - Exit\n";

    year = GetUserInput("Year");
    month = GetUserInput("Month", 1, 12);

    Calendar(year, month);
    cout << menu;

    do
    {
        bool Proceed = false;

#ifdef MSDOS
        Proceed = _kbhit();
#else
        Proceed = true;
#endif

        if (Proceed)
        {
#ifdef MSDOS
            control = _getch();
#else
            cin.get(control);
            cin.get();
#endif
            system("cls");

            switch (control)
            {
            case -32:
                continue;
                break;
            case 'P':
            case 'p':
            case 72:    // Up arrow
            case 75:    // Left arrow
                month--;
                if (month < 1)
                {
                    month += 12;
                    year -= 1;
                }
                break;
            case 'N':
            case 'n':
            case 13:    // Enter
            case 77:    // Right arrow
                month++;
                if (month > 12)
                {
                    month -= 12;
                    year += 1;
                }
                break;
            case 'D':
            case 'd':
                year = GetUserInput("Year");
                month = GetUserInput("Month", 1, 12);
                break;
            case 'E':
            case 'e':
                cout << "\n\tBye!\n";
                break;
            default:
                cout << "\n\tWrong input!\n\n";
                cout << menu;
                continue;
                break;
            }

            Calendar(year, month);
            cout << menu;
        }
    } while (control != 'e' && control != 'E');

    return 0;
}

int GetUserInput(const char * name, int from, int to)
{
    bool succeed = false;
    int value = 0;
    char buffer[10];
    do
    {
        cout << "Enter " << name << ": ";
        cin.getline(buffer, 10);
        value = atoi(buffer);

        if (from == to || value >= from && value <= to)
            succeed = true;
    } while (!succeed);

    return value;
}

void Calendar(int year, int month)
{
    char monthName[][10]
    {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int numberOfDaysInMonth, shift, empty;
    int daysInMonth[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    numberOfDaysInMonth = (month == 2 && year % 4 == 0) ? 29 : daysInMonth[month - 1];

    const int fixedYear = 2008;
    const int fixedEmpty[]{ 1, 4, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0 };

    int yearDiff = year - fixedYear;

    if (yearDiff > 0)
    {
        shift = yearDiff + yearDiff / 4;
        if (month <= 2 && year % 4 != 0)
            shift++;
    }
    else
    {
        shift = yearDiff - yearDiff / 4;
        if (month > 2 && year % 4 != 0)
            shift--;
    }

    empty = fixedEmpty[month - 1] + shift;

    empty = empty % 7;
    if (empty < 0)
        empty += 7;

    cout << " ....... " << monthName[month - 1] << " " << year << " ";
    int dots = 23 - strlen(monthName[month - 1]);
    for (int i = 0; i < dots; i++)
        cout << ".";
    cout << "\n Mo\tTu\tWe\tTh\tFr\tSa\tSu\t\n ";

    for (int e = 0; e < empty; e++)
        cout << "\t";
    for (int d = 1; d <= numberOfDaysInMonth; d++)
        cout << d << ((empty + d) % 7 == 0 ? "\n " : "\t");
    cout << "\n\n";
}
