#include <iostream>
#include <string>
#include <fstream>
#include "background_input.h"
using namespace std;


// read from external file to display the background informations
void background_input() {
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "You are the leader of WHO, see whether you can beat the COVID. Here is the information" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	ifstream fin;
	fin.open("information.txt");
	if ( fin.fail() ) {
		cout << "Error in file opening!"
		     << endl;
	}
	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
	fin.close();

}