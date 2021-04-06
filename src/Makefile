
OBJ	= iso_year_week_day.o convert_iso_year_week_day.o

PROGRAM	= convert_iso_year_week_day

$(PROGRAM):	$(OBJ)

clean:
	rm -f $(OBJ)

distclean:	clean
	rm -f $(PROGRAM)
	
convert_iso_year_week_day.o: convert_iso_year_week_day.c iso_year_week_day.h

iso_year_week_day.o: iso_year_week_day.c iso_year_week_day.h
