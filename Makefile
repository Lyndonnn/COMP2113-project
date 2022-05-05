FLAGS = -pedantic-errors -std=c++11

data_output.o: data_output.cpp data_output.h
	g++ $(FLAGS) -c data_output.cpp
background_input.o: background_input.cpp background_input.h
	g++ $(FLAGS) -c background_input.cpp
covid_fighter.o: covid_fighter.cpp data_output.h background_input.h
	g++ $(FLAGS) -c covid_fighter.cpp
covid_fighter: covid_fighter.o background_input.o data_output.o
	g++ $(FLAGS) covid_fighter.o background_input.o data_output.o -o covid_fighter
clean:
	rm -f covid_fighter.o background_input.o data_output.o -o covid_fighter
