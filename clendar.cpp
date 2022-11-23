#include<bits/stdc++.h>
using namespace std;
int first_weekDay(int year)
{
    int day;
    day = (((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;

    return day;
}
int leap_year(int year)
{
    if (year % 400 == 0)
        return true;

    else if (year % 4 == 0 and year % 100 != 0)
        return true;

    else
        return false;
}
int main()
{
    int Year, Month, Day, days_in_month, weekDay=0, startingDay;

    cout << "Enter your Birthday Year = ";
    cin >> Year;

    cout << "Enter your Birthday Month = ";
    cin >> Month;

    cout << "Enter your Birthday date = ";
    cin >> Day;

    //cin >> year;
    string month[] = {"January", "February", "March", "April", "*May*", "June", "July",
    "August","September","October","November","December"};

    int month_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (leap_year(Year))
    {
        month_day[1] = 29;
    }
    startingDay = first_weekDay(Year);

    for (int i = 0; i < 12; i++)
    {
        days_in_month = month_day[i];

        cout << endl << endl<<"   ------------" << month[i] << "------------" << endl;

        cout << endl << "   Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

        for (weekDay = 0; weekDay < startingDay; weekDay++)
        {
            cout << "     ";
        }
        for(int i=1; i<=days_in_month; i++)
        {
            printf("%5d",i);

            weekDay++;

            if (weekDay > 6)
                //(++weekDay>6)
            {
                printf("\n");
                weekDay = 0;
            }

            startingDay = weekDay;
        }
    }
}

