/*
* Gerardo Gonzalez
* Southern New Hampshire University : Programming Languages
* Project 2 : AirGead Banking
* Date : 2022 / 08 / 06
*/
#ifndef AIRGEAD_H_
#define AIRGEAD_H_
#include<iostream>
using namespace std;

class Banking				// Class labled banking 
{
public:
	Banking();				// constructer object 
	void displayInfo(float input1, float input2, float input3, float input4); // displayInfo function with pramaters as inputs.
	void dispStatWith();	// display function for statistics with monthly deposits 
	void dispStatWithout();	// display function for statistics without monthly deposits 


private:	// Private variables. 
	
	float inInvestAmt;
	float monthlyDep;
	float yrIntrest;
	float numYrs;
	float numMonths;
	float totAmt;
	float opAmt;
	float intrsAmt;
	float clAmt;
	bool testTrig;

};


#endif // !AIRGEAD_H_

