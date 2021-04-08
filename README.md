# iso_year_week_day
Short routine to convert ISO-8601 year-week-day to time_t

For detail of ISO-8601 see [https://en.wikipedia.org/wiki/ISO_8601](https://en.wikipedia.org/wiki/ISO_8601)

Disk drive manufacturing dates seem to be ISO (year, week, day) which isn't altogether obvious.

````
time_t  iso_year_week_day_tm (int year, int week, int day, struct tm* tm);
````
converts from ISO-8601 year, week, day to time_t and returns the same
information in a *struct tm* object (if not NULL.)

````
time_t  iso_year_week_day (int year, int week, int day);
````
is a wrapper that passes such a NULL pointer to the previous function.

````
time_t	iso_year_begins (int year, struct tm* tm);
````
calculates the first day (Monday) of the first ISO week of *year* returning time_t of noon on that day and in *tm* if supplied.

````
time_t  iso_year_month_day_week_dow (year_t year, month_t month, day_t day,
                                        week_t* week, day_t* dow);
````
calculates the ISO week and week day (dow) of a calender date (year, month, day) and also returns the number of seconds between the beginning of the ISO year and the date.


````
convert_iso_year_week_day -y year -w week -d day [-f strftime_template]
````
is a simple program that converts the ISO date to `+%Y-%m-%d` by default or any valid date-time format that _strftime(3)_ understands.

````
convert_iso_year_month_day -y year -m month -d day
````
prints the corresponding ISO year, week number and day.

### Examples
````
convert_iso_year_week_day -y 2020 -w 40 -d 4 -f '%c'
Thu Oct  1 12:00:00 2020

convert_iso_year_month_day -y 2020 -m 10 -d 1
2020-W40-04
````
### Notes
Depends on the stdc library routine *mktime(3)*.
