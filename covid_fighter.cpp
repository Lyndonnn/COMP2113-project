#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>

#include "2.h"
using namespace std;



// print the status in the previous day
void printDay(Day &head) {
	cout << endl;
	cout << "******" << "Total funding (in $): " << head.fund << "******" << endl;
	cout << "******" << "Support rate (in %): " << head.support << "******" << endl;
	cout << "******" << "Infection rate (in %): " << head.infection << "******" << endl;
	cout << "******" << "Death rate (in %): " << head.death  << "******" << endl;
	cout << endl;
}

// add a new daily status
void addDay(Day *head, int fund, int support, int infection, int death) {
	Day *p = new Day;
	p -> fund = fund;
	p -> support = support;
	p -> infection = infection;
	p -> death = death;
	p -> next = head;
	head = p;
}

// display all the avalaible choices
// obtain the action chosen from the player
int actionMenu(int day) {
	int action;
	// print action menu
	cout << "********************************" << endl;
	cout << "************DAY " << setw(16) << setfill('*') << left << day << endl;
	cout << "********************************" << endl;
	// ++++++++++++++++ add choices here ++++++++++++++++++++++++
	cout << "Please choose your action: " << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "Enter 1 --------> Measures" << endl;
	cout << "Enter 2 --------> Show Status" << endl;
	cout << "Enter 3 --------> Show Background Information" << endl;
	cout << "Enter 0 --------> Quit (your current status will not be recorded)" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	// read player's action
	cin >> action;

	return action;
}

// generate a random number
int random() {
	int a;
	srand((unsigned)time(NULL));
	a = rand() % 7 + 1;
	return  a;
}

int chooseaction(Day &info) {
	int a, b;
	cout << "Please choose the action you want to take" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "Enter 1 ---------> Tightening quarantine policy" << endl;
	cout << "Enter 2 ---------> Distribute free disinfection materials" << endl;
	cout << "Enter 3 ---------> Organize medical teams for rescue" << endl;
	cout << "Enter 4 ---------> Develop up-to-date vaccine" << endl;
	cout << "Enter 5 ---------> Spread fake news to exaggerate your contributions" << endl;
	cout << "Enter 6 ---------> Raise donations worldwide" << endl;
	cout << "Enter 7 ---------> Provide additional assistance will be given to poor areas" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cin >> a;
	switch (a) {
		case 1:
			cout << "Enter 1 ---> Normal quarantine (accept flight, ship but need 14 days quarantine)" << endl;
			cout << "Enter 2 ---> Absolute quarantine (no flight, ship, cars enter the country) " << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			cin >> b;
			if (b == 1) {
				info.support -= 10;
				info.fund -= 10;
				info.infection -= 5;
				return 10;
			}
			if (b == 2) {
				info.support -= 30;
				info.fund -= 20;
				info.infection -= 20;
				return 11;
			} else {
				cout << "Operation invalid, you waste one day" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			}
			break;
		case 2:
			info.support += 10;
			info.fund -= 20;
			info.infection -= 10;
			info.death -= 0.1;
			if (info.support > 100) {
				info.support = 100;
			}
			return 2;
			break;
		case 3:
			info.support += 10;
			info.fund -= 20;
			info.death -= 0.3;
			if (info.support > 100) {
				info.support = 100;
			}
			return 3;
			break;
		case 4:
			info.fund -= 40;
			info.support += 10;
			info.infection -= 20;
			info.death -= 0.1;
			if (info.support > 100) {
				info.support = 100;
			}
			return 4;
			break;
		case 5:
			info.fund += 20;
			info.support += 10;
			info.infection += 10;
			if (info.support > 100) {
				info.support = 100;
			}
			return 5;
			break;
		case 6:
			info.fund += 20;
			info.support -= 20;
			return 6;
			break;
		case 7:
			info.support += 10;
			info.fund -= 20;
			info.death -= 0.3;
			if (info.support > 100) {
				info.support = 100;
			}
			return 7;
			break;
		default:
			cout << "Invalid operation, you waste a day" << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;

	}
	return 0;
}

// generate a random event
void randomevent(Day &info) {
	int ran, temp;
	ran = random();
	switch (ran) {
		case 1:
			cout << "Breaking News: The holiday is coming and people are eager to travel." << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			break;
		case 2:
			cout << "Breaking News: Clusters of cases have emerged in some poor areas." << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			break;
		case 3:
			cout << "Breaking News: The virus mutated again." << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			break;
		case 4:
			cout << "Breaking News: Some poor countries can no longer afford the high cost of epidemic prevention." << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			break;
		case 5:
			cout << "Breaking News: Prices are rising and epidemic prevention spending is exceeding the budget." << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			break;
		default:
			cout << "News: The epidemic prevention work is progressing step by step." << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
	}
	temp = chooseaction(info);
	switch (ran) {
		case 1:
			if (temp == 10 || temp == 11) {
				info.infection -= 5;
				cout << "Long periods of quarantine have discouraged people from travelling" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			} else {
				info.infection += 20;
				cout << "The mass movement led to the outbreak of epidemic" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			}
			break;
		case 2:
			if (temp == 3 || temp == 7) {
				info.death -= 0.1;
				info.infection -= 10;
				cout << "Medical care in poor areas has been improved" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			} else {
				info.death += 1;
				info.infection += 10;
				cout << "Both mortality and infection rates have increased dramatically due to cluster of cases" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			}
			break;
		case 3:
			if (temp == 4) {
				info.death -= 0.2;
				info.infection -= 10;
				cout << "The newly developed vaccine is very effective" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			} else {
				info.infection += 10;
				info.death += 1;
				cout << "The mutated virus cannot be dealt with by existing medical measures" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			}
			break;
		case 4:
			if (temp == 2) {
				info.infection -= 10;
				info.death -= 0.1;
				cout << "Free supplies have helped the poor areas a lot" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			} else {
				info.death += 1;
				info.infection += 20;
				cout << "Health systems in some poor countries are about to collapse" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			}
			break;
		case 5:
			if (temp == 6) {
				info.fund += 10;
				cout << "The donation was supported by many countries" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			} else {
				info.fund -= 20;
				cout << "The budget of the organization is increasingly tight" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			}
	}
	if (temp == 5) {
		info.potential += 20;
		info.flag = true;

	}

}

void background() {
	cout << "You are the leader of WHO, see whether you can beat the COVID" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
}

// more functions to be considered...
int main() {
	//Day *head = NULL;

	int day = 0;
	int counter = 0;
	int count = 0;
	int check[100];
// basic information
	Day value;
	value.fund = 100;
	value.support = 100;
	value.infection = 50;
	value.death = 1;
	value.potential = 0;
	value.flag = false;
	//int action = actionMenu(day);
	while (day < 100) {
		int action = actionMenu(day);
		if (value.infection <= 0 || value.death <= 0) {
			// success
			//cout << value.death << value.infection << endl;
			cout << "YOU HAVE BEAT THE COVID !!!" << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			exit(1);
			break;
		}
		if (value.support <= 0 || value.infection >= 100 || value.fund <= 0 || value.death >= 5) {
			// lose
			cout << "You Fail To Beat The COVID" << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			exit(1);
		}

		// update funding, support, infection, and death according to the action chosen
		switch (action) {
			case 1:
				cout << "----------------------------------------------------------------------------------------------" << endl;
				randomevent(value);
				cout << "----------------------------------------------------------------------------------------------" << endl;
				break;
			case 2:
				cout << "----------------------------------------------------------------------------------------------" << endl;
				printDay(value);
				cout << "----------------------------------------------------------------------------------------------" << endl;
				break;
			case 3:
				cout << "----------------------------------------------------------------------------------------------" << endl;
				background();
				cout << "----------------------------------------------------------------------------------------------" << endl;
				break;
			case 0:
				exit(1);
			default:
				cout << "You entered a wrong action" << endl;
				cout << "You've wasted a day" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;


		}
		if (value.potential >= 100) {
			cout << "You get caught spreading fake news, people lose trust in you" << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			value.fund -= 100;
			value.support -= 100;
		}
		if (value.flag == true) {
			value.potential += 20;

		}
		day++; // add the day by 1
		//action = actionMenu(day);

	}
	return 0;
}
