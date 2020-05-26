#include <iostream>
#include <Windows.h>
#include "Controller.h"
#include "Movie.h"
#include "Tests.h"
#include "RepositoryMovie.h"
#include "UI.h"

using namespace std;

int main()
{
	Tests t; t.Test();
	UI ui;ui.Menu_main();

	system("pause");
	
	return 0;
}