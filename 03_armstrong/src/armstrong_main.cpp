#include <iostream>
#include <sstream>
#include <math.h>

bool isArmstrongNumber(int number)
{
	// TODO: implement some functionality to see if this number is an armstrong number

	int i = 0;
	int suma = 0;
	int cifra = 0;
	int number_copy = number; // fac o copie pentru a pastra number intact
	int number_copy1 = number;

	while (number_copy > 0)
	{
		number_copy /= 10;
		i++; // ca sa vedem puterea
	}

	while (number_copy1 > 0)
	{
		cifra = number_copy1 % 10; // ca sa luam ultima cifra din numar

		suma = suma + pow(cifra, i); // calcult de verificat pt armstrong

		number_copy1 /= 10;
	}

	if (number == suma) // verifica daca numarul initial este egal cu suma calculata
	{
		return true;
	}
	else
	{
		return false;
	}
}

void printIsArmstrong(int number)
{
	if (isArmstrongNumber(number))
	{
		std::cout << "Armstrong" << std::endl;
	}
	else
	{
		std::cout << "NOT Armstrong" << std::endl;
	}
}

int main(int argc, char* argv[])
{
	//		  ./03_armstrong.exe 153		=> Output: Armstrong
	//		  ./03_armstrong.exe 154		=> Output: NOT Armstrong

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		std::cout << "No program arguments found." << std::endl;
		return 1;
	}

	int readNumber = 0;

	// Get the first argument
	std::string argumentAsString = argv[1];


	// TODO: read number / cast to integer
	const char* argumentAsCharArray = argumentAsString.c_str();

	int nr = std::stoi(argumentAsString); // converteste din string in int

	printIsArmstrong(nr);
	//printIsArmstrong(readNumber);
	return 0;
}
