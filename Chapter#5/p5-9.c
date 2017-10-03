#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth , int *pday);

main(){
    int month, day, year, doy, res;

    year = 2017;
    month = 10;
    day = 2;
    
    doy = day_of_year(year, month, day);
    if (doy > 0)
        printf("day_of_year = %d\n", doy);

    doy = 366;
    res = month_day(year, doy, &month, &day);

    if (res > 0)
        printf("month = %d, day = %d\n", month, day);

    return 0;
}

static int day_tab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static int leap_tab[] = {
    365,
    366
};

int day_of_year(int year, int month, int day){
    int i, leap;

    if (year < 0){
        printf("Wrong data!");
        return 0;
    }

    
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (
        month < 1  ||
        month > 12 ||
        day < 1 ||
        day > *(*day_tab + 13 * leap + month)
        ){
            printf("Wrong data!");
            return 0;
        }
    for (i = 1; i < month; i++)
        day += *(*day_tab + 13 * leap + i);
    return day;    
}

int month_day(int year, int yearday, int *pmonth , int *pday){
    int i, leap;
    if (year < 0){
        printf("Wrong data!");
        return 0;
    }

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (
        yearday < 1 ||
        yearday > *(leap_tab + leap)
        ){
            printf("Wrong data!");
            return 0;
        }

    for (i = 1; yearday > day_tab[leap][i]; i++)
        yearday -= *(*day_tab + 13 * leap + i);
    *pmonth = i;
    *pday = yearday;

    return 1;
}