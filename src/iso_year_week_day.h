/*
// @(#) iso_year_week_day.h
*/
# if !defined( ISO_YEAR_WEEK_DAY_H)
# define	ISO_YEAR_WEEK_DAY_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<time.h>

typedef	int	year_t;
typedef	int	month_t;
typedef	int	week_t;
typedef	int	day_t;
static	const	time_t	time_t_error	= (-1);

time_t	iso_year_begins (year_t year, struct tm* tp);

time_t	iso_year_week_day_tm (year_t year, week_t week, day_t day,
				 struct tm* tmp);

time_t	iso_year_week_day (year_t year, week_t week, day_t day);

time_t	iso_year_month_day_week_dow (year_t year, month_t month, day_t day,
					week_t* week, day_t* dow);
# endif
