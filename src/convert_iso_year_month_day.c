/*
// @(#) convert_iso_year_month_day.c
*/
# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<time.h>

# include	"iso_year_week_day.h"

static	void	Usage(){
	fprintf (stdout, "Usage: convert_iso_year_month_day -y year -m month -d day\n");
	exit (EXIT_FAILURE);
}
int	main (int argc, char* argv[]){
	int	opt	= EOF;
	struct	tm	tm;
	int	year	= -1;
	int	month	= -1;
	int	day	= -1;
	char*	fmt	= "%Y-%m-%d";

	while ((opt = getopt (argc, argv, "y:m:d:h")) != EOF) {
		switch (opt) {
		case	'y':
			year	= atoi (optarg);
		break;
		case	'm':
			month	= atoi (optarg);
		break;
		case	'd':
			day	= atoi (optarg);
		break;
		default:
			Usage();
		break;
		}
	}
	if (year >= 1900 && month > 0 && month <= 12 && day > 0 && day <= 31) {
		int	week	= 0;
		int	dow	= 0;
		time_t	t	= iso_year_month_day_week_dow (year, month, day,&week, &dow);
		if (t != time_t_error) {
			printf ("%d-W%02d-%02d\n", year, week, dow);
		}
	}
	else	{
		Usage();
	}
	exit (EXIT_SUCCESS);
}
