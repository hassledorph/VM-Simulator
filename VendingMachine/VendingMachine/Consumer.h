// Vending Machine Created by John Sjöberg
// V1.0
#pragma once

class Consumer{

private:
	float balance;


public:

	void setBalance(float balance);

	float getBalance();

	void lowerBalance(float amount);

	void increaseBalance(float amount);

};