#ifndef A_H_
#define A_H_

struct Day {
	int fund;
	int support;
	int infection;
	double death;
	int potential;
	bool flag;
	Day *next;
};

#endif