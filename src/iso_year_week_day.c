/*
//
*/
# include	<time.h>

# include	"iso_year_week_day.h"

time_t	iso_year_week_day_tm (year_t year, month_t week, day_t day, struct tm* tmp) {

	struct tm tm = { // Noon 4-Jan-Year
			.tm_year	= year - 1900,
			.tm_mon		= 0,
			.tm_mday	= 4,
			.tm_hour	= 12
			};
	time_t	result	= mktime (&tm);

	if (result != time_t_error) {
		day_t	day_offset	= tm.tm_wday;  // day-of-week 4/1/YY 
		
		day_t	from_monday	= day_offset;
		if (day_offset==0) 
			from_monday	+= 6;
		else
			from_monday	+= -1;

		tm.tm_mday += (day - 1) + (week - 1) * 7 - from_monday;
		result	= mktime (&tm);
		if (result != time_t_error && tmp) {
			*tmp	= tm;
		}
	}
	return	result;
}
time_t	iso_year_week_day (year_t year, month_t week, day_t day) {
	return	iso_year_week_day_tm (year, week, day, 0);
}
