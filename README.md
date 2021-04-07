# iso_year_week_day
Short routine to convert ISO8601 year-week-day to time_t

Disk drive manufacturing dates seem to be ISO (year, week, day)
which isn't altogether obvious.

````
time_t  iso_year_week_day_tm (int year, int week, int day, struct tm* tm);
````
converts from ISO8601 year, week, day to time_t and returns the same
information in a <i>struct tm</i> object (if not NULL.)

````
time_t  iso_year_week_day (int year, int week, int day);
````
is a wrapper that passes such a NULL pointer to the previous function.

````
convert_iso_year_week_day -y year -w week -d day [-f strftime_template]
````
is a simple program that converts the ISO date to <b>+%Y-%m-%d</b> by default or
any valid date-time format that <i>strftime(3)</i> understands.

## Example
````
convert_iso_year_week_day -y 2020 -w 40 -d 4 -f '%c'
Thu Oct  1 12:00:00 2020
````
## Notes
Depends on the stdc library routine <i>mktime(3)</i>.
