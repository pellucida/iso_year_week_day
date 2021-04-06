
OBJ	= iso_year_week_day.o convert_iso_year_week_day.o

PROGRAM	= convert_iso_year_week_day

$(PROGRAM):	$(OBJ)

test:	$(PROGRAM)	
	@echo -n "GOT:  "
	@./$(PROGRAM) -y 2020 -w 40 -d 4 -f %c
	@echo "WANT: Thu Oct  1 12:00:00 2020"

clean:
	rm -f $(OBJ)

distclean:	clean
	rm -f $(PROGRAM)
	
convert_iso_year_week_day.o: convert_iso_year_week_day.c iso_year_week_day.h

iso_year_week_day.o: iso_year_week_day.c iso_year_week_day.h
