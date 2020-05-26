#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include "RepositoryMovie.h"

class Controller
{
private:
	RepositoryMovie repoM;

public:
	Controller();
	int Validate_int();
	int Validate_Year();
	
};
#endif
