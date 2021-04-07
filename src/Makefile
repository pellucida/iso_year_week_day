
OBJ1	= iso_year_week_day.o
OBJ2	= iso_year_month_day_week_dow.o

CONVERT_WEEK_DOW_OBJ	= convert_iso_year_week_day.o 
CONVERT_MONTH_DAY_OBJ	= convert_iso_year_month_day.o

CONVERT_WEEK_DOW	= convert_iso_year_week_day
CONVERT_MONTH_DAY	= convert_iso_year_month_day

all:	$(CONVERT_WEEK_DOW) $(CONVERT_MONTH_DAY)

$(CONVERT_WEEK_DOW):	$(CONVERT_WEEK_DOW_OBJ) $(OBJ1)

$(CONVERT_MONTH_DAY):	$(CONVERT_MONTH_DAY_OBJ) $(OBJ1) $(OBJ2)

test:	$(CONVERT_WEEK_DOW) $(CONVERT_MONTH_DAY)	
	@echo -n "GOT:  "
	@./$(CONVERT_WEEK_DOW) -y 2020 -w 40 -d 4 -f %c
	@echo "WANT: Thu Oct  1 12:00:00 2020"
	@echo -n "GOT:  "
	@./$(CONVERT_MONTH_DAY) -y 2020 -m 10 -d 1
	@echo "WANT: 2020-W40-04"
	

clean:
	rm -f $(OBJ1) $(OBJ2) $(CONVERT_WEEK_DOW_OBJ) $(CONVERT_MONTH_DAY_OBJ)

distclean:	clean
	rm -f $(CONVERT_WEEK_DOW) $(CONVERT_MONTH_DAY)
	
convert_iso_year_week_day.o: convert_iso_year_week_day.c iso_year_week_day.h

iso_year_week_day.o: iso_year_week_day.c iso_year_week_day.h

iso_year_month_day_week_dow.o: iso_year_month_day_week_dow.c iso_year_week_day.h
