#include "Controller.h"
#include "RepositoryMovie.h"
#include "Movie.h"
#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>

Controller::Controller() {}

int Controller::Validate_int()
{

	//functie de verificare int

	int num;

	bool aux = true;
	cin.exceptions(std::istream::failbit);

	do {
		try {
			cin >> num;
			aux = true;
		}
		catch (std::ios_base::failure& fail) {
			aux = false;
			cout << "PLease insert a valid number:" << endl;
			cin.clear();
			std::string tmp;
			getline(cin, tmp);
		}
	} while (aux == false);

	return num;
}


int Controller::Validate_Year()
{

	//functie de verificare an
	
	int num = 0;
	
	bool aux = true;
	cin.exceptions(std::istream::failbit);

	do {
		try {
			cin >> num;
			aux = true;
		}
		catch (std::ios_base::failure& fail) {
			aux = false;
			cout << "PLease insert a valid number:" << endl;
			cin.clear();
			std::string tmp;
			getline(cin, tmp);
		}
	} while (aux == false);

	if (!(num >= 1878 && num <= 2020))
	{
		cout << "Error, enter a number between 1878 and 2019:";
		Validate_Year();
	}

	return num;
}


