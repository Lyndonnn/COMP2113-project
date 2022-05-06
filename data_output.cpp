#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include "data_output.h"
//#include "covid.h"
using namespace std;

// output daily information to file
void dataoutput(Day *&head) {

	ofstream fout;
	fout.open("dailyInfo.txt");

	if (fout.fail()) {
		cout << "Error in file opening!" << endl;
		exit(1);
	}


	int count = 0;
	Day *traverse = head;
	// print column names
	fout << "Day" << "     " << "Funding" << "     " << "Support Rate"
	     << "     " << "Infection Rate" << "     " << "Death Rate" << endl;
	// print daily information sequentially
	while (traverse->next != NULL) {
		fout << setw(3) << count << setw(12) << traverse->fund << setw(17) <<
		traverse->support << setw(19) << traverse->infection << setw(15) <<
		traverse->death << endl;
		count++;
		traverse = traverse->next;
	}
	fout << setw(3) << count << setw(12) << traverse->fund << setw(17) <<
	traverse->support << setw(19) << traverse->infection << setw(15) <<
	traverse->death << endl;
	fout.close();
}
