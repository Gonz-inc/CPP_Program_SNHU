/*
* Gerardo Gonzalez
* Southern New Hampshire University : Programming Languages
* Project 2 : AirGead Banking
* Date : 2022 / 08 / 06
*/
#include"airGead.h" //calls in header file 
#include <iostream> 

using namespace std; 
	
	bool optionIn = true;
	char userIn5 = ' ';
void exitQueue() {
	cout << "\nTo exit press n or to Start over enter y: ";
	cin >> userIn5;

	if (userIn5 == 'n' || userIn5 == 'N') {
		optionIn = false;
	}
	else if (userIn5 == 'y' || userIn5 == 'Y') {
		optionIn = true;
	}
	cout << endl;
}
int main() {
float userin1 = 0;  // user Input 1
	float userin2 = 0;	// user Input 2
	float userin3 = 0;	// user Input 3
	float userin4 = 0;	// user Input 4

	Banking airGead;	// creates calls object for this project named airGead
	
	
	while (optionIn != false) {
		
		airGead.displayInfo(userin1, userin2, userin3, userin4); // passes user inputs to display Info fuction 
		airGead.dispStatWithout();		// Calls function 	
		cout << endl;					// prints with space seperations 
		airGead.dispStatWith();			// Calls funciton
		exitQueue();

	}
}

