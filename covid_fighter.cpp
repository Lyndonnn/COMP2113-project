#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct Day {
  int fund;
  int support;
  int infection;
  int death;
  Day * next;
};

// print the status in the previous day
void printDay(Day * head) {
  cout << endl;
  cout << "******" << "Total funding (in $): " << head.fund << "******"<< endl;
  cout << "******" << "Support rate (in %): " << hend.support << "******"<< endl;
  cout << "******" << "Infection rate (in %): " << head.infection << "******"<< endl;
  cout << "******" << Death rate (in %): " << head.death " << ""******" << endl;
  cout << endl;
}

// add a new daily status
void addDay(Day * head, int fund, int support, int infection, int death) {
  Day * p = new Day;
  p -> fund = fund;
  p -> support = support;
  p -> infection = infection;
  p -> death = death;
  p -> next = head;
  head = p;
}

// display all the avalaible choices
// obtain the action chosen from the player
char actionMenu(int day) {
  char action;

  // print action menu
  cout << "********************************" << endl;
  cout << "************DAY " << setw(16) << setfill('*') << left << day << endl;
  cout << "********************************" << endl;
  // ++++++++++++++++ add choices here ++++++++++++++++++++++++

  cout << "Please choose your action: ";

  // read player's action
  cin >> action;
  cout << endl;

  return action;
}


// more functions to be considered...




int main() {
  Day * head = NULL;
  int day=0;
  int fund, support, infection, death;


  char action = actionMenu(day);
  while (fund > 0 && support > 0) {
    if (infection == 0 || death == 0) {
      // success

      break;
    }

    // update funding, support, infection, and death according to the action chosen
    switch (choice) {
      case '1':
      break;
    }








    day++; // add the day by 1
    char action = actionMenu(day);
  }

  return 0;
}
