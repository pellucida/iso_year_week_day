/*
// @(#) iso_year_week_day.c - convert ISO8601 yr/wk/d to time_t
*/
# include	<time.h>

# include	"iso_year_week_day.h"


// The first ISO week (01) is the first week in a calendar year to contain
// a Thursday. This is equivalent to finding the first week containing Jan 04.
// ie If the first Thu is Jan 01 => Sun is Jan 04 
//			  Jan 07 => Mon is Jan 04
// The first day of an ISO week is Monday.

time_t	iso_year_begins (year_t year, struct tm* tp) {
	struct	tm	tm	= { .tm_year = year - 1900,
				.tm_mon = 0, .tm_mday = 4, .tm_hour = 0,
				.tm_isdst = 0, }; 
	
	time_t	result	= mktime (&tm);
	if (result != time_t_error) {
		int	dow	= tm.tm_wday;
		if (dow==0)
			dow	= 7;
		if (dow <= 4) {
			tm.tm_mday	= 5 - dow;  // 4th - dow + 1
		}
		else 	{
			tm.tm_mday	= 36 - dow; // 4th - dow + 31 + 1
			tm.tm_mon	= 11;	          // Dec
			tm.tm_year	= tm.tm_year - 1; // Prev year
		}
		result	= mktime (&tm);
		if (result != time_t_error && tp) {
			*tp	= tm;
		}
	}
	return	result;
}

// year, week, day -> seconds since epoch (time_t) AND time_t -> struct tm
// On ERROR returns (-1)


time_t	iso_year_week_day_hour_min_sec_tm (year_t year, week_t week, day_t day,
	hour_t hour, minute_t min, sec_t sec,
	struct tm* tp)
{
	struct	tm	tm;
	time_t	result	= iso_year_begins (year, &tm);
	if (result != time_t_error) {

		// This looks wrong but mktime normalizes dates
		// mktime(3)...
		// "if structure members are outside their valid interval,
		// "they will be normalized (so that, for example, 40 October
		// "is changed  into  9  November)

		tm.tm_mday	+= (week-1)*7 + (day-1);
		tm.tm_hour	= hour;
		tm.tm_min	= min;
		tm.tm_sec	= sec;
		tm.tm_isdst	= 0;
		result		= mktime (&tm);
		if (result != time_t_error && tp) {
			*tp	= tm;
		}
	}
	return	result;
}
time_t	iso_year_week_day_tm (year_t year, week_t week, day_t day,
	struct tm* tp)
{
	return	iso_year_week_day_hour_min_sec_tm (year, week, day,
			0, 0, 0, tp);
}	
time_t	iso_year_week_day_hour_min_sec (year_t year, week_t week, day_t day,
		hour_t hour, minute_t min, sec_t sec)
{
	return	iso_year_week_day_hour_min_sec_tm (year, week, day,
			hour, min, sec, 0);
}
time_t	iso_year_week_day (year_t year, week_t week, day_t day) {
	return	iso_year_week_day_tm (year, week, day, 0);
}
