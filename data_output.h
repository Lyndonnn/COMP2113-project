#ifndef data_output_H
#define data_output_H
struct Day {
	int fund;
	int support;
	int infection;
	double death;
	int potential;
	bool flag;
	Day *next;
};

void dataoutput(Day *&head);


#endif
