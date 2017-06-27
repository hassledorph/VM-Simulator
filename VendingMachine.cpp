// Vending Machine Created by John Sjöberg
// V1.0
#include <iostream>
#include <string>
#include "VendingMachine.h"
#include "Consumer.h"


Consumer consumer;

//Default constructor
VendingMachine::VendingMachine()
{
	consumer.setBalance(0);
}
//Constructor with argument
VendingMachine::VendingMachine(float balance)
{
	consumer.setBalance(balance);
}

// Main machine function
void VendingMachine::runMachine()
{
	
	while (1)
	{
		cout << "Vending Machine" << endl;

		VendingMachine::listChoices();

		VendingMachine::makeSelection();
	}

}
//Function to run machine a specific amount of times. Used for testing purposes. 
void VendingMachine::runMachine(int times)
{
	int loops = 0;
	while (loops < times)
	{
		cout << "Vending Machine" << endl;

		VendingMachine::listChoices();

		VendingMachine::makeSelection();

		loops++;
	}
	cin.get();
}

void VendingMachine::listChoices()
{
	//Array for choises in Vending Machine. 
	string choices[] = { "1. Powerbar | 15sek","2. Cola | 12sek","3. Iced latte | 19.90sek","4. Water | 5sek","5. Add Money" ,"6. Exit" };

	cout << "List of goods: " << endl;
	
	// Loop through choices array. 
	for (int i = 0; i < (sizeof(choices) / sizeof(*choices)); i++)
	{
		cout << choices[i] << endl;
	}

}


void VendingMachine::makeSelection()
{
	int selection;
	float cost = 15;
	cout << "Your balance is: " << consumer.getBalance() << "sek" << endl;
	cout << "Please make a selection: " << endl;
	cin >> selection;

	//Error handling
	while (cin.fail())
	{
		cout << "Invalid selection! Try again!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Please make a selection: ";
		cin >> selection;
	}


	switch (selection) {

	case 1:
		handleSelection(15.0f);
		break;
	case 2:
		handleSelection(12.0f);
		break;
	case 3:
		handleSelection(19.90f);
		break;
	case 4:
		handleSelection(5.0f);
		break;
	case 5:
		float addMoney;
		cout << "With how much?" << endl;
		cin >> addMoney;
		if (addMoney > 0 && addMoney < INT_MAX)
		{
			consumer.increaseBalance(addMoney);
			cout << addMoney << " has been added to your account." << endl;
		}
		else
		{
			cout << "Thats not a valid amount." << endl;
		}
		break;
	case 6:
		cout << "Exiting..." << endl;
		exit(0);
	default:
		cout << "Invalid choise. Try Again" << endl;
	}

}

void VendingMachine::handleSelection(float cost)
{
		
	if (consumer.getBalance() >= cost)
	{
		consumer.lowerBalance(cost);
		cout << cost << "sek has been deducted from your account." << endl;
	}
	
	else
	{
		cout << "Sorry, but you don't have enough money!" << endl;
	}

}
