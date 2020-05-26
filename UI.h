#ifndef UI_H
#define UI_H

#include "RepositoryMovie.h"
#include "Movie.h"
#include "Controller.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>

using namespace std;

class UI
{
private:
	Controller Contr;
	RepositoryMovie Repo;
	bool csv, html;
public:
	UI();
	void Upload();
	void Choose_File_Type();
	void Show_All_Movies();
	void Show_Watchlist();
	void Show_Genre(string Genre);
	void Menu_main();
	void Menu_administrator();
	void Menu_User();
	void Submenu_User();
	void Create_Html();
	void Create_Csv();
};
#endif