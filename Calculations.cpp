/*
* Gerardo Gonzalez
* Southern New Hampshire University: Programming Languages 
* Project 2: AirGead Banking
* Date: 2022/08/06
*/
#include<iostream>
#include"airGead.h"
#include <iomanip>		
#include <string>	// used for controlling print format. 
#include <limits>

Banking::Banking() {	// sets all the float variables to zero
	inInvestAmt = 0;	// is the value for open amount
	monthlyDep = 0;		// Depositited amount
	yrIntrest = 0;		// annual intrest
	numYrs = 0;			// Number of years 
	numMonths = 0;		// Number of mounths 
	totAmt = 0;			// Total amount for calculations 
	opAmt = 0;			// open Amount 
	intrsAmt = 0;		// Interest Amount
	clAmt = 0;			// Closing amount.
}

void Banking::displayInfo(float input1,float input2, float input3, float input4) {	// class object for displaying info
	cout << "*****************************" << endl;	//Beginning of message 
	cout << "******** Data Input *********" << endl;	
	cout << "Initial investment Amount: " << endl;		
	cout << "Monthly Deposit: " << endl;				
	cout << "Annual Interest: " << endl;						
	cout << "Number of years: " << endl;				//End of message
	
	system("PAUSE");								// pauses operations until a key is pressed 

	cout << endl;
	cout << "*****************************" << endl;	//Beginning of message 											
	cout << "******** Data Input *********" << endl;
	cout << "Initial investment Amount: $";
													// checks if anythins in inputted while also seeing if its postivie integer repeated this for all 4 inputs.
	while (!(cin >> input1 && input1 > 0)) {		// input for first variable in message 
		if (!cin) {									
			cout << "Must be a number: ";
			cin.clear();
			cin.ignore(100000,'\n');
		}
		else {
			cout << "please enter postive number: ";
		}
	}
	cout << "Monthly Deposit: $";
	while (!(cin >> input2 && input2 > 0)) {		// input for first variable in message
		if (!cin) {									 
			cout << "Must be a number: ";
			cin.clear();
			cin.ignore(100000, '\n');
		}
		else {
			cout << "please enter postivie number: ";
		}
	}
		cout << "Annual Interest: %";
		while (!(cin >> input3 && input3 > 0)) {	// input for first variable in message 
			if (!cin) {									
				cout << "Must be a percentage: ";
				cin.clear();
				cin.ignore(100000, '\n');
			}
			else {
				cout << "please enter a postiive percentage: ";
			}
		}	

		cout << "Number of years: ";
		while (!(cin >> input4 && input4 > 0)) {		// input for first variable in message
			if (!cin) {									 
				cout << "Must be a number: ";
				cin.clear();
				cin.ignore(100000, '\n');
			}
			else {
				cout << "please enter postive number: ";
			}
		}									//fourth input
		cout << endl;
	
	system("PAUSE");								// press any key to continue 
	
	numMonths = input4 * 12;							// set the number of months 
	inInvestAmt = input1;								// sets initial investment amount
	monthlyDep = input2;								// sets the monthly deposit 
	yrIntrest = input3;									// annual interest
	numYrs = input4;									// number of years
	opAmt = input1;										// open amount (for calculations)
}

void Banking::dispStatWithout() {						// display function for balance and interest without monthly deposit
	float newInvAmt2 = 0;								// variable for this spesific function
	newInvAmt2 = inInvestAmt;							// set variable with the initial investment amount.
	
	cout << "\n   Balance and Intrest Without Additional Monthly Deposits" << endl;		// Print structure
	cout << "=============================================================" << endl;		
	cout << "  Year" << "\t   " << fixed << "  Year End Ballance";						// serves to format a table.
	cout << fixed << "\t   " << "Year End Earned Intrest" << endl;
	cout << "-------------------------------------------------------------" << endl;	// end of table strucure.
	
	for (int i = 0; i < numYrs; i++) {				// for loop for the number of years 
		totAmt = newInvAmt2 + 0;					// total amount without monthly deposit
		intrsAmt = totAmt * ((yrIntrest / 100));	// interest amount for every year
		clAmt = totAmt + intrsAmt;					// clost amount 
		newInvAmt2 = clAmt;							// sets closed amount for the next intrest amount calculation
		
		cout << setprecision(2) << "   " << (i + 1) << "\t\t" << fixed << "    $" << clAmt; // prints out the closed amount for every year
		cout << setprecision(2) << fixed << "\t\t\t    $" << intrsAmt << endl;				// prints the amount earned from interest
	}
	
	
}

void Banking::dispStatWith() {							 // Display function for balance and interest with monthly deposits
	float newInvAmt = 0;								 // variable for this function
	float yearEnd = 0;									 // second variable for yearly interest amount  
	newInvAmt =  inInvestAmt;							 // sets first variable with initial investment amount

	cout << "\n   Balance and Intrest With Additional Monthly Deposits" << endl;		// Beginning of table print out
	cout << "=============================================================" << endl;
	cout << "  Year" << "\t   " << fixed << "  Year End Ballance";
	cout << fixed << "\t   " << "Year End Earned Intrest" << endl;
	cout << "-------------------------------------------------------------" << endl;	// end of table print out.
	
	for (int i = 0; i < numYrs; i++) {				// for loop for number of years 
		yearEnd = 0;								// set the years intrest to the year 0
		
		for (int j = 0; j < 12; j++) {					    // for loop with months in a year.
			totAmt = newInvAmt + monthlyDep;			    // total amount but this time with monthly deposit
			intrsAmt = totAmt * ((yrIntrest / 100) / 12);   // interest amount for every month
			yearEnd = yearEnd + intrsAmt;					// interest amount for that number of year
			clAmt = totAmt + intrsAmt;						// closing amount 
			newInvAmt = clAmt;								// set the new investement amount with that of the closing amount
			
		}
		
		cout << setprecision(2) << "   " << (i + 1) << "\t\t" << fixed << "    $" << clAmt;		// Prints out the closing amount 
		cout << setprecision(2) << fixed << "\t\t\t    $" << yearEnd << endl;					// Prints the yearend amount
	}
}
