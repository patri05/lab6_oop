#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Movie
{
private:
	string Title;
	string Genre;
	int Publishing_Year;
	int Likes;
	string Link;
	int ID;

public:
	Movie();
	void Set_Title(string title);
	void Set_Genre(string genre);
	void Set_Publishing_Year(int pub);
	void Set_Likes(int likes);
	void Set_Link(string link);
	void Set_ID(int id);
	void Add_Like();
	string Get_Title();
	string Get_Genre();
	int Get_Publishing_Year();
	int Get_Likes();
	string Get_Link();
	int Get_ID();
	
};
#endif