/*
// @(#) iso_year_week_day.c - convert ISO8601 yr/wk/d to time_t
*/
# include	<time.h>

# include	"iso_year_week_day.h"

// year, week, day -> seconds since epoch (time_t) AND time_t -> struct tm
// On ERROR returns (-1)

time_t	iso_year_week_day_tm (year_t year, month_t week, day_t day,
	struct tm* tp)
{

	struct tm tm = { // Noon 4-Jan-Year
			.tm_year	= year - 1900,
			.tm_mon		= 0,
			.tm_mday	= 4,
			.tm_hour	= 12
			};
	time_t	result	= mktime (&tm);

	if (result != time_t_error) {
		day_t	day_offset	= tm.tm_wday;//day-of-week of this jan 4
		
		// Calc previous Monday
		day_t	from_monday	= day_offset;
		if (day_offset==0) 	// mod 7 subtract 1
			from_monday	+= 6;
		else
			from_monday	+= -1;

		// This looks wrong but mktime normalizes dates
		// mktime(3)...
		// "if structure members are outside their valid interval,
		// "they will be normalized (so that, for example, 40 October
		// "is changed  into  9  November)

		tm.tm_mday += (day - 1) + (week - 1) * 7 - from_monday;
		result	= mktime (&tm);
		if (result != time_t_error && tp) {
			*tp	= tm;
		}
	}
	return	result;
}
time_t	iso_year_week_day (year_t year, month_t week, day_t day) {
	return	iso_year_week_day_tm (year, week, day, 0);
}
