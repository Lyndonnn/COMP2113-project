#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "background_input.h"
#include "data_output.h"

using namespace std;

struct Day {
	int fund;
	int support;
	int infection;
	double death;
	int potential;
	bool flag;
	Day *next;
};


// print the status in the previous day
void printDay(Day &head) {
	cout << endl;
	cout << "******" << " Total funding (in $billion): " << setw(3) << head.fund << " ******" << endl;
	cout << "******" << " Support rate (in %): " << setw(11) << head.support << " ******" << endl;
	cout << "******" << " Infection rate (in %): " << setw(9) << head.infection << " ******" << endl;
	cout << "******" << " Death rate (in %): " << setw(13) << head.death  << " ******" << endl;
	cout << endl;
}

// add a new daily status to the tail of the linked list
void addDay(Day *&head, Day *&tail, Day &info) {
	Day *p = new Day;
	p -> fund = info.fund;
	p -> support = info.support;
	p -> infection = info.infection;
	p -> death = info.death;
	p -> potential = info.potential;
	p -> flag = info.flag;
	p -> next = NULL;
	if (head == NULL) {
		head = p;
		tail = p;
	} else {
		tail->next = p;
		tail = p;
	}
}

// display all three actions
// obtain the action chosen from the player
int actionMenu(int day) {
	int action;
	// print action menu
	cout << "********************************" << endl;
	cout << "************ DAY " << setw(2) << day << " ************" << endl;
	cout << "********************************" << endl;
	cout << "Please choose your action: " << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "Enter 1 --------> Measures" << endl; // select the measure for the current day
	cout << "Enter 2 --------> Show Status" << endl;
	cout << "Enter 3 --------> Show Background Information" << endl;
	cout << "Enter 0 --------> Quit (your current status will not be recorded)" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	// read player's action
	cin >> action;

	return action;
}

// generate a random number from 1 to 7
int randomNumber() {
	int a;
	a = rand() % 7 + 1;
	return a;
}

// print all seven measures that can be taken
// obtain the measure chosen by the player
int chooseAction(Day &info) {
	int a, b;
	// print the measures
	cout << "Please choose the action you want to take" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "Enter 1 ---------> Tightening quarantine policy" << endl;
	cout << "Enter 2 ---------> Distribute free disinfection materials" << endl;
	cout << "Enter 3 ---------> Organize medical teams for rescue" << endl;
	cout << "Enter 4 ---------> Develop up-to-date vaccine" << endl;
	cout << "Enter 5 ---------> Spread fake news to exaggerate your contributions" << endl;
	cout << "Enter 6 ---------> Raise donations worldwide" << endl;
	cout << "Enter 7 ---------> Provide additional assistance to poor areas" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cin >> a;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	// update funding, support, infection rate, and death rate based on the measure
	switch (a) {
		case 1:
			cout << "Enter 1 ---> Normal quarantine (accept flight, ship but need 14 days quarantine)" << endl;
			cout << "Enter 2 ---> Absolute quarantine (no flight, ship, cars enter the country) " << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			cin >> b;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			if (b == 1) {
				info.support -= 10;
				info.fund -= 10;
				info.infection -= 5;
				if (info.infection < 0) {
					info.infection = 0;
				}
				if (info.support < 0) {
					info.support = 0;
				}
				return 10;
			}
			if (b == 2) {
				info.support -= 30;
				info.fund -= 20;
				info.infection -= 20;
				if (info.infection < 0) {
					info.infection = 0;
				}
				if (info.support < 0) {
					info.support = 0;
				}
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
			if (info.infection < 0) {
				info.infection = 0;
			}
			if (info.death < 0) {
				info.death = 0;
			}
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
			if (info.death < 0) {
				info.death = 0;
			}
			return 3;
			break;
		case 4:
			info.fund -= 40;
			info.support += 10;
			info.infection -= 20;
			info.death -= 0.1;
			if (info.infection < 0) {
				info.infection = 0;
			}
			if (info.death < 0) {
				info.death = 0;
			}
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
			if (info.infection > 100) {
				info.infection = 100;
			}
			return 5;
			break;
		case 6:
			info.fund += 20;
			info.support -= 20;
			if (info.support < 0) {
				info.support = 0;
			}
			return 6;
			break;
		case 7:
			info.support += 10;
			info.fund -= 20;
			info.death -= 0.3;
			if (info.death < 0) {
				info.death = 0;
			}
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
void randomEvent(Day &info) {
	int ran, temp;
	// generate a random event
	ran = randomNumber();
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
	// read player's chosen measure
	temp = chooseAction(info);
	// further adjustments on funding, support, infection rate, and death rate
	// in general, acting in response to the breaking news (if triggered) results in more favorable situation
	switch (ran) {
		case 1:
			if (temp == 10 || temp == 11) {
				info.infection -= 5;
				if (info.infection < 0) {
					info.infection = 0;
				}
				cout << "Long periods of quarantine have discouraged people from travelling" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			} else {
				info.infection += 20;
				if (info.infection > 100) {
					info.infection = 100;
				}
				cout << "The mass movement led to the outbreak of epidemic" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			}
			break;
		case 2:
			if (temp == 3 || temp == 7 || temp == 2) {
				info.death -= 0.1;
				info.infection -= 10;
				if (info.death < 0) {
					info.death = 0;
				}
				if (info.infection < 0) {
					info.infection = 0;
				}

				cout << "Medical care in poor areas has been improved" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			} else {
				info.death += 1;
				info.infection += 10;
				if (info.infection > 100) {
					info.infection = 100;
				}
				cout << "Both mortality and infection rates have increased dramatically due to cluster of cases" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			}
			break;
		case 3:
			if (temp == 4) {
				info.death -= 0.2;
				info.infection -= 10;
				if (info.death < 0) {
					info.death = 0;
				}
				if (info.infection < 0) {
					info.infection = 0;
				}
				cout << "The newly developed vaccine is very effective" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			} else {
				info.infection += 10;
				info.death += 1;
				if (info.infection > 100) {
					info.infection = 100;
				}
				cout << "The mutated virus cannot be dealt with by existing medical measures" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			}
			break;
		case 4:
			if (temp == 2 || temp == 7) {
				info.infection -= 10;
				info.death -= 0.1;
				if (info.infection < 0) {
					info.infection = 0;
				}
				if (info.death < 0) {
					info.death = 0;
				}
				cout << "Free supplies have helped the poor areas a lot" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			} else {
				info.death += 1;
				info.infection += 20;
				if (info.infection > 100) {
					info.infection = 100;
				}
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



int main() {
	Day *head = NULL;
	Day *tail = NULL;
	int day = 0;
	Day value;
	value.fund = 100;
	value.support = 100;
	value.infection = 50;
	value.death = 1;
	value.potential = 0;
	value.flag = false;
	addDay(head, tail, value); // add initial status to the linked list
	
	srand(time(NULL));
	while (day < 100) {
		int action = actionMenu(day);

		switch (action) {
			case 1: // if the player want to take a measure for that day
				cout << "----------------------------------------------------------------------------------------------" << endl;
				randomEvent(value);
				addDay(head, tail, value); // add daily infomation to the linked list
				cout << "----------------------------------------------------------------------------------------------" << endl;
				day++;
				break;
			case 2: // if the player want to know the current status
				cout << "----------------------------------------------------------------------------------------------" << endl;
				printDay(value);
				cout << "----------------------------------------------------------------------------------------------" << endl;
				break;
			case 3: // if the player want to search for background information
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
				day++;


		}
		if (day >= 100) {
			cout << "----------------------------------------------------------------------------------------------" << endl;
			cout << "You fail to beat the COVID as you spend too much time." << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
		}
		// success condition
		if (value.infection <= 0 || value.death <= 0) {
			cout << "YOU HAVE BEAT THE COVID !!!" << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			break;
		}
		// lose condition 1
		if (value.support <= 0 || value.infection >= 100 || value.fund <= 0 || value.death >= 5) {
			cout << "----------------------------------------------------------------------------------------------" << endl;
			cout << "You Fail To Beat The COVID" << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			break;
		}
		// lose condition 2: too much fake news produced
		if (value.potential >= 100) {
			cout << "You get caught spreading fake news, people lose trust in you" << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl;
			value.fund -= 100;
			value.support -= 100;
			break;
		}
		if (value.flag == true) {
			value.potential += 20;

		}
	}

	dataoutput(*&head);

	return 0;
}

