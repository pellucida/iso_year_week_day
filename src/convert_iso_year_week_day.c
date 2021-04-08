/*
// @(#) convert_iso_year_week_day.c
*/
# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<time.h>

# include	"iso_year_week_day.h"

static	void	Usage(){
	fprintf (stdout, "Usage: convert_iso_year_week_day -y year -w week -d day [-h hour [-m minutes -s [seconds]]] [-f fmt]\n");
	exit (EXIT_FAILURE);
}
int	main (int argc, char* argv[]){
	int	opt	= EOF;
	struct	tm	tm;
	int	year	= -1;
	int	week	= -1;
	int	day	= -1;
	int	hour	= 0;
	int	min	= 0;
	int	sec	= 0;
	char*	fmt	= "%Y-%m-%d";

	while ((opt = getopt (argc, argv, "y:w:d:h:m:s:f:h")) != EOF) {
		switch (opt) {
		case	'y':
			year	= atoi (optarg);
		break;
		case	'w':
			week	= atoi (optarg);
		break;
		case	'd':
			day	= atoi (optarg);
		break;
		case	'h':
			hour	= atoi (optarg);
		break;
		case	'm':
			min	= atoi (optarg);
		break;
		case	's':
			sec	= atoi (optarg);
		break;
		case	'f':
			fmt	= optarg;
		break;
		default:
			Usage();
		break;
		}
	}
	if (year >= 1900 && week > 0 && week <= 53 && day > 0 && day <= 7) {
		time_t	t	= iso_year_week_day_hour_min_sec_tm (year, week, day, hour, min, sec, &tm);
		if (t != time_t_error) {
			char	buf[BUFSIZ];
			strftime (buf, sizeof(buf), fmt, &tm);
			printf ("%s\n", buf);
		}
	}
	else	{
		Usage();
	}
	exit (EXIT_SUCCESS);
}
