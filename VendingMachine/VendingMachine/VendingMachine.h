// Vending Machine Created by John Sjöberg
// V1.0
#pragma once

using namespace std;

class VendingMachine
{
	private:
	//Functions
	void listChoices();

	void makeSelection();

	void handleSelection(float selection);

	public:
		//Constructors
		VendingMachine();

		VendingMachine(float balance);
		
		//Functions
		void runMachine();
		
		void runMachine(int times);

		
		

};