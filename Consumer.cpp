#include "Consumer.h"

//Sets balance for consumer.
void Consumer::setBalance(float balance)
{
	this->balance = balance;
}
//Gets balance for consumer
float Consumer::getBalance()
{
	return this->balance;
}

//Lowers balance by amount.
void Consumer::lowerBalance(float amount)
{
	this->balance -= amount;
}
//Increases balance by amount.
void Consumer::increaseBalance(float amount)
{
	this->balance += amount;
}