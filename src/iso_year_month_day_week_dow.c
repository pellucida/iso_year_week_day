/*
// @(#) iso_year_month_day_week_dow.c
*/

# include	<time.h>

# include	"iso_year_week_day.h"

// calculate the ISO week number and day number of a year-month-day.

time_t	iso_year_month_day_hour_min_sec_week_dow (year_t year, month_t month,
		day_t day, hour_t hour, minute_t min, sec_t sec,
		week_t* week, day_t* dow)
{
	time_t	result	= time_t_error;
	struct	tm	tm	= { .tm_year = year - 1900,
			.tm_mon = month - 1, .tm_mday = day,
			.tm_hour = hour, .tm_min = min, .tm_sec = sec,
			.tm_isdst = 0, };
	time_t	when	= mktime (&tm);
	if (when != time_t_error) {
		time_t	origin	= iso_year_begins (year, 0);
		if (origin != time_t_error) {
			result	= when - origin;		// diff seconds
			week_t	nweeks	= result/(7*24*60*60);	// sec-per-week
			*week	= nweeks + 1;
			*dow	= tm.tm_wday;
		}
	}
	return	result;
}
time_t	iso_year_month_day_week_dow (year_t year, month_t month, day_t day,
					week_t* week, day_t* dow)
{
	return	iso_year_month_day_hour_min_sec_week_dow (year, month, day, 0,0,0, week, dow);
}
